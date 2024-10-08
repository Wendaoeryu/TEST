#include<stdio.h>
#include<stdlib.h>
#include<easyx.h>
#include<time.h>
#define STR_SIZE 20//ÿ�����ٸ��ַ�
#define STR_NUM 128//������
#define STR_WIDTH 15//�ַ����15����

struct Rain
{
	int x;//����xy
	int y;
	char str[STR_SIZE];
	int speed;
};
Rain rain[STR_NUM];
char CreateChar()//��������ĵ����ַ�
{
	char c;
	int t = rand() % 3;
	switch (t)
	{
	case 0:
		c = '0' + rand() % 10;
		break;
	case 1:
		c = 'a' + rand() % 26;
		break;
	case 2:
		c = 'A' + rand() % 26;
		break;
	default:
		break;
	}
	return c;
}
void init()
{
	srand(time(NULL));//NULL��һ�������ڱ�ʾ��ָ�벻��Сд
	for (int i = 0; i < STR_NUM; ++i)
	{
		rain[i].x = getwidth() * i;
		rain[i].y = rand() % getheight();
		rain[i].speed = rand() % 5 + 5;

		for (int j = 0; j < STR_SIZE; ++j)//ÿһ��������ַ�ʵ�����
		{
			rain[i].str[j] = CreateChar();
		}

	}


}
void draw()
{
	BeginBatchDraw();//����˫�����ͼ��ֹ��˸
	cleardevice();//����ɵ��ַ���
	setbkmode(0);//ȥ������ɫ
	for (int i = 0; i < STR_NUM; ++i)
	{
		for (int j = 0; j < STR_SIZE; ++j)
		{
			outtextxy(rain[i].x, rain[i].y - STR_WIDTH * j, rain[i].str[j]);//��ʾ�ַ����ַ�������������
			settextcolor(RGB(0, 255 - 13 * j, 0));//�����ַ���ɫ����ɫ�ӵ�����
		}
	}
	EndBatchDraw();//�ر�˫����
}
int main()
{
	//��������
	initgraph(960, 640);
	//���ݳ�ʼ��
	init();


	//��ѭ��
	while (true)
	{
		//�����ַ�
		draw();
		//�޸��ַ�

		//�ַ�����
	}

	while (true)
	{

	}

	return 0;
}