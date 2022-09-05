#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double a,b,c,d;
int bo=0;

int Range(float a,float b,float c,float d);
void Graph(float a,float b,float c,float d,int min,int max);
void Differential(int p);
void integral(int x1,int x2);

int main() 
{
	system("color a");
	int p,x1,x2,min,max;
	
	printf("輸入X的第3次方係數:");
	scanf("%lf",&a);
    printf("輸入X的第2次方係數:");
	scanf("%lf",&b);
	printf("輸入X的第1次方係數:");
	scanf("%lf",&c);
	printf("輸入X的第0次方係數:");
	scanf("%lf",&d);
	if(bo==0)
	{
		min=Range(a,b,c,d);
		bo=1;
	}
	if(bo==1)
		max=Range(a,b,c,d);
	printf("x軸的動態範圍為 %d~%d\n",min,max);

	printf("請輸入所求切點的X座標值:");
	scanf("%d",&p);
	
	printf("請輸入x的區間x1、x2:");
	scanf("%d%d",&x1,&x2);
		
	Differential(p);
	integral(x1,x2);
	Graph(a,b,c,d,min,max);
    return 0;
}

int Range(float a,float b,float c,float d)
{
	int i,d1y,d2y,dx1,dx2,min,max;
	double f2x,f1y,f2y,f1x;
	for(i=-100;i<=100;i++)
	{
		f2x=3*a*i*i+2*b*i+c;
		f1x=3*a*pow(i+1,2)+2*b*(i+1)+c;
		if((int)(f2x+0.5)==0||f1x*f2x<0)
		{
			dx1=i;
			f1y=a*pow(i,3)+b*pow(i,2)+c*i+d; 
			d1y=(int)(f1y+0.5);
			break;
		}
	}
	for(i=100;i>=-100;i--)
	{
		
		f2x=3*a*i*i+2*b*i+c;
		f1x=3*a*pow(i+1,2)+2*b*(i+1)+c;
		if((int)(f2x+0.5)==0||f1x*f2x<0)
		{
			dx2=i;
			f1y=a*pow(i,3)+b*pow(i,2)+c*i+d; 
			d2y=(int)(f1y+0.5);
			break;
		}
	}
	if(d1y*d2y<=0)
	{
		for(i=-100;i<=dx1;i++)
		{
			f1y=a*pow(i,3)+b*pow(i,2)+c*i+d;
			f2y=a*pow(i+1,3)+b*pow(i+1,2)+c*i+d;
			if((int)(f1y+0.5)==0||f1y*f2y<0) 
			{
				dx1=i;
			}
		}
		for(i=100;i>=dx2;i--)
		{
			f1y=a*pow(i,3)+b*pow(i,2)+c*i+d;
			f2y=a*pow(i+1,3)+b*pow(i+1,2)+c*i+d;
			if((int)(f1y+0.5)==0||f1y*f2y<0) 
			{
				dx2=i;
			}
		}
	}
	else
	{
		if((d1y>0&&a>0)||(d1y<0&&a<0))
		{
			for(i=-100;i<dx1;i++)
			{
				f1y=a*pow(i,3)+b*pow(i,2)+c*i+d;
				f2y=a*pow(i+1,3)+b*pow(i+1,2)+c*i+d;
				if((int)(f1y+0.5)==0||f1y*f2y<0) 
				{
					dx1=i;
				}
			}
		}
		else
		{
			for(i=100;i>dx2;i--)
			{
				f1y=a*pow(i,3)+b*pow(i,2)+c*i+d;
				f2y=a*pow(i+1,3)+b*pow(i+1,2)+c*i+d;
				if((int)(f1y+0.5)==0||f1y*f2y<0) 
				{
					dx2=i;
				}
			}
		}
	}
	if(dx1<=0)
	{
		i=dx1/10;
		min=i*10-10;
	}
	else
	{
		i=dx1/10;
		min=i*10;
	}
	if(dx2<=0)
	{
		i=dx2/10;
		max=i*10;
	}
	else
	{
		i=dx2/10;
		max=i*10+10;
	}
	if(bo==0)
		return min;
	else
		return max;
}

void Differential(int p)
{
	float dy;
	dy=3*a*pow(p,2)+2*b*p+c;
	printf("該點斜率為: %f\n",dy);
}

void integral(int x1,int x2)
{
	float Fy;
	Fy=a*(pow(x2,4)-pow(x1,4))/4+b*(pow(x2,3)-pow(x1,3))/3+c*(pow(x2,2)-pow(x1,2))/2+d*(x2-x1);
	printf("該區域定積分為: %f\n\n",Fy);
}

void Graph(float a,float b,float c,float d,int min,int max)
{
	int x,y,ans;
	float answer;
	for(x=min;x<=max+3;x++)
	{
		answer=a*pow(x,3)+b*pow(x,2)+c*x+d;
		ans=(int)(answer+0.5);
		for(y=-60;y<=65;y++)
		{
			if(x<=max&&y<60)
			{
				if(y==0)
				{
					if(x%10==0&&x<0)
						printf("-");
					else if(x%10==0&&x>=0)
						printf("%d",x/10);
					else if((y/2)==ans&&y%2==0)
						printf("*");
					else
						printf("|");
				}	
				else if(y==1)
				{
					if(x%10==0&&x<0)
						printf("%d",-x/10);
					else if(x%10==0&&x>0)
						printf("0");
					else if((y/2)==ans&&y%2==0)
						printf("*");
					else
						printf(" ");
				}
				else if(y==2)
				{
					if(x%10==0&&x<0)
						printf("0");
					else if((y/2)==ans&&y%2==0)
						printf("*");
					else if(x==0)
						printf("-");
					else
						printf(" ");
				}
				else if(x==-1)
				{
					if(y==-60||y==-59||y==-58)
					{
						if((y/2)==ans&&y%2==0)
							printf("*");
						else
							printf(" ");
					}
					else
					{
						if((y%20==0&&y<0))
							printf("-");
						else if(y%20==0&&y>0)
							printf("%d",y/20);
						else if(-y%20==19&&y<0)
							printf("%d",(-y+1)/20);
						else if((y%20==1&&y>0)||(-y%20==18&&y<0))
							printf("0");
						else if((y/2)==ans&&y%2==0)
							printf("*");
						else
							printf(" ");	
					}	
				}
				else if(x==0)
				{
					if(y%20==0)
						printf("|");
					else if((y/2)==ans&&y%2==0)
						printf("*");
					else
						printf("-");
					
				}
				else if((y/2)==ans&&y%2==0)
					printf("*");
				else
					printf(" ");
			}
			else
			{
				if(x==max+2&&y==0)
					printf("V");
				else if(x==max+3&&y==0)
					printf("X");
				else if((x==max+3&&y==1)||(x==0&&y==65)) 
					printf("軸");
				else if(x==0&&y==64)
					printf("Y");
				else if(x==0&&y==60)
					printf(">");
				else if(x==max+1&&y==0)
					printf("|"); 
				else
					printf(" ");
			}
		}
		printf("\n");
	}
}

