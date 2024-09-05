#pragma once
#include<iostream>
#include<string>
#include<vector>
namespace edtxt {
	template <class T>
	class edtxtfile
	{
	public:
		std::vector<T> txttoitem(std::string&& str) {
			std::stringstream ss(str);
			std::string line;
			while (std::getline(ss, line, '\n')) {
				auto name = [&line]()->std::string {
					//取得空格前的字串
					auto pos = line.find(' ');
					if (pos != std::string::npos) {
						return line.substr(0, pos);
					}
					}; 

				//auto user = 
				//auto passwd = 
			}
			return std::vector<T>{};
		}
	private:

	};
}