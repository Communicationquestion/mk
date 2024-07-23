#include<abstraction_path/Abs_Path.h>  
void abstraction_path::Abs_path::set_file_path(std::string _file_path)
{
	file_path = get_current_path() + "\\" + _file_path;

}
void abstraction_path::Abs_path::set_CMake_path(std::string _CMake_path)
{
	CMake_path = get_file_path() + "\\" + _CMake_path;
}

std::string abstraction_path::Abs_path::get_file_path()
{
	return file_path;
}

std::string abstraction_path::Abs_path::get_cmake_path()
{
	return CMake_path;
}
void abstraction_path::Abs_path::print_path()
{
	std::cout << file_path << std::endl;

	std::cout << CMake_path << std::endl;
}

std::string abstraction_path::Abs_path::get_current_path()
{
	std::filesystem::path currentPath = std::filesystem::current_path();
	return currentPath.string();
}

std::string abstraction_path::Abs_path::get_exe_path()
{
	return std::string();
}
