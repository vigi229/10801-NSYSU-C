#include <stdio.h>
#include <stdlib.h>

void status(int front ,int last ,int arr[] )
{
	int i;
	printf("Queue :");
	if((front!=last&&arr[front]!=-1)||(last==front&&arr[front]!=-1))
	{
		if(front>last)
		{
			last=last+10;
			for(i=front;i<=last;i++)
			{
				if(i>9)
				{
					printf("%d ",arr[i-10]);
				}
				else
				{
					printf("%d ",arr[i]);
				}
			}
		}
		else
		{
			for(i=front;i<=last;i++)
			{
				printf("%d ",arr[i]);
			}
		}
	}
	printf("\n--------------------------------\n");
}
 
int main(void) {
	FILE *file=fopen("input.txt","r");
	int n,i,temp,arr[10],front,back;
	char s[8];
	fscanf(file,"%d",&n);
	front=0;
	for(i=0;i<n;i++)
	{
		fscanf(file,"%d",&arr[i]);
		back=i;
	}
	printf("Insert the original numbers.\n\n");
	status(front,back,arr);
	while((fscanf(file,"%s",&s))!=EOF)
	{
		if(s[0]=='D')
		{
			if(front==back&&arr[front]==-1)
			{
				printf("%s\n",s);
				printf("Nothing in queue.\n");
				status(front,back,arr);
			}
			else
			{
				printf("%s\n",s);
				printf("%s %d from queue.\n",s,arr[front]);
				arr[front]=-1;
				if(front!=back)
				{
					front++;
				}
				if(front>9)
					front=front-10;
				status(front,back,arr);
			}
			
		}
		if(s[0]=='E')
		{
			fscanf(file,"%d",&temp);
			if((front!=back&&arr[front]!=-1)||(back==front&&arr[front]!=-1))
			{
				back++;
				if(back>9)
					back=back-10;	
			}
			arr[back]=temp;
			printf("%s %d\n",s,temp);
			printf("%s %d into queue.\n",s,temp);
			status(front,back,arr);
		}
	}
	fclose(file);
	return 0;
}
