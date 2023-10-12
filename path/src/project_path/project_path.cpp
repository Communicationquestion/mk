#include<project_path/project_path.h>
int project_path::project_path::set_path(std::string _file_path, std::string _CMake_path)
{
	set_file_path(_file_path);
	set_CMake_path(_CMake_path);
	return 0;
}
