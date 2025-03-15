#pragma once
#include <iostream>
#include <optional>
#include <string>
#include <type_traits>

#include <boost/stacktrace.hpp>
template <typename T, bool isbreak = false>
void lookerr(std::optional<T> err) {

    if (err.has_value()) {
        std::cout << "Initialization error: " << *err << std::endl;
        boost::stacktrace::stacktrace st;
        std::cout << st[3] << "\n";
        if constexpr (isbreak) {
            std::exit(EXIT_FAILURE); // 使用 EXIT_FAILURE 表示失败
        }
    }
}
