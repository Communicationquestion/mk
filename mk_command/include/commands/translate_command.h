#pragma once
#include <common_command/common_command.h>
#include <translate_command/translate_command.h>
class TranslateCommand : public CommonCommand::CCommonCommand {
public:
    TranslateCommand(std::string _type) : toen(_type) {};
    int MkRun();
    int MkRun(std::string _receive_commands) ;

private:
    atomizationCmd_translate::AtomCmdTranslate toen;
};