#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
	
	//Exercise 1
	int ans,test,max=500,min=0,count=0;
	printf("�п�J����(�d��:0~500):\n");
	scanf("%d",&ans);

	printf("\n\n�q�@�ӼƦr\n");	
	scanf("%d",&test);

	while(ans!=test)
	{
		count+=1;
		if(test>=min&&test<=max)
		{
			if(test>ans)
			{
				max=test;
				printf("�d�� %d �� %d\n�q�@�ӼƦr\n",min,max);
				scanf("%d",&test);
			}
			else
			{
				min=test;
				printf("�d�� %d �� %d\n�q�@�ӼƦr\n",min,max);
				scanf("%d",&test);
			}
		}
		else
		{
			printf("�d�� %d �� %d\n�q�@�ӼƦr\n",min,max);
			scanf("%d",&test);
		}
	
	}
	count=count+1;
	printf("���߲q��!!\n�A�q�F %d ��\n\n",count);

	
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
