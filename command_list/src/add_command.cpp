#include <add_command/add_command.h>
#include <utility>

void addmodule::Add_Module::init(std::string _modeule_folder) {
    m_modeule_folder = std::move(_modeule_folder);
}

int addmodule::Add_Module::creta_files(std::string _file_name, std::string _type) {

    set_paths(_type);
    m_paths.print_paths();

    m_paths.create_file<fs::path>(m_paths.get_path<fs::path>("module_root_folder_path"), "");
    set_module_cmake_txt(std::move(_file_name), std::move(_type));
    m_paths.create_file<fs::path>(m_paths.get_path<fs::path>("camke_txt_file_path"), module_cmake_txt, false);

    // m_paths.create_file<fs::path>(m_paths.get_path<fs::path>("module_include_path"),"");
    m_paths.createDirectory(m_paths.get_path<fs::path>("module_include_path"));

    m_paths.create_file<fs::path>(m_paths.get_path<fs::path>("src_path"), "");

    m_paths.create_file<fs::path>(m_paths.get_path<fs::path>("main_path"), "", false);

    return 0;
}
int addmodule::Add_Module::set_module_cmake_txt(std::string _file_name, std::string _type) {
    std::string str{};
    for (auto& a : _file_name) {
        if (a == '\\') {
            break;
        } else {
            str = str + a;
        }
    }
    std::string file = "file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.h)\n";
    std::string add_library{};
    if ("project" == _type) {
        add_library = "add_executable(" + str + " ${srcs})\n";
    } else {
        add_library = "add_library(" + str + " STATIC ${srcs})\n";
    }

    std::string target_include_directories = "target_include_directories(" + str + " PUBLIC include)\n";
    module_cmake_txt                       = file + add_library + target_include_directories;
    return 0;
}

void addmodule::Add_Module::set_paths(std::string _type) {

    template_path::Template_Path<fs::path, std::string>::pathtype module_root_folder_path =
        std::string(m_modeule_folder);
    m_paths.set_path("module_root_folder_path", module_root_folder_path);
    if ("project" == _type) {

        template_path::Template_Path<fs::path, std::string>::pathtype module_root_folder_path =
            std::string(m_modeule_folder + "/" + m_modeule_folder);
        m_paths.set_path("module_root_folder_path", module_root_folder_path);
    }

    fs::path tmp_camke_txt_file_path = m_paths.get_path<fs::path>("module_root_folder_path") / "CMakeLists.txt";
    template_path::Template_Path<fs::path, std::string>::pathtype camke_txt_file_path = tmp_camke_txt_file_path;
    m_paths.set_path("camke_txt_file_path", camke_txt_file_path);

    fs::path tmp_module_include_path =
        m_paths.get_path<fs::path>("module_root_folder_path") / "include" / m_modeule_folder;
    template_path::Template_Path<fs::path, std::string>::pathtype module_include_path = tmp_module_include_path;
    m_paths.set_path("module_include_path", module_include_path);

    fs::path tmp_src_path = m_paths.get_path<fs::path>("module_root_folder_path") / "src";
    template_path::Template_Path<fs::path, std::string>::pathtype src_path = tmp_src_path;
    m_paths.set_path("src_path", src_path);

    std::string cppfile        = m_modeule_folder + ".cpp";
    fs::path tmp_main_cpp_path = m_paths.get_path<fs::path>("src_path") / cppfile;
    template_path::Template_Path<fs::path, std::string>::pathtype main_path = tmp_main_cpp_path;
    m_paths.set_path("main_path", main_path);
}
