#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *prev;
}*front,*last;

//struct node *front,*last;

void myenqueue(int value)
{
	struct node *new;
	new=malloc(sizeof(struct node));
	
	new->data=value;
	new->prev=NULL;
	
	if(front==NULL)
	{
		front=new;
	}
	new->prev=last;
	last=new;
}

int mydequeue()
{
	int value;
	struct node *temp,*current;
	temp=front;
	if(front==NULL)
	{
		return -1;
	}
	else if(front==last)
	{
		front=last=NULL;
	}
	else
	{
		current=last;
		while(current->prev!=front)
		{
			current=current->prev;
		}
		front=current;
	}
	value=temp->data;
	free(temp);
	return value;
}

void status()
{
	printf("Queue :");
	struct node *point,*current;
	if(front!=NULL)
	{
		point=front;
		while(point!=last)
		{
			current=last;
			while(current->prev!=point)
			{
				current=current->prev;
			}
			printf("%d ",point->data);
			point=current;
		}
		printf("%d",point->data);
	}
	printf("\n--------------------------------\n");
}
int travercial()
{
	int count=1;
	struct node *point;
	point=last;
	if(last!=NULL)
	{
		point=last;
		while(point!=front)
		{
			count++;
			point=point->prev;
		}
	}
	return count;
}
int main(void) {
	FILE *file=fopen("input.txt","r");
	int n,i,temp,count;
	char s[8];
	fscanf(file,"%d",&n);
	printf("Insert the original numbers.\n\n");
	for(i=0;i<n;i++)
	{
		fscanf(file,"%d",&temp);
		myenqueue(temp);
	}
	status();
	count=travercial();
	printf("%d\n",count);
	while((fscanf(file,"%s",&s))!=EOF)
	{
		if(s[0]=='D')								//include string strcmp 回傳數字  0 一樣 
		{
			temp=mydequeue();
			printf("%s\n\n",s);
			if(temp==-1)
			{
				printf("Nothing in queue.\n\n");
			}
			else
			{
				printf("%s %d from queue.\n\n",s,temp);
			}
			status();
			count=travercial();
			printf("%d\n",count);
		}
		if(s[0]=='E')
		{
			fscanf(file,"%d",&temp);
			myenqueue(temp);
			printf("%s %d\n\n",s,temp);
			printf("%s %d into queue.\n\n",s,temp);
			status();
			count=travercial();
			printf("%d\n",count);
		}
	}
	printf("Finish total input.\n");
	fclose(file);
	return 0;
}
