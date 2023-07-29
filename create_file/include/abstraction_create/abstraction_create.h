#pragma once
#include<project_path/project_path.h>
#include<module_path/module_path.h>
namespace abstraction_create {
	class Abs_create
	{
	public:
		virtual int creta_files() = 0;
		project_path::project_path set_project_path(std::string _file);

		module_path::ModulePath  set_module_Path(std::string _file_path);

		project_path::project_path get_project_path();

		module_path::ModulePath  get_module_Path();

	private:
		project_path::project_path ProjectPath;

		module_path::ModulePath  ModulePath;
	};


}
