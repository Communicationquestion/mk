#pragma once
#include<iostream>
#include<ThirdParty/thirdparty.h>
#include<abstraction_command/abstraction_command.h>
#include<sentencepiece_processor.h>
#include<abstraction_path/Abs_Path.h>
  

namespace atomizationCmd_translate { 

	struct Languages
	{
		std::string processor;
		std::string resprocessor;
		std::string Translator;
	};
	class Get_Path : public abstraction_path::Abs_path {
		int set_path(std::string _file_path, std::string _CMake_path) {
			return 0;
		}
	};

	class AtomCmdTranslate : public AbsCommand::Abs_Command
	{
	public:

		AtomCmdTranslate(std::string _type);
		~AtomCmdTranslate();
		void translation(std::string _input);
		void addlanguage(std::string _disk_path);
		void set_config(std::string _path);
		void set_config();




	private: 

		Get_Path path;

		std::string type; 

		std::vector<std::string> pieces;

		std::vector<std::vector<std::string>> batch ;

		std::vector<ctranslate2::TranslationResult> results;

		std::vector<std::string> res;
		std::string l_type;
		std::string text;
		std::vector<Languages> v_languages;
		Languages languages;
		ctranslate2::Translator *translator=nullptr;
		sentencepiece::SentencePieceProcessor processor;
		sentencepiece::SentencePieceProcessor resprocessor;

	};

}

