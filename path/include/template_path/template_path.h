#pragma once
#include <filesystem>
#include <iostream>
#include <stdexcept>
#include <string>
#include <tuple>
#include <unordered_map>
#include <variant>
#include <fstream>
namespace fs = std::filesystem;

namespace template_path {
    template<typename... Types>
    class Template_Path {
    public:
        fs::path get_current_path() { return fs::current_path(); };

        template<typename PathType>
        void create_file(const PathType &path, const std::string _txt, bool is_directory = true) {
            try {
                if (is_directory) {
                    if (fs::create_directory(path)) {
                        std::cout << "Directory created: " << path << std::endl;
                        return;
                    }
                    std::cout << "Directory already exists: " << path << std::endl;
                    return;
                }
                if (!is_directory) {
                    // 创建文件并写入内容
                    std::ofstream file(path);
                    if (file.is_open()) {
                        file << _txt;
                        file.close();
                        return;
                    }
                    std::cerr << "Failed to create the file: " << path << std::endl;
                }
            } catch (const fs::filesystem_error &e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
        bool createDirectory(const fs::path& directory) {
            try {
                // 递归地创建目录
                if (fs::create_directories(directory)) {
                    std::cout << "Directory created successfully: " << directory << std::endl;
                    return true;
                } else {
                    std::cout << "Directory already exists: " << directory << std::endl;
                    return false;  // 目录已经存在
                }
            } catch (const fs::filesystem_error& e) {
                std::cerr << "Filesystem error: " << e.what() << std::endl;
            } catch (const std::exception& e) {
                std::cerr << "General error: " << e.what() << std::endl;
            }

            return false;  // 如果发生异常，返回 false
        }
        using pathtype = std::variant<Types...>;

        void set_path(const std::string &name, pathtype &value) {
            std::visit([&](auto &v) { set_path_impl(name, v); }, value);
        }

        void set_path_impl(const std::string &name, fs::path value) {
            paths[name] =
                    get_current_path() / value;
        }

        void set_path_impl(const std::string &name, std::string value) {
            fs::path temp_path = get_current_path() / value;
            paths[name] = temp_path;
        }

        template<typename T>
        T get_path(const std::string &name) const {
            auto it = paths.find(name);
            if (it != paths.end()) {
                return std::get<T>(it->second);
            }
            throw std::runtime_error("Field not found or type mismatch");
        }

        // 遍历并打印所有字段
        void print_paths() const {
            for (const auto &[name, value]: paths) {
                std::cout << name << ": ";
                std::visit([](const auto &v) { std::cout << v << std::endl; }, value);
            }
        }

    private:
        std::unordered_map<std::string, pathtype> paths; // 动态键值表
    };
} // namespace abstraction_path
