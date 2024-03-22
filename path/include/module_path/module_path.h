#pragma once
#include<abstraction_path/Abs_Path.h>
namespace module_path {
	class ModulePath :public abstraction_path::Abs_path
	{
	public:
		int set_path(std::string _file_path, std::string _CMake_path);
		void set_include_path(std::string _module);
		void set_src_path();
		void set_mainCpp_path();

		void print_path();

		std::string get_include_path();
		std::string get_src_path();
		std::string get_mainCpp();
		
	private:
		std::string src;
		std::string include;
		std::string main_cpp;
	};


}