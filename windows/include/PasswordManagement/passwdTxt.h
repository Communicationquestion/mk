#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<qstring.h>
namespace edtxt {
	template <class T>
	class edtxtfile {
	public:
		void txttoitem(std::string&& str, std::vector<T>& vec) {
			std::string token;
			std::istringstream tokenStream(str);
			while (std::getline(tokenStream, token, '\n')) {
				vec.push_back(itemtostruct(std::move(token)));
			}
			return;
		}

		T itemtostruct(std::string&& line) {
			return [&line]()-> T {
				auto name = [&]()->std::string {
					auto pos = line.find(' ');
					if (pos != std::string::npos) {
						return line.substr(0, pos);
					}
					else {
						return "";
					}
					}();
				auto user = [&line]()->std::string {
					auto firstSpacePos = line.find(' ');

					if (firstSpacePos != std::string::npos) {
						int secondSpacePos = line.find(' ', firstSpacePos + 1);  // 找到第二个空格的位置

						if (secondSpacePos != std::string::npos) {
							return line.substr(firstSpacePos, secondSpacePos);
						}
						else {
							return "";
						}
					}

					}();
				auto passwd = [&line]()->std::string {
					auto firstSpacePos = line.find(' ');

					if (firstSpacePos != std::string::npos) {
						int secondSpacePos = line.find(' ', firstSpacePos + 1);  // 找到第二个空格的位置

						if (secondSpacePos != std::string::npos) {
							return line.substr(secondSpacePos);;
						}
						else {
							return "";
						}
					}
					}();
				return { QString::fromStdString(std::move(name)), QString::fromStdString(std::move(user)), QString::fromStdString(std::move(passwd)) };
				}();
		}

	private:

	};
}