#include<translate_command/translate_command.h>
atomizationCmd_translate::AtomCmdTranslate::AtomCmdTranslate(std::string _type)
{
    l_type = _type;
    addlanguage();
    if (_type == "zhen") {
        languages.processor =v_languages.at(0).processor;
        languages.resprocessor = v_languages.at(0).resprocessor;
        languages.Translator = v_languages.at(0).Translator;
    }
    else if(_type == "enzh"){
        languages.processor = v_languages.at(1).processor;
        languages.resprocessor = v_languages.at(1).resprocessor;
        languages.Translator = v_languages.at(1).Translator;
    }
    else{
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

   translator =new ctranslate2::Translator(languages.Translator/*"D:/model/zhen_ctranslate2"*/, ctranslate2::Device::CPU);

}

void atomizationCmd_translate::AtomCmdTranslate::translation(std::string _input)
{
    //std::cout <<"1-----  " << _input << std::endl;
    std::string gres = "▁";
    _input = stringCharacterReplace(_input, ' ', Utf8ToGbk(gres.c_str()));
    //std::cout <<"_input " << _input << std::endl;

    
        //_input = GbkToUtf8(_input.c_str());
   
   

    processor.Encode(_input, &pieces);

   
    batch = { pieces };
    results = translator->translate_batch(batch);

    for (const auto& token : results[0].output()) {
       
        res.push_back(token);
    }
  
    resprocessor.Decode(res, &text);

    std::cout << Utf8ToGbk(text.c_str()) << std::endl;

}

void atomizationCmd_translate::AtomCmdTranslate::addlanguage()
{

    languages.processor = "D:/model/opus-2020-07-17zhen/source.spm";
    languages.resprocessor = "D:/model/opus-2020-07-17enzh/source.spm";
    languages.Translator = "D:/model/zhen_ctranslate2";
    v_languages.push_back(languages);
    languages.processor = "D:/model/opus-2020-07-17enzh/source.spm";
    languages.resprocessor = "D:/model/opus-2020-07-17zhen/source.spm";
    languages.Translator = "D:/model/enzh_ctranslate2";
    v_languages.push_back(languages);
}

atomizationCmd_translate::AtomCmdTranslate::~AtomCmdTranslate()
{
    delete translator;
    translator = nullptr;
}