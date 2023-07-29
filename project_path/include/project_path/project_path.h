#pragma once
#include<abstraction_path/Abs_Path.h>
namespace project_path {
	class project_path : public abstraction_path::Abs_path {
	public:
		int set_path(std::string _file_path, std::string _CMake_path);
	private:

	};
}


