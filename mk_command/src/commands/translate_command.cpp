#include<commands/translate_command.h>

int TranslateCommand::MkRun()
{

	//toen.translation("翻译");
	toen.get_model_root();
	return 0;
}
int TranslateCommand::MkRun(std::string _receive_commands)
{
	toen.translation(_receive_commands);
	
	return 0;
}
