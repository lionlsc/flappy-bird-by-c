//���easyx����flappy birdС��Ϸ//
//����ͼƬ�زĲ��㣬���ֻ�ܼ�¼9��//
//����ʱ��2018��1��10��//
//�����ˣ�lionlsc//
//����ͼƬ�������زľ���������//
//�������� vc6.0//
//Do not use it for commercial use//
#include<stdio.h>
#include<graphics.h>
#include<conio.h>                   //�ǻ�������//
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#pragma comment(lib,"Winmm.lib")  //����Winmm.lib�⺯�����������ֵĲ���//
int birdx,birdy,barrierdown,barriertop,barrierx,count,flag;
IMAGE bkphoto,bird1,bird2,barrierover1,barrierover2,barrierdown1,barrierdown2;
IMAGE score01,score02,score11,score12,score21,score22,score31,score32,score41,score42,score51,score52,score61,score62;
IMAGE score71,score72,score81,score82,score91,score92;
IMAGE birdfail1,birdfail2;
IMAGE gameover1,gameover2;            //����ͼƬ//
int temp;
void startup()                        //���ò���//
{
	initgraph(350,600);               //������Ϸ�����С//
    HWND hwnd = GetHWnd();
    SetWindowText(hwnd, "lionlsc����");
	flag=0;
	count=0;
	birdx=50;
	birdy=50;
	barrierx=350;
	barrierdown=-375;
	barriertop=340;
	loadimage(&bkphoto,"D:\\flappybird\\background.jpg"); 
	loadimage(&bird1,"D:\\flappybird\\bird1-2.jpg");
    loadimage(&bird2,"D:\\flappybird\\bird1-1.jpg");
	loadimage(&barrierover1,"D:\\flappybird\\stone_up1.jpg");
	loadimage(&barrierover2,"D:\\flappybird\\stone_up2.jpg");
	loadimage(&barrierdown1,"D:\\flappybird\\stone_down1.jpg");
    loadimage(&barrierdown2,"D:\\flappybird\\stone_down2.jpg");
	loadimage(&score01,"D:\\flappybird\\0_1.jpg");
    loadimage(&score02,"D:\\flappybird\\0_2.jpg");
	loadimage(&score11,"D:\\flappybird\\1_1.jpg");
    loadimage(&score12,"D:\\flappybird\\1_2.jpg");
    loadimage(&score21,"D:\\flappybird\\2_1.jpg");
    loadimage(&score22,"D:\\flappybird\\2_2.jpg");
    loadimage(&score31,"D:\\flappybird\\3_1.jpg");
    loadimage(&score32,"D:\\flappybird\\3_2.jpg");
    loadimage(&score41,"D:\\flappybird\\4_1.jpg");
    loadimage(&score42,"D:\\flappybird\\4_2.jpg");
    loadimage(&score51,"D:\\flappybird\\5_1.jpg");
    loadimage(&score52,"D:\\flappybird\\5_2.jpg");
    loadimage(&score61,"D:\\flappybird\\6_1.jpg");
    loadimage(&score62,"D:\\flappybird\\6_2.jpg");
    loadimage(&score71,"D:\\flappybird\\7_1.jpg");
    loadimage(&score72,"D:\\flappybird\\7_2.jpg");
    loadimage(&score81,"D:\\flappybird\\8_1.jpg");
    loadimage(&score82,"D:\\flappybird\\8_2.jpg");
    loadimage(&score91,"D:\\flappybird\\9_1.jpg");
    loadimage(&score92,"D:\\flappybird\\9_2.jpg");
    loadimage(&birdfail1,"D:\\flappybird\\bird4-1.jpg");
    loadimage(&birdfail2,"D:\\flappybird\\bird4-2.jpg");
    loadimage(&gameover1,"D:\\flappybird\\gameover1.jpg");
    loadimage(&gameover2,"D:\\flappybird\\gameover2.jpg");
	BeginBatchDraw();           //����������ͼ//
}
void show()                     //��ʾͼƬ//
{
	putimage(0,0,&bkphoto);
    putimage(barrierx,barrierdown,&barrierover2,NOTSRCERASE);
    putimage(barrierx,barrierdown,&barrierover1,SRCINVERT);
    putimage(barrierx,barriertop,&barrierdown2,NOTSRCERASE);
    putimage(barrierx,barriertop,&barrierdown1,SRCINVERT);
	if(count==0)
	{
 	  putimage(300,100,&score01,NOTSRCERASE);
	  putimage(300,100,&score02,SRCINVERT);
	}
	if(count==1)
	{
      putimage(300,100,&score11,NOTSRCERASE);
	  putimage(300,100,&score12,SRCINVERT);
	}
	if(count==2)
	{
      putimage(300,100,&score21,NOTSRCERASE);
	  putimage(300,100,&score22,SRCINVERT);
	}
    if(count==3)
	{
      putimage(300,100,&score31,NOTSRCERASE);
	  putimage(300,100,&score32,SRCINVERT);
	}
    if(count==4)
	{
      putimage(300,100,&score41,NOTSRCERASE);
	  putimage(300,100,&score42,SRCINVERT);
	}
    if(count==5)
	{
      putimage(300,100,&score51,NOTSRCERASE);
	  putimage(300,100,&score52,SRCINVERT);
	}
    if(count==6)
	{
      putimage(300,100,&score61,NOTSRCERASE);
	  putimage(300,100,&score62,SRCINVERT);
	}
    if(count==7)
	{
      putimage(300,100,&score71,NOTSRCERASE);
	  putimage(300,100,&score72,SRCINVERT);
	}
    if(count==8)
	{
      putimage(300,100,&score81,NOTSRCERASE);
	  putimage(300,100,&score82,SRCINVERT);
	}
    if(count==9)
	{
      putimage(300,100,&score91,NOTSRCERASE);
	  putimage(300,100,&score92,SRCINVERT);
	}
    if(flag==1)
	{
     putimage(birdx,birdy,&birdfail1,NOTSRCERASE);
     putimage(birdx,birdy,&birdfail2,SRCINVERT);
     putimage(79,280,&gameover1,NOTSRCERASE);
     putimage(79,280,&gameover2,SRCINVERT);
	 EndBatchDraw();                              //����������ͼ//
     mciSendString("close bkmusic",NULL,0,NULL);  //С����������Ϸ�������ر�����//
	 system("pause"); 
	 closegraph();
	}
	if(flag!=1)
	{
	putimage(birdx,birdy,&bird2,NOTSRCERASE);
	putimage(birdx,birdy,&bird1,SRCINVERT);
	}
	FlushBatchDraw();                     //����������ͼ//
}
void updatewithoutinput()                 //û���û�����ʱ�����²������������ӵ�λ��//
{
	
	srand(time(NULL));
	temp=rand()%99+1;
	birdy=birdy+20;
	if(barrierx>(-140))
	{
	barrierx=barrierx-10;
	}
	if(barrierx<=(-140))
	{
	barrierx=350;
    barrierdown=temp-425;
	barriertop=temp+280;
	}
	if(birdx==(barrierx+140)&&(birdy>barrierdown+600)&&(birdy<barriertop))
	{
		count++;
	}
	if(((birdx>=(barrierx-20))&&(birdx<=barrierx+140))&&((birdy>=barriertop-10)||(birdy<=barrierdown+625)))
	{
		birdy=birdy-20;
		flag=1;                                 //�ж�С���Ƿ�ͨ��������//
	}
	Sleep(135);
}
void updatewithinput()
{
	char ch;
	if(kbhit())
	{
		ch=getch();
		if(ch==' ')         //����Ұ��¿ո����С����Ծ//
		{
			birdy=birdy-50;
            mciSendString("close jpmusic",NULL,0,NULL);                               //����С����Ծʱ������//
            mciSendString("open D:\\flappybird\\jump.mp3 alias jpmusic",NULL,0,NULL);
            mciSendString("play jpmusic",NULL,0,NULL);
		}
	}

}
void main()
{
	 
   
    mciSendString("open D:\\flappybird\\background.mp3 alias bkmusic",NULL,0,NULL);  //���ű�������//
	mciSendString("play bkmusic repeat",NULL,0,NULL);
	startup();
	while(1)
	{
	show();
	updatewithoutinput();
	if(flag!=1)                         //��С��û��ͨ�����ӣ��û���������Ч//
	{
	updatewithinput();
	}
	}
}
