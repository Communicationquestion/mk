#pragma once
#include<iostream>
#include<ThirdParty/thirdparty.h>
#include<abstraction_command/abstraction_command.h>
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
		void get_model_root(std::string _path);
		void get_model_root();
		void output(std::vector<std::string> &&_output);
		std::string translationSentences(std::string &src);
		int set_ctranslate2(ctranslate2::Device _device = ctranslate2::Device::CPU);
		void set_processor_languages();
		

	private: 
		std::map<std::string, std::string>  processor_map;
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
		std::vector < std::vector<std::string>> target_prefix{  };
		ctranslate2::TranslationOptions options;
	};

	class StrPrse {
	public:
		StrPrse(std::string&& str,std::string && _type) :strs(std::move(str)),l_type(_type) {
			
		}
		std::vector<std::string> strslice();
	private:
		std::string l_type;
		std::string strs;
		std::vector<std::string> vstrs{};
	};

}

