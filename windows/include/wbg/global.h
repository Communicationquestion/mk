#pragma once
#include <vector>
struct Account {
	QString name;
	QString user;
	QString passwd;

};
extern std::vector<Account>* myenv;