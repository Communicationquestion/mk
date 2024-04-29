#pragma once
#include<iostream>
#include<ThirdParty/thirdparty.h>
#include<abstraction_command/abstraction_command.h>
#include<sentencepiece_processor.h>
  

namespace atomizationCmd_translate { 



	class AtomCmdTranslate : public AbsCommand::Abs_Command
	{
	public:

		AtomCmdTranslate(std::string _type);
		~AtomCmdTranslate();
		void translation(std::string _input);

	private: 
		std::string type; 

		std::vector<std::string> pieces;

		std::vector<std::vector<std::string>> batch ;

		std::vector<ctranslate2::TranslationResult> results;

		std::vector<std::string> res;

		std::string text;
		
		ctranslate2::Translator *translator=nullptr;
		sentencepiece::SentencePieceProcessor processor;
		sentencepiece::SentencePieceProcessor resprocessor;

	};

}

