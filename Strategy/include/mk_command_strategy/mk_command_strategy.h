#pragma once
#include<abstraction_strategy/abstraction_strategy.h>
#include<vector>
namespace MkCommandStrategy {
	class CMKCommandStrategy :public AbsStratety::CAbsStratry
	{

	public:
		CMKCommandStrategy(std::string _cmdtype) {
			cmdtype = _cmdtype;
		}
		void initmap();
		int execute(std::vector<std::string> v_command);
		std::string cmdtype;
	private:
		
	};
}
