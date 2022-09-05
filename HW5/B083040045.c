#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
	
	//Exercise 1
	int ans,test,max=500,min=0,count=0;
	printf("請輸入答案(範圍:0~500):\n");
	scanf("%d",&ans);

	printf("\n\n猜一個數字\n");	
	scanf("%d",&test);

	while(ans!=test)
	{
		count+=1;
		if(test>=min&&test<=max)
		{
			if(test>ans)
			{
				max=test;
				printf("範圍 %d 到 %d\n猜一個數字\n",min,max);
				scanf("%d",&test);
			}
			else
			{
				min=test;
				printf("範圍 %d 到 %d\n猜一個數字\n",min,max);
				scanf("%d",&test);
			}
		}
		else
		{
			printf("範圍 %d 到 %d\n猜一個數字\n",min,max);
			scanf("%d",&test);
		}
	
	}
	count=count+1;
	printf("恭喜猜對!!\n你猜了 %d 次\n\n",count);

	
	//Exercise 2
	int m,n,i;
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		double ans1=1;
		//if(m-n>=n)
		//{
			for(i=1;i<=n;i++)
			{
				ans1=ans1*(m-i+1)/i;
			}
			printf("C(%d, %d) = %d\n",m,n,(int)ans1);
		//}
		//else
		//{
		//	for(i=1;i<=m-n;i++)
		//	{
		//		ans1=ans1*(m-i+1)/i;
		//	}
		//	printf("C(%d, %d) = %d\n",m,n,(int)ans1);
		//}
	}
	
	return 0;
}
