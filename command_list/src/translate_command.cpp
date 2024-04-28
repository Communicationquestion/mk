#include<translate_command/translate_command.h>
atomizationCmd_translate::AtomCmdTranslate::AtomCmdTranslate(std::string _type)
{
	const auto status = processor.Load("D:/model/opus-2020-07-17zhen/source.spm");
    if (!status.ok()) {
        std::cerr << status.ToString() << std::endl;
        // error
    }

    const auto resstatus = resprocessor.Load("D:/model/opus-2020-07-17enzh/source.spm");
    if (!resstatus.ok()) {
        std::cerr << resstatus.ToString() << std::endl;
        // error
    }

   translator =new ctranslate2::Translator("D:/model/zhen_ctranslate2", ctranslate2::Device::CPU);

}

void atomizationCmd_translate::AtomCmdTranslate::translation(std::string _input)
{

    _input = GbkToUtf8(_input.c_str());
    processor.Encode(_input, &pieces);
    //for (const std::string& token : pieces) {
    //    std::cout << token << std::endl;
    //}
   
    batch = { pieces };
    results = translator->translate_batch(batch);

    for (const auto& token : results[0].output()) {
        //std::cout << token;
        res.push_back(token);
    }
  
    resprocessor.Decode(res, &text);

    
    std::cout << text << std::endl;
}