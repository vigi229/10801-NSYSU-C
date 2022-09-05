#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
	//Exercise 1
	int time;
	printf("Time (minutes):");
	scanf("%d",&time);
	if(time>0)
	{
		if(time%60<=10)
		{
			switch(time/60)
			{
			case 0:
				printf("The parking fee is 0 dollar(s).\n\n");
				break;
			case 1:
				printf("The parking fee is 100 dollar(s).\n\n");
				break;
			case 2:
				printf("The parking fee is 170 dollar(s).\n\n");
				break;
			case 3:
				printf("The parking fee is 220 dollar(s).\n\n");
				break;
			default:
				printf("The parking fee is %d dollar(s).\n\n",220+20*(time/60-3));
				break;
			}
		}
		else
		{
			switch(time/60)
			{
			case 0:
				printf("The parking fee is 100 dollar(s).\n\n");
				break;
			case 1:
				printf("The parking fee is 170 dollar(s).\n\n");
				break;
			case 2:
				printf("The parking fee is 220 dollar(s).\n\n");
				break;
			default:
				printf("The parking fee is %d dollar(s).\n\n",220+20*(time/60-2));
				break;
			}
		}
	}
	else
		printf("Error!\n\n");
		
		
	//Exercise 2
	int year,month,day;
	scanf("%d %d %d",&year,&month,&day);
	
	if(month>12||month<1)
	{
		printf("Error!");	
	}
	else
	{
		if((year%4==0&&year%100!=0)||(year%400==0&&year%3200!=0))
		{
		printf("It's leap year\n");
		switch(month)
		{
			case 12:
				day+=30;
			case 11:
				day+=31;
			case 10:
				day+=30;
			case 9:
				day+=31;
			case 8:
				day+=31;
			case 7:
				day+=30;
			case 6:
				day+=31;
			case 5:
				day+=30;
			case 4:
				day+=31;
			case 3:
				day+=29;
			case 2:
				day+=31;
				break;
		}
	}
	else
	{
		printf("It's common year\n");
		switch(month)
		{
			case 12:
				day+=30;
			case 11:
				day+=31;
			case 10:
				day+=30;
			case 9:
				day+=31;
			case 8:
				day+=31;
			case 7:
				day+=30;
			case 6:
				day+=31;
			case 5:
				day+=30;
			case 4:
				day+=31;
			case 3:
				day+=28;
			case 2:
				day+=31;
				break;
		}
	}
	printf("It's the %dth day in %d.'",day,year);
	}
	
	return 0;
}
