#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
int bubble_sort(int*,int,int*);
int selection_sort(int*,int,int*);
int insertion_sort(int*,int,int*);
int main() 
{
	FILE *file=fopen("input.txt","r");
	int i,j,n;
	unsigned int compare_bubble,swap_bubble,compare_selection,swap_selection,compare_insertion,swap_insertion;
	FILE *fb=fopen("B083040045_bubble.txt","w");
	FILE *fs=fopen("B083040045_selection.txt","w");
	FILE *fi=fopen("B083040045_insertion.txt","w");
	fprintf(fb,"Bubble sort result:\n");
	fprintf(fs,"Selection sort result:\n");
	fprintf(fi,"Insertion sort result:\n");
	for(i=1;i<4;i++)
	{
		//clock_t start,finish;
		//start=clock();
		printf("Sequence %d      bubble          selection       insertion   \n",i);
		printf("------------------------------------------------------------\n");
		if(i==1)
			n=500;
		else if(i==2)
			n=1000;
		else
			n=2000;
		
		int arr[n],arr1[n];	
		for(j=0;j<n;j++)
		{
			fscanf(file,"%d",&arr[j]);
		}
		
		for(j=0;j<n;j++)
		{
			arr1[j]=arr[j];
		}
		swap_bubble=bubble_sort(arr1,n,&compare_bubble);
		for(j=0;j<n;j++)
		{
			fprintf(fb,"%d ",arr1[j]);
		}
		fprintf(fb,"\n\n");
			
		for(j=0;j<n;j++)
		{
			arr1[j]=arr[j];
		}
		swap_selection=selection_sort(arr1,n,&compare_selection);
		for(j=0;j<n;j++)
		{
			fprintf(fs,"%d ",arr1[j]);
		}
		fprintf(fs,"\n\n");
			
		for(j=0;j<n;j++)
		{
			arr1[j]=arr[j];
		}
		swap_insertion=insertion_sort(arr1,n,&compare_insertion);
		for(j=0;j<n;j++)
		{
			fprintf(fi,"%d ",arr1[j]);
		}
		fprintf(fi,"\n\n");	
		//finish=clock();
		printf("swap times      %-7u         %-7u         %-7u        \n",swap_bubble,swap_selection,swap_insertion);
		printf("compare times   %-7u         %-7u         %-7u        \n",compare_bubble,compare_selection,compare_insertion);
		printf("------------------------------------------------------------\n");
		//printf("%lf \n",(double)(finish-start) / CLOCKS_PER_SEC);	
	}
	fclose(fb);
	fclose(fs);
	fclose(fi);
	fclose(file);
    return 0;
}

int bubble_sort(int *a,int n,int *compare)
{
	int i,j,k,swap=0;
	*compare=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			*compare=*compare+1;					 //*compare++ 礚   纔舦拜肈 (compare++纔*┪单基) 
			if(a[j]>a[j+1])
			{
				k=a[j];
				a[j]=a[j+1];
				a[j+1]=k;
				swap++;
			}
		}
	}
	return swap;
}

int selection_sort(int *a,int n,int *compare)
{
	int i,j,k,min,swap=0;
	*compare=0;
	for(i=0;i<n-1;i++)
	{
		min=a[i];
		for(j=i+1;j<n;j++)
		{
			*compare=*compare+1;						 //*compare++ 礚   纔舦拜肈 (compare++纔*┪单基) 
			if(min>a[j])
			{
				min=a[j];
				k=j;
			}
		}
		a[k]=a[i];
		a[i]=min;
		swap++;
	}
	return swap;
}

int insertion_sort(int *a,int n,int *compare)
{
	int i,j,k,min,swap=0;
	*compare=0;
	for(i=1;i<n;i++)
	{
		min=a[i];
		for(j=i;j>0&&a[j-1]>min;j--)
		{
			*compare=*compare+1;                         //*compare++ 礚  纔舦拜肈 (compare++纔*┪单基) эΘ(*compare)++ 
			a[j]=a[j-1];
			//swap++;
		}
		a[j]=min;
		swap++;
	}
	return swap;
}
