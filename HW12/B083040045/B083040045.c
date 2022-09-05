#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};
struct node *top;
void mypush(int value)
{
	struct node *new;
	new=malloc(sizeof(struct node));
	
	new->data=value;
	new->next=NULL;
	
	new->next=top;
	top=new;
}
int mypop()
{
	if(top==NULL)
	{
		return -1;
	}
	else
	{
		int n;
		struct node *new;
		n=top->data;
		new=top;
		top=new->next;
		free(new);
		return n;
	}
}
void status()
{
	struct node *point;
	point=top;
	while(point!=NULL)
	{
		printf("*       *\n");
		printf("*%5d  *\n",point->data);
		printf("*       *\n");
		printf("*********\n");
		point=point->next;
	}
}
int travercial()
{
	int count=0;
	struct node *point;
	point=top;
	while(point!=NULL)
	{
		count++;
		point=point->next;
	}
	return count;
}
int main() 
{
	int in,input,test,count;
	printf("Nothing in stack.\nPlease input the instruction:");
	while((scanf("%d",&in))!=EOF)
	{
		if(in==1)
		{
			scanf("%d",&input);
			printf("push %d into stack.\n",input);
			mypush(input);
			status();
		}
		else
		{
			test=mypop();
			if(test==-1)
			{
				printf("Error pop.\nNothing in stack.\n");
			}
			else
			{
				printf("pop %d from stack.\n",test);
				status();
			}
		}
		count=travercial();
		printf("%d\n",count);
		printf("Please input the instruction:");
	}
	
    return 0;
}



