#include <stdio.h>
#include <conio.h>   //getche�����ڴ�ͷ�ļ�������
#include <windows.h> //mciSendString�����ڴ�ͷ�ļ�������

//����mciSendString������Ҫ����winmm.lib������ļ�
#pragma comment(lib,"winmm.lib")


int main()
{
	char c;
	char cmd[100];
	int i = 0;
	
	//���ÿ���̨���ڱ���
	system("title ���Ӹ��� By:ITħ��");  //system�����Ĺ��ܣ�ִ��һ������
	system("color f4");  //���ÿ���̨����ǰ��ɫ�ͱ���ɫ������Ϊ��ɫǰ������ɫ����
	
	while(1)
	{
		//ͨ����������һ���ַ�
		//c = getchar();
		c = getche(); //��getchar�����Ĺ���һ���������������Ҫ���س���ȷ������
		
		//��һ�����֣���ȡ��������ֻҪ������ͬ�Ϳ���ͬʱ����
		sprintf(cmd, "open sound\\%c.mp3 alias s%d", c, i); //ע���printf�������
		mciSendString(cmd, NULL, 0, NULL);
		
		//���ű�����Ӧ������
		sprintf(cmd, "play s%d", i); //ע���printf�������
		mciSendString(cmd, NULL, 0, NULL);
		
		i++; //��֤ÿ�δ����ֵı�������һ��
	}
	
	return 0;
}