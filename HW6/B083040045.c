#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 


int main(void)

{

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN );

    char arr[65][120];
    
	int x1,y1,n,i;
    
	for(y1=0;y1<65;y1++)
	{
		for(x1=0;x1<120;x1++)
		{
			arr[y1][x1]=' ';
		}
	}
	
	for(x1=0;x1<120;x1++)
	{
		if(x1%20==0)
			arr[20][x1]='|';
		else
			arr[20][x1]='-';
	}
	
	for(y1=0;y1<65;y1++)
	{
		if(y1%10==0)
			arr[y1][60]='-';
		else
			arr[y1][60]='|';		
	}
	arr[19][19]='-';
	arr[19][20]='2';
	arr[19][21]='0';
	arr[19][39]='-';
	arr[19][40]='1';
	arr[19][41]='0';
	arr[19][59]='0';
	arr[19][79]='1';
	arr[19][80]='0';
	arr[19][99]='2';
	arr[19][100]='0';
	arr[20][119]='>';
	arr[21][116]='X';
	
	arr[0][61]='2';
	arr[0][62]='0';
	arr[10][61]='1';
	arr[10][62]='0';
	arr[20][60]='0';
	arr[30][60]='1';
	arr[30][61]='0';
	arr[40][60]='2';
	arr[40][61]='0';
	arr[50][60]='3';
	arr[50][61]='0';
	arr[60][60]='4';
	arr[60][61]='0';
	arr[63][62]='Y';

	printf("請輸入多項式的最高次方數:");
	scanf("%d",&n);
	float arr1[n+1];
	
	for(i=n;i>=0;i--)
	{
		printf("輸入x的%d次方的係數:",i);
		scanf("%f",&arr1[i]);
	}
	double fy,fx;
	for(x1=0;x1<120;x1++)
	{
		fx=((float)x1-60)/2;                //運算要換成相同型態 
		fy=0;
		for(i=0;i<=n;i++)
		{
			fy=fy+arr1[i]*pow(fx,i);
		}
		if(fy>=-20&&fy<=40)
		{
			arr[(int)(fy+0.5)+20][x1]='*';
		}
	}
	
	for(y1=0;y1<65;y1++)
	{
		for(x1=0;x1<120;x1++)
		{
			if((x1==63&&y1==63)||(x1==117&&y1==21))
				printf("軸");
			else
				printf("%c",arr[y1][x1]);
		}
		printf("\n");
	}
	
    return 0;

}
