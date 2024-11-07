#include <translate_command/translate_command.h>

atomizationCmd_translate::AtomCmdTranslate::AtomCmdTranslate(
    std::string _type) {
  l_type = _type;
  // addlanguage("test");
  set_config();

  options.beam_size = 5;
  options.length_penalty = 1.0;

  options.max_decoding_length = 500;

  if ("zhen" == l_type) {
    target_prefix.push_back({{"__en__"}});
  } else if ("enzh" == l_type) {
    target_prefix.push_back({{"zh_CN"}});
  }

  if (_type == "zhen") {
    languages.processor = v_languages.at(0).processor;
    languages.resprocessor = v_languages.at(0).resprocessor;
    languages.Translator = v_languages.at(0).Translator;
  } else if (_type == "enzh") {
    languages.processor = v_languages.at(1).processor;
    languages.resprocessor = v_languages.at(1).resprocessor;
    languages.Translator = v_languages.at(1).Translator;
  } else {
    languages.processor = {};
    languages.resprocessor = {};
    languages.Translator = {};
  }

  const auto status = processor.Load(
      languages.processor); //("D:/model/opus-2020-07-17zhen/source.spm");
  if (!status.ok()) {
    std::cerr << status.ToString() << std::endl;
    // error#include <boost/algorithm/string.hpp>
#include <boost/locale/encoding.hpp>
#include <boost/process.hpp>
  }

  const auto resstatus = resprocessor.Load(
      languages.resprocessor); //("D:/model/opus-2020-07-17enzh/source.spm");
  if (!resstatus.ok()) {
    std::cerr << resstatus.ToString() << std::endl;
    // error
  }

  translator = new ctranslate2::Translator(
      languages.Translator /*"D:/model/zhen_ctranslate2"*/,
      ctranslate2::Device::CPU);
}

void atomizationCmd_translate::AtomCmdTranslate::translation(
    std::string _input) {

  StrPrse strpres(std::move(_input), std::move(l_type));

  std::vector<std::string> vout{};
  for (auto i : strpres.strslice()) {

    vout.push_back(translationSentences(i));
  }
  output(std::move(vout));
}

void atomizationCmd_translate::AtomCmdTranslate::output(
    std::vector<std::string> &&_output) {
  for (auto &text : _output) {
    boost::algorithm::replace_all(text, "▁", " ");
    std::cout << boost::locale::conv::between(text, "GBK", "UTF-8")
              << std::endl;
  }
}

std::string atomizationCmd_translate::AtomCmdTranslate::translationSentences(
    std::string &src) {

  pieces.clear();
  batch.clear();
  results.clear();
  res.clear();
  auto is_invisible_char_except_space = [](unsigned char c) -> bool {
    return std::iscntrl(c) && c != ' ';
  };
  src.erase(
      std::remove_if(src.begin(), src.end(), is_invisible_char_except_space),
      src.end());

  processor.Encode(src, &pieces);
  if ("zhen" == l_type) {
    pieces.emplace(pieces.begin(), "__zh__");

  } else if ("enzh" == l_type) {
    pieces.emplace(pieces.begin(), "en");
  }
  batch.push_back(pieces);
  results = translator->translate_batch(batch, target_prefix, options);

  for (const auto &token : results[0].output()) {

    res.push_back(token);
  }
  resprocessor.Decode(res, &text);

  return text;
}
void atomizationCmd_translate::AtomCmdTranslate::set_config() {
  std::filesystem::path currentPath = std::filesystem::current_path();
  std::string current_path = currentPath.string();

  current_path.erase(current_path.size() - 7);
  addlanguage(current_path);
}
void atomizationCmd_translate::AtomCmdTranslate::set_config(std::string _path) {
  addlanguage(_path);
}
void atomizationCmd_translate::AtomCmdTranslate::addlanguage(
    std::string _path) {
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

std::vector<std::string> atomizationCmd_translate::StrPrse::strslice() {

  return [&]() -> std::vector<std::string> {
    if ("zhen" == l_type) {
      vstrs = truncateIntoSentencesUtf8(strs, 140);
    } else if ("enzh" == l_type) {
      vstrs = truncateIntoSentencesUtf8(strs, 240);
    }
    return vstrs;
  }();
}
