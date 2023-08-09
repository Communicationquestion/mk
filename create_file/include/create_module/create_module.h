#pragma once
#include<abstraction_create/abstraction_create.h>
namespace CreateModule {
	class Create_Module :public abstraction_create::Abs_create {
	public:
		int creta_files(std::string _file_name);
		int set_module_cmake_txt(std::string _file_name);
		std::string get_module_cmake_txt();
	private:
		std::string module_cmake_txt;
	};
}