#pragma once
#include <type_traits>
#include <string>
#include <optional>
#include <iostream>
#include <boost/stacktrace.hpp>
template<typename T, bool isbreak = false>
std::optional<T> lookerr(std::optional<T> err) {
	boost::stacktrace::stacktrace st;
	std::cout << st[3] << "\n";
	if (err.has_value()) {
		std::cout << "Initialization error: " << *err << std::endl;
		if constexpr (isbreak) {
			std::exit(EXIT_FAILURE);  // 使用 EXIT_FAILURE 表示失败
		}
		else {
			return *err;  // 返回具体的错误信息
		}
	}
	else {
		std::cout << "Initialization succeeded." << std::endl;
		return std::nullopt;  // 返回 nullopt 表示成功
	}
}



