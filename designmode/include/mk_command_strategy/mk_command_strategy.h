#pragma once
#include<designmode/abstraction_strategy/abstraction_strategy.h>
#include<vector>
namespace MkCommandStrategy {
	class CMKCommandStrategy :public AbsStratety::CAbsStratry
	{

	public:
		CMKCommandStrategy(std::string _cmdtype) {
			cmdtype = _cmdtype;
		}
        bool isUtf8(const std::string& text) {
            for(size_t i = 0; i < text.size(); ++i) {
                unsigned char byte = static_cast<unsigned char>(text[i]);
                if(byte <= 0x7F) {
                    continue;  // ASCII
                } else if((byte & 0xE0) == 0xC0) {
                    if(i + 1 >= text.size() || (text[i + 1] & 0xC0) != 0x80) {
                        return false;
                    }
                    i += 1;
                } else if((byte & 0xF0) == 0xE0) {
                    if(i + 2 >= text.size() || (text[i + 1] & 0xC0) != 0x80 || (text[i + 2] & 0xC0) != 0x80) {
                        return false;
                    }
                    i += 2;
                } else if((byte & 0xF8) == 0xF0) {
                    if(i + 3 >= text.size() || (text[i + 1] & 0xC0) != 0x80 || (text[i + 2] & 0xC0) != 0x80 || (text[i + 3] & 0xC0) != 0x80) {
                        return false;
                    }
                    i += 3;
                } else {
                    return false;
                }
            }
            return true;
        }
		void initmap();
		int execute(std::vector<std::string> v_command);
		std::string cmdtype;
	private:
		
	};
}
