#pragma once
#include<iostream>
#include<string>
namespace MkCommand {
	class Mk_Command
	{
	public:
		Mk_Command();
		~Mk_Command();
		int MkRun(std::string _receive_commands);
	private:
	};

	Mk_Command::Mk_Command()
	{
	}

	Mk_Command::~Mk_Command()
	{
	}
}