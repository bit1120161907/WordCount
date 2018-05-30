// wordcount.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main(int argc, char* argv[])
{
	int codeL = 0, nuL = 0, anL = 0, chN = 0, wN = 0, lN = 0;
	int bo[5] = { 0,0,0,0,0 };
	while (1)
	{
		int i = 1;
		if (strcmp(argv[i], "-s") == 0)
		{
			bo[0] = 1;
			i++;
		}
		if (strcmp(argv[i], "-a") == 0)
		{
			bo[1] = 1;
			i++;
		}
		if (strcmp(argv[i], "-c") == 0)
		{
			bo[2] = 1;
			i++;
		}
		if (strcmp(argv[i], "-w") == 0)
		{
			bo[3] = 1;
			i++;
		}
		if (strcmp(argv[i], "-l") == 0)
		{
			bo[4] = 1;
			i++;
		}
		if (i >= argc - 1)
		{
			break;
		}
	}
	if (bo[0] == 0)
	{
		FILE *stream;
		int numclosed;
		errno_t err;
		if ((err = fopen_s(&stream, argv[argc - 1], "r")) != 0)
			printf("The file 'crt_fopen_s.c' was not opened\n");
		else
			printf("The file 'crt_fopen_s.c' was opened\n");
		char CmdLine[100];
		while (fscanf_s(stream, "%[^\n]", CmdLine) != EOF)
		{
			lN++;
			int top = 0;
			int i = 0;
			int bo1 = 0, bo2 = 0;
			while (CmdLine[i] != '\0')
			{
				if ((CmdLine[i] > 'a'&&CmdLine[i] < 'z') || (CmdLine[i] > 'A'&&CmdLine[i] < 'Z'))
				{
					chN++;
					top = 1;
					bo1 = 1;
				}
				else 
				{
					if (top == 1) wN++;
					if (CmdLine[i] != '\n' && CmdLine[i] != ' ' && CmdLine[i] != '\t')
					{
						chN++;
					}
					if (CmdLine[i] == '/'&&CmdLine[i + 1] == '/')
					{
						if(bo1 == 0)
						bo2 = 1;
						break;
					}
				}
				i++;
			}
			if (bo1 == 1&&bo2!=1) codeL++;
			else if (bo2 == 1) anL++;
			else nuL++;
		}
		if (stream)
		{
			if (fclose(stream))
			{
				printf("The file 'crt_fopen_s.c' was not closed\n");
			}
		}
	}
	if (bo[0] == 0)
	{
		if (bo[1] == 1)
		{
			printf("codeL:%d\n", codeL);
			printf("nuL:%d\n", nuL);
			printf("anL:%d\n", anL);
		}
		if (bo[2] == 1)
		{
			printf("chN:%d\n", chN);
		}
		if (bo[3] == 1)
		{
			printf("wN:%d\n", wN);
		}
		if (bo[4] == 1)
		{
			printf("lN:%d\n", lN);
		}
	}
    return 0;
}

