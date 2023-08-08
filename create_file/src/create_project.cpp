#include<create_project/create_project.h>
int create_project::CreateProject::creta_files(std::string _file_name)
{
	set_project_path(_file_name);

	MkDir(get_project_path().get_file_path());

	create_cmaketxt(get_project_path().get_cmake_path(), "main");

	return 0;
}
