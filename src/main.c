#include <stdio.h>
#include <conio.h>   //getche函数在此头文件中声明
#include <windows.h> //mciSendString函数在此头文件中声明

//调用mciSendString函数需要引入winmm.lib这个库文件
#pragma comment(lib,"winmm.lib")


int main()
{
	char c;
	char cmd[100];
	int i = 0;
	
	//设置控制台窗口标题
	system("title 电子钢琴 By:IT魔君");  //system函数的功能：执行一个命令
	system("color f4");  //设置控制台窗口前景色和背景色，这里为红色前景，白色背景
	
	while(1)
	{
		//通过键盘输入一个字符
		//c = getchar();
		c = getche(); //和getchar函数的功能一样，但是输入后不需要按回车键确认输入
		
		//打开一首音乐，并取个别名，只要别名不同就可以同时播放
		sprintf(cmd, "open sound\\%c.mp3 alias s%d", c, i); //注意和printf函数类比
		mciSendString(cmd, NULL, 0, NULL);
		
		//播放别名对应的音乐
		sprintf(cmd, "play s%d", i); //注意和printf函数类比
		mciSendString(cmd, NULL, 0, NULL);
		
		i++; //保证每次打开音乐的别名都不一样
	}
	
	return 0;
}