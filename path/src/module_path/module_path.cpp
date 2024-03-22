#include<module_path/module_path.h>

int module_path::ModulePath::set_path(std::string _file_path, std::string _CMake_path)
{
	set_file_path(_file_path);

	set_CMake_path(_CMake_path);

	set_include_path(_file_path);

	set_src_path();

	set_mainCpp_path();

	return 0;
}

void module_path::ModulePath::set_include_path(std::string _module)
{
	std::string str = _module;
	std::string afterSlash;
	std::size_t slashPosition = str.find('\\');  // 寻找第一个斜杠的位置
	if (slashPosition != std::string::npos) {  // 判断是否找到斜杠
		afterSlash = str.substr(slashPosition + 1);  // 获取斜杠后的字符
	}
	include = get_file_path() + "\\" + "include" + "\\" + afterSlash;
}

void module_path::ModulePath::set_src_path()
{
	src = get_file_path() + "\\" + "src";
}

void module_path::ModulePath::set_mainCpp_path()
{
	main_cpp= get_file_path() + "\\" + "src"+"\\"+"main.cpp";
}
void module_path::ModulePath::print_path()
{
	std::cout << get_file_path() << std::endl;
	std::cout << get_cmake_path() << std::endl;
	std::cout << include << std::endl;
	std::cout << src << std::endl;
	std::cout << main_cpp << std::endl;
}
std::string module_path::ModulePath::get_include_path()
{
	return include;
}
std::string module_path::ModulePath::get_src_path()
{
	return src;
}
std::string module_path::ModulePath::get_mainCpp()
{
	return main_cpp;
}