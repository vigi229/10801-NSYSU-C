#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//definition from exercise 2
#define square_2 1.41428
#define square_3 1.73205
int main(void)
{
	//Exercise 1
	int h1,m1,s1,h2,m2,s2,t1,t2,t3;
	char a;
	scanf("%d%c%d%c%d",&h1,&a,&m1,&a,&s1);
	scanf(" %d%c%d%c%d",&h2,&a,&m2,&a,&s2);

	t1=3600*h1+60*m1+s1;                    //換算為最小單位 s 
	t2=3600*h2+60*m2+s2;
	
	t3=t2-t1;
	
	h1=t3/3600;
	t3=t3%3600;
	
	m1=t3/60;
	t3=t3%60;
	
	s1=t3;
	
	printf("相差時間 %02d:%02d:%02d\n\n",h1,m1,s1);
	
	
	//Exercise 1
	float side,height;
	printf("邊長:");
	scanf("%f",&side);
	height=square_2*square_3*side/3;
	printf("高度:%.2f\n",height);
	printf("底面積:%.2f\n",pow(side,2)/4*square_3);
	printf("表面積:%.2f\n",pow(side,2)*square_3);
	printf("體積:%.2f\n",pow(side,2)*square_3*height/12);
	
	return 0;
}
