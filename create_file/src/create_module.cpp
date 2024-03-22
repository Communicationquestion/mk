#include<create_module/create_module.h>

int CreateModule::Create_Module::creta_files(std::string _file_name,std::string _type)
{
	set_module_Path(_file_name);

	get_module_Path().get_file_path();
	MkDir(get_module_Path().get_file_path());

	set_module_cmake_txt(_file_name,_type);

	get_module_Path().get_cmake_path();
	create_cmaketxt(get_module_Path().get_cmake_path(), module_cmake_txt);

	get_module_Path().get_include_path();
	MkDir(get_module_Path().get_include_path());

	get_module_Path().get_src_path();
	MkDir(get_module_Path().get_src_path());
	if (_type == "project") {
		get_module_Path().get_mainCpp();
		create_txt(get_module_Path().get_mainCpp());
	}

	

	return 0;
}
int CreateModule::Create_Module::set_module_cmake_txt(std::string _file_name,std::string _type)
{
	//file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.h)
	//add_library(create_file STATIC ${srcs})
	//target_include_directories(create_file PUBLIC include)
	std::string str{};
	for (auto& a : _file_name) {
		if (a == '\\') {
			break;
		}
		else
		{
			str = str + a;
		}
	}
	std::string file = "file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.h)\n";
	std::string add_library{};
	if ("project" == _type)
	{
		add_library = "add_executable(" + str + " ${srcs})\n";
	}
	else
	{
		add_library = "add_library(" + str + " STATIC ${srcs})\n";
	}
	 

	std::string target_include_directories = "target_include_directories(" + str + " PUBLIC include)\n";
	module_cmake_txt = file + add_library + target_include_directories;
	return 0;
}
int CreateModule::Create_Module::set_project_cmake_txt(std::string _file_name)
{

	return 0;
}