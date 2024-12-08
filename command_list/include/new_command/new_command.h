#pragma once
#include <template_path/template_path.h>
#include <string>

namespace new_project {
	class NewProject {
	public:
		void init(const std::string &_project_name);

		int creta_files(const std::string& _file_name);

		int set_project_cmake_txt(const std::string& _file_name);

		void set_paths();
		//std::string get_project_cmake_txt();
	private:
		std::string project_cmake_txt;
		std::string m_modeule_folder;
		std::string m_project_name;
		template_path::Template_Path<fs::path, std::string> m_paths;
	};
}
