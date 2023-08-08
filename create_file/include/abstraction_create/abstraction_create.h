#pragma once
#include<project_path/project_path.h>
#include<module_path/module_path.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#ifdef _WIN32
#include <direct.h>		//for mkdir rmdir
#include <io.h>			//for access
#elif __linux__
#include <unistd.h>		//for mkdir rmdir
#include <sys/stat.h>	//for access
#include <dirent.h>		//for DIR remove
#endif

#ifdef _WIN32
#define ACCESS _access
#define MKDIR(a) _mkdir((a))
#define RMDIR(a) _rmdir((a))
#elif __linux__
#define ACCESS access
#define MKDIR(a) mkdir((a),0755)
#define RMDIR(a) rmdir((a))
#endif

namespace abstraction_create {
	class Abs_create
	{
	public:
		virtual int creta_files(std::string _file_name) = 0;
		bool MkDir(const std::string& strPath);
		int create_cmaketxt(std::string _cmakePath, std::string _txt);
		project_path::project_path set_project_path(std::string _file);

		module_path::ModulePath  set_module_Path(std::string _file_path);

		project_path::project_path get_project_path();

		module_path::ModulePath  get_module_Path();

	private:
		project_path::project_path ProjectPath;

		module_path::ModulePath  ModulePath;
	};


}
