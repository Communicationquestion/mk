#include<translate_command/translate_command.h>

atomizationCmd_translate::AtomCmdTranslate::AtomCmdTranslate(std::string _type) {
	l_type = _type;
	//addlanguage("test");
	set_config();
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
	processor.Encode(_input, &pieces);


	if ("zhen" == l_type) {
		pieces.emplace(pieces.begin(), "__zh__");
		batch = { pieces };
	}
	else if ("enzh" == l_type) {
		pieces.emplace(pieces.begin(), "en");
		batch = { pieces };
	}
	std::vector < std::vector<std::string>> target_prefix{  };
	if ("zhen" == l_type) {
		target_prefix.push_back({ { "__en__" } });
	}
	else if ("enzh" == l_type) {
		target_prefix.push_back({ { "zh_CN" } });
	}

	if ("zhen" == l_type) {
		results = translator->translate_batch(batch, target_prefix);
	}
	else if ("enzh" == l_type) {
		results = translator->translate_batch(batch, target_prefix);
	}





	for (const auto& token : results[0].output()) {

		res.push_back(token);
	}
	resprocessor.Decode(res, &text);
	boost::algorithm::replace_all(text, "▁", " ");

	std::cout << boost::locale::conv::between(text, "GBK", "UTF-8") << std::endl;

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