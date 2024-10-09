#include<translate_command/translate_command.h>
#include <locale>
#include <codecvt>
atomizationCmd_translate::AtomCmdTranslate::AtomCmdTranslate(std::string _type) {
	l_type = _type;
	//addlanguage("test");
	set_config();

	options.beam_size = 5;               
	options.length_penalty = 1.0; 
							
	options.max_decoding_length = 500;

	if ("zhen" == l_type) {
		target_prefix.push_back({ { "__en__" } });
	}
	else if ("enzh" == l_type) {
		target_prefix.push_back({ { "zh_CN" } });
	}

	if (_type == "zhen") {
		languages.processor = v_languages.at(0).processor;
		languages.resprocessor = v_languages.at(0).resprocessor;
		languages.Translator = v_languages.at(0).Translator;
	}
	else if (_type == "enzh") {
		languages.processor = v_languages.at(1).processor;
		languages.resprocessor = v_languages.at(1).resprocessor;
		languages.Translator = v_languages.at(1).Translator;
	}
	else {
		languages.processor = {};
		languages.resprocessor = {};
		languages.Translator = {};
	}

	const auto status = processor.Load(languages.processor);//("D:/model/opus-2020-07-17zhen/source.spm");
	if (!status.ok()) {
		std::cerr << status.ToString() << std::endl;
		// error
	}

	const auto resstatus = resprocessor.Load(languages.resprocessor);//("D:/model/opus-2020-07-17enzh/source.spm");
	if (!resstatus.ok()) {
		std::cerr << resstatus.ToString() << std::endl;
		// error
	}

	translator = new ctranslate2::Translator(languages.Translator/*"D:/model/zhen_ctranslate2"*/, ctranslate2::Device::CPU);






}

void atomizationCmd_translate::AtomCmdTranslate::translation(std::string _input) {


	StrPrse strpres(std::move(_input), std::move(l_type));

	std::vector<std::string> vout{};
	for (auto i : strpres.strslice()) {
		std::cout << "push_back:" << boost::locale::conv::between(i, "GBK", "UTF-8") << std::endl;
		vout.push_back(translationSentences(i));
	}

	output(std::move(vout));

}


void atomizationCmd_translate::AtomCmdTranslate::output(std::vector<std::string>&& _output) {
	for (auto& text : _output) {
		boost::algorithm::replace_all(text, "▁", " ");
		std::cout  << boost::locale::conv::between(text, "GBK", "UTF-8") << std::endl;
	}

}


std::string atomizationCmd_translate::AtomCmdTranslate::translationSentences(std::string& src) {

	pieces.clear();
	batch.clear();
	results.clear();
	res.clear();
	auto is_invisible_char_except_space = [](unsigned char c) -> bool {
		return std::iscntrl(c) && c != ' '; // 保留空格，移除控制字符
		};
	src.erase(std::remove_if(src.begin(), src.end(), is_invisible_char_except_space), src.end());
	//src.erase(std::remove_if(src.begin(), src.end(), ::isspace), src.end());
	processor.Encode(src, &pieces);

	if ("zhen" == l_type) {
		pieces.emplace(pieces.begin(), "__zh__");

		batch.push_back(pieces);
	}
	else if ("enzh" == l_type) {
		pieces.emplace(pieces.begin(), "en");
		batch.push_back(pieces);
	}
	

	if ("zhen" == l_type) {
		results = translator->translate_batch(batch, target_prefix, options);
	}
	else if ("enzh" == l_type) {
		results = translator->translate_batch(batch, target_prefix, options);
	}

	for (const auto& token : results[0].output()) {

		res.push_back(token);
	}
	resprocessor.Decode(res, &text);


	return text;
}
void atomizationCmd_translate::AtomCmdTranslate::set_config() {
	std::string current_paht = exec_cmd("where.exe mk");
	//std::cout <<"mk in path: "<< current_paht << std::endl;
	current_paht.erase(current_paht.size() - 7);
	addlanguage(current_paht);


}
void atomizationCmd_translate::AtomCmdTranslate::set_config(std::string _path) {
	addlanguage(getcwd());
}
void atomizationCmd_translate::AtomCmdTranslate::addlanguage(std::string _path) {
	_path = stringCharacterReplace(_path, '\\', "/");
	languages.processor = _path + "/model/opus-2020-07-17zhen/source.spm";
	languages.resprocessor = _path + "/model/opus-2020-07-17enzh/source.spm";
	languages.Translator = _path + "/model/zhen_ctranslate2";
	v_languages.push_back(languages);
	languages.processor = _path + "/model/opus-2020-07-17enzh/source.spm";
	languages.resprocessor = _path + "/model/opus-2020-07-17zhen/source.spm";
	languages.Translator = _path + "/model/enzh_ctranslate2";
	v_languages.push_back(languages);
}

atomizationCmd_translate::AtomCmdTranslate::~AtomCmdTranslate() {
	delete translator;
	translator = nullptr;
}
std::string wstring_to_utf8(const std::wstring& wstr) {
	std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
	return converter.to_bytes(wstr);
}
std::wstring utf8_to_wstring(const std::string& str) {
	std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
	return converter.from_bytes(str);
}
// 按字符（而非字节）截取字符串
std::vector<std::string> truncateIntoSentencesUtf8(const std::string& text, size_t max_len) {
	std::vector<std::string> sentences;
	std::wstring wtext = utf8_to_wstring(text);  // 转换为宽字符

	size_t start = 0;
	while (start < wtext.length()) {
		// 如果剩余字符小于等于 max_len，直接截取
		if (wtext.length() - start <= max_len) {
			sentences.push_back(wstring_to_utf8(wtext.substr(start)));
			break;
		}

		// 查找在当前范围内最后一个句号（。或.）
		size_t pos = wtext.find_last_of(L"。.", start + max_len);
		if (pos == std::wstring::npos || pos < start) {
			// 如果没有找到句号，直接截取 max_len 长度的字符
			size_t pos2 = wtext.find_last_of(L"，", start + max_len);
			if (pos2 == std::wstring::npos || pos2 < start) {
				sentences.push_back(wstring_to_utf8(wtext.substr(start, max_len)));
				start += max_len; // 更新起始位置
			}
			else {

				sentences.push_back(wstring_to_utf8(wtext.substr(start, pos2 - start + 1)));
				start = pos2 + 1; // 更新起始位置
			}

		}
		else {
			// 找到句号，截取到句号位置
			sentences.push_back(wstring_to_utf8(wtext.substr(start, pos - start + 1)));
			start = pos + 1; // 跳过句号，继续处理
		}
	}

	return sentences;
}
std::vector<std::string> atomizationCmd_translate::StrPrse::strslice() {

	return [&]() -> std::vector<std::string> {
		if ("zhen" == l_type) {
			vstrs = truncateIntoSentencesUtf8(strs, 140);
		}
		else {
			vstrs.push_back(strs);
		}
		for (auto& i : vstrs) {

			std::cout << "sent:" << boost::locale::conv::between(i, "GBK", "UTF-8") << std::endl;
		}

		return vstrs;
		}();
}