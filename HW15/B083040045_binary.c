#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	struct node *prev;
	int data;
	struct node *back;
};
struct node *first,*last;

void insert(int value)
{
	struct node *new,*current;
	new=malloc(sizeof(struct node));
	
	new->prev=new->back=NULL;
	new->data=value;
	
	if(last==NULL)
	{
		first=last=new;
	}
	else if(last->data>value)
	{
		new->prev=last;
		last->back=new; 
		last=new;
	}
	else if(first->data<value)
	{
		new->back=first;
		first->prev=new;
		first=new;
	}
	else if(first->data==value||last->data==value)
	{
		printf("Repeat!\n");
	}
	else
	{
		current=last;
		while(!(current->data<value&&current->prev->data>value))
		{
			if(current->data==value)
			{
				break;
			}
			current=current->prev;
		}
		if(current->data==value)
		{
			printf("Repeat!\n");
		}
		else
		{
			new->prev=current->prev;
			new->back=current;
			current->prev->back=new;
			current->prev=new;
		}
		
	}
	
}
struct node* Search(int value)
{
	struct node *current;
	if(current!=NULL)
	{
		current=last;
		while(!(current==NULL||current->data==value))
		{
			current=current->prev;
		}
	}
	return current;
}
int delete(int value)
{
	struct node *found;
	if((found=Search(value))==NULL)
	{
		return -1;
	}
	else
	{
		found->back->prev=found->prev;
		found->prev->back=found->back;
		free(found);
		return 0;
	}
}
void status()
{
	struct node *current;
	current=last;
	while(current!=NULL)
	{
		printf("%d ",current->data);
		current=current->prev;
	}
	printf("\n--------------------\n");
}
int main() 
{
	FILE* file=fopen("input.txt","r");
	int n,i,temp;
	char s[7],s1[]="insert",s2[]="delete";
	fscanf(file,"%d",&n);
	for(i=0;i<n;i++)
	{
		fscanf(file,"%d",&temp);
		insert(temp);
	}
	printf("Original :\n");
	status();
	while((fscanf(file,"%s",&s))!=EOF)
	{
		fscanf(file,"%d",&temp);
		if(strcmp(s,s1)==0)
		{
			insert(temp);
			printf("%s %d\n",s,temp);
			status();
		}
		if(strcmp(s,s2)==0)
		{
			printf("%s %d\n",s,temp);
			n=delete(temp);
			if(n==-1)
			{
				printf("Can not find it.\n");
			}
			status();
		}
	}
	fclose(file);
    return 0;
}


