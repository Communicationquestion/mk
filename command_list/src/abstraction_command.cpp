#include <cstring>
#include<abstraction_command/abstraction_command.h>

int AbsCommand::Abs_Command::run_cmd(const char* cmd)
{
	char MsgBuff[1024];
	int MsgLen = 1020;
	FILE* fp;
	if (cmd == NULL)
	{
		return -1;
	}
	if ((fp = popen(cmd, "r")) == NULL)
	{
		return -2;
	}
	else
	{
		memset(MsgBuff, 0, MsgLen);

		//读取命令执行过程中的输出
		while (fgets(MsgBuff, MsgLen, fp) != NULL)
		{
			printf("MsgBuff: %s\n", MsgBuff);
		}

		//关闭执行的进程
		if (pclose(fp) == -1)
		{
			return -3;
		}
	}
	return 0;
}
