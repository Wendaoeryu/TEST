#include<stdio.h>
#include<stdlib.h>
#include<easyx.h>
#include<time.h>
#define STR_SIZE 20//每条多少个字符
#define STR_NUM 128//多少条
#define STR_WIDTH 15//字符宽度15像素

struct Rain
{
	int x;//坐标xy
	int y;
	char str[STR_SIZE];
	int speed;
};
Rain rain[STR_NUM];
char CreateChar()//生成随机的单个字符
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
	srand(time(NULL));//NULL是一个宏用于表示空指针不能小写
	for (int i = 0; i < STR_NUM; ++i)
	{
		rain[i].x = getwidth() * i;
		rain[i].y = rand() % getheight();
		rain[i].speed = rand() % 5 + 5;

		for (int j = 0; j < STR_SIZE; ++j)//每一条里面的字符实现随机
		{
			rain[i].str[j] = CreateChar();
		}

	}


}
void draw()
{
	BeginBatchDraw();//开启双缓冲绘图防止闪烁
	cleardevice();//清除旧的字符雨
	setbkmode(0);//去除背景色
	for (int i = 0; i < STR_NUM; ++i)
	{
		for (int j = 0; j < STR_SIZE; ++j)
		{
			outtextxy(rain[i].x, rain[i].y - STR_WIDTH * j, rain[i].str[j]);//显示字符，字符从上往下排列
			settextcolor(RGB(0, 255 - 13 * j, 0));//设置字符颜色，颜色从淡到亮
		}
	}
	EndBatchDraw();//关闭双缓冲
}
int main()
{
	//创建窗口
	initgraph(960, 640);
	//数据初始化
	init();


	//主循环
	while (true)
	{
		//绘制字符
		draw();
		//修改字符

		//字符下落
	}

	while (true)
	{

	}

	return 0;
}