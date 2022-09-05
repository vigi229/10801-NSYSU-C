#include <stdio.h>
#include <stdlib.h>


int main() 
{
	int y,m,w,d,i,j;
	printf("Input:");
	scanf("%4d",&y);
	scanf("%2d",&m);
	scanf("%d",&w);
	while(1)
	{
		if(m>12||m<1||w>6||w<0)
		{
			printf("Input:");
			scanf("%4d",&y);
			scanf("%2d",&m);
			scanf("%d",&w);
			continue;
		}
		else
		{
			switch(m)
			{
				case 1:
					printf("                      January, %d\n  SUN  MON  TUE  WED  THU  FRI  SAT\n",y);
					d=31;
					break;
				case 2:
					printf("                     February, %d\n  SUN  MON  TUE  WED  THU  FRI  SAT\n",y);
					if((y%4==0&&y%100!=0)||(y%400==0&&y%3200!=0))
						d=29;
					else
						d=28;
					break;
				case 3:
					printf("                        March, %d\n  SUN  MON  TUE  WED  THU  FRI  SAT\n",y);
					d=31;
					break;
				case 4:
					printf("                        April, %d\n  SUN  MON  TUE  WED  THU  FRI  SAT\n",y);
					d=30;
					break;
				case 5:
					printf("                          May, %d\n  SUN  MON  TUE  WED  THU  FRI  SAT\n",y);
					d=31;
					break;
				case 6:
					printf("                         June, %d\n  SUN  MON  TUE  WED  THU  FRI  SAT\n",y);
					d=30;
					break;
				case 7:
					printf("                         July, %d\n  SUN  MON  TUE  WED  THU  FRI  SAT\n",y);
					d=31;
					break;
				case 8:
					printf("                       August, %d\n  SUN  MON  TUE  WED  THU  FRI  SAT\n",y);
					d=31;
					break;
				case 9:
					printf("                    September, %d\n  SUN  MON  TUE  WED  THU  FRI  SAT\n",y);
					d=30;
					break;
				case 10:
					printf("                      October, %d\n  SUN  MON  TUE  WED  THU  FRI  SAT\n",y);
					d=31;
					break;
				case 11:
					printf("                     November, %d\n  SUN  MON  TUE  WED  THU  FRI  SAT\n",y);
					d=30;
					break;
				case 12:
					printf("                     December, %d\n  SUN  MON  TUE  WED  THU  FRI  SAT\n",y);
					d=31;
					break;
			}
			j=1;
			i=0;
			while(j<=d)
			{
				printf("  ");
				if(w>0)
				{
					printf("   ");
					w--;	
				}
				else
				{
					if(j>=10)
					{
						printf(" %d",j);
						j++;
					}
					else
					{
						printf("  %d",j);
						j++;
					}
				}
				i++;
				if(i==7)
				{
					printf("\n");
					i=0;
				}
			}
			printf("\nInput:");
			scanf("%4d",&y);
			scanf("%2d",&m);
			scanf("%d",&w);
			
		}
	}
	
	
	

    return 0;
}


