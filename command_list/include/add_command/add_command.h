#pragma once
#include <template_path/template_path.h>

namespace addmodule {
class Add_Module {
public:
  void init(std::string _modeule_folder);
  int creta_files(std::string _file_name, std::string _type);
  int set_module_cmake_txt(std::string _file_name, std::string _type);

  void set_paths(std::string _type);

private:
  std::string module_cmake_txt;
  // std::string project_cmake_txt;
  std::string m_modeule_folder;
  std::string m_type;
  template_path::Template_Path<fs::path, std::string> m_paths;
};
} // namespace addmodule
