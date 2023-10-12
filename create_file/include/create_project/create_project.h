#pragma once
#include<abstraction_create/abstraction_create.h>
namespace create_project {
	class CreateProject :public abstraction_create::Abs_create
	{
	public:
		int creta_files(std::string _file_name,std::string _type);
		int creta_files(std::string _file_name);
		int set_project_cmake_txt(std::string _file_name);
		std::string get_project_cmake_txt();
	private:
		std::string project_cmake_txt;
	};


}