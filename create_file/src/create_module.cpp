#include<create_module/create_module.h>

int CreateModule::Create_Module::creta_files(std::string _file_name)
{
	set_module_Path(_file_name);

	get_module_Path().get_file_path();
	MkDir(get_module_Path().get_file_path());

	get_module_Path().get_cmake_path();
	create_cmaketxt(get_module_Path().get_cmake_path(), "Module");

	get_module_Path().get_include_path();
	MkDir(get_module_Path().get_include_path());

	get_module_Path().get_src_path();
	MkDir(get_module_Path().get_src_path());

	return 0;
}
