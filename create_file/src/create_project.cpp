#include<create_project/create_project.h>
int create_project::CreateProject::creta_files(std::string _file_name)
{
	set_project_path(_file_name);

	MkDir(get_project_path().get_file_path());

	set_project_cmake_txt(_file_name);

	create_cmaketxt(get_project_path().get_cmake_path(), project_cmake_txt);

	return 0;
}
int create_project::CreateProject::set_project_cmake_txt(std::string _file_name)
{
	//cmake_minimum_required(VERSION 3.8)
	//set(CMAKE_CXX_STANDARD 20)
	//set(CMAKE_CXX_STANDARD_REQUIRED ON)
	//set(CMAKE_CXX_EXTENSIONS OFF)
	//project("mk")

	std::string cmake_minimum_required = "cmake_minimum_required(VERSION 3.8)\n";
	std::string set_cpp_standard = "set(CMAKE_CXX_STANDARD 20)\n";
	std::string set_standard_required = "set(CMAKE_CXX_STANDARD_REQUIRED ON)\n";
	std::string set_extensions = "set(CMAKE_CXX_EXTENSIONS OFF)\n";
	std::string project = "project(\"" + _file_name + "\")\n";
	project_cmake_txt = cmake_minimum_required + set_cpp_standard + set_standard_required + set_extensions + project;
	return 0;
}

