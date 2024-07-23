#pragma once
#include<string>
#include<iostream>
#include <filesystem>
namespace abstraction_path {
	class Abs_path {
	public:
		virtual int set_path(std::string _file_path, std::string _CMake_path) = 0;
		void set_file_path(std::string _file_path);
		void set_CMake_path(std::string _CMake_path);
		std::string get_file_path();
		std::string get_cmake_path();
		virtual	void print_path();
		std::string get_current_path();
		std::string get_exe_path();
	private:
		std::string file_path;
		std::string CMake_path;

	};
}