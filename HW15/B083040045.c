#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
//由小到大 
struct node {
	int data;
	struct node *prev;
};
struct node *last;
void myinsert(int value)
{
	struct node *new,*current;
	new=malloc(sizeof(struct node));
	
	new->data=value;
	new->prev=NULL;
	
	if(last==NULL)
	{
		last=new;
	}
	else if(last->data>value)
	{
		new->prev=last;
		last=new;
	}
	else
	{
		current=last;
		while(!((current->prev==NULL)||(current->data<value&&current->prev->data>value)))
		{
			if(current->data==value)
			{
				break;
			}
			current=current->prev;
		}
		if(current->data==value)//優先側這個 
		{
			printf("number %d is in list already.\n",value);
			free(new);
		}
		else if(current->prev==NULL)
		{
			current->prev=new;
		}
		else 
		{
			new->prev=current->prev;
			current->prev=new;
		}
	}
} 

struct node* Search(int value)
{
	struct node *current;
	current=last;
	while(!((current==NULL)||(current->data==value)))
	{
		current=current->prev;
	}
	return current;
	
}
int mydelete(int value)
{
	struct node *current,*found;
	if((found=Search(value))==NULL)
	{
		return -1;
	}
	else
	{
		current=last;
		while(current->prev!=found)
		{
			current=current->prev;
		}
		current->prev=found->prev;
		free(found);
		return 0;
	}
}

void status()
{
	struct node *point;
	point=last;
	printf("list:");
	if(last!=NULL)
	{
		while(point!=NULL)
		{
			printf("%d ",point->data);
			point=point->prev;
		}
	}
	printf("\n--------------------\n");
}

int main(void) {
	FILE *file=fopen("input.txt","r");
	int n,i,temp;
	char s[7],s1[]="insert",s2[]="delete";
	fscanf(file,"%d",&n);
	printf("Insert the original numbers.\n");
	for(i=0;i<n;i++)
	{
		fscanf(file,"%d",&temp);
		myinsert(temp);
	}
	status();
	while((fscanf(file,"%s",&s))!=EOF)
	{
		fscanf(file,"%d",&temp);
		if(strcmp(s,s1)==0)
		{
			printf("Insert %d.\n",temp);
			myinsert(temp);
			status(); 
		}
		if(strcmp(s,s2)==0)
		{
			printf("Delete %d.\n",temp);
			n=mydelete(temp);
			if(n==-1)
			{
				printf("number %d is not in list.\n",temp);
			}
			status();
		}
	}
	printf("Finish total input.\n");
	fclose(file);
	return 0;
}
