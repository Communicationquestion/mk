#include <new_command/new_command.h>
#include <utility>

void new_project::NewProject::init(const std::string &_project_name) {
	m_project_name = _project_name;
}


int new_project::NewProject::creta_files(const std::string& _file_name)
{
	set_paths();

	m_paths.create_file<fs::path>(m_paths.get_path<fs::path>("project_root_folder_path"),"");

	set_project_cmake_txt(_file_name);

	m_paths.create_file<fs::path>(m_paths.get_path<fs::path>("camke_txt_file_path"),project_cmake_txt,false);
	return 0;
}
int new_project::NewProject::set_project_cmake_txt(const std::string& _file_name)
{
	std::string cmake_minimum_required = "cmake_minimum_required(VERSION 3.8)\n";
	std::string set_cpp_standard = "set(CMAKE_CXX_STANDARD 20)\n";
	std::string set_standard_required = "set(CMAKE_CXX_STANDARD_REQUIRED ON)\n";
	std::string set_extensions = "set(CMAKE_CXX_EXTENSIONS OFF)\n";
	std::string project = "project(" + _file_name + " LANGUAGES CXX)\n";
	std::string add_subdirectory = "add_subdirectory("+_file_name+")";
	project_cmake_txt = cmake_minimum_required + set_cpp_standard + set_standard_required + set_extensions + project+ add_subdirectory;
	return 0;
}

void new_project::NewProject::set_paths() {
	template_path::Template_Path<fs::path,std::string>::pathtype project_root_folder_path =std::string(m_project_name);
	m_paths.set_path("project_root_folder_path", project_root_folder_path);

	fs::path tmp_camke_txt_file_path = m_paths.get_path<fs::path>("project_root_folder_path") / "CMakeLists.txt";
	template_path::Template_Path<fs::path,std::string>::pathtype camke_txt_file_path = tmp_camke_txt_file_path;
	m_paths.set_path("camke_txt_file_path", camke_txt_file_path);
}
