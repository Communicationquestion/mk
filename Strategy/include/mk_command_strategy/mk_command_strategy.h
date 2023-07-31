#pragma once
#include<abstraction_strategy/abstraction_strategy.h>
namespace MkCommandStrategy {
	class CMKCommandStrategy :public AbsStratety::CAbsStratry
	{
	public:

		int execute(std::string _command);
	private:

	};
}
