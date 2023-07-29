#include<abstraction_create/abstraction_create.h>

project_path::project_path abstraction_create::Abs_create::set_project_path(std::string _file)
{

	ProjectPath.set_path(_file, "cmake");

	ProjectPath.print_path();

	return ProjectPath;
}


module_path::ModulePath abstraction_create::Abs_create::set_module_Path(std::string _file_path)
{

	ModulePath.set_path(_file_path, "cmake");

	ModulePath.print_path();

	return ModulePath;
}

project_path::project_path abstraction_create::Abs_create::get_project_path()
{
	return ProjectPath;
}

module_path::ModulePath abstraction_create::Abs_create::get_module_Path()
{
	return ModulePath;
}
