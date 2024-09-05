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
			for (auto& i : str) {
				//T.name = i;
				std::cout << i;
			}
			return std::vector<T>{};
		}
	private:

	};



}