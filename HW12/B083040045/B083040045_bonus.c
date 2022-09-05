#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
	FILE* file=fopen("output1.txt","w");
	srand(time(NULL));
	
	fprintf(file,"Class A original\n\n");
	int i,j,temp,arr1[50],arr2[50];
	for(i=0;i<50;i++)
	{
		arr1[i]=rand()%101;
		fprintf(file,"%3d ",arr1[i]);
		if((i+1)%10==0)
			fprintf(file,"\n");
	}
	
	fprintf(file,"\nClass B original\n\n");
	for(i=0;i<50;i++)
	{
		arr2[i]=rand()%101;
		fprintf(file,"%3d ",arr2[i]);
		if((i+1)%10==0)
			fprintf(file,"\n");
	}
	
	for(i=1;i<50;i++)
	{
		temp=arr1[i];
		for(j=i;j>0&&arr1[j-1]>temp;j--)
		{
			arr1[j]=arr1[j-1];
		}
		arr1[j]=temp;
	}
	
	for(i=1;i<50;i++)
	{
		temp=arr2[i];
		for(j=i;j>0&&arr2[j-1]>temp;j--)
		{
			arr2[j]=arr2[j-1];
		}
		arr2[j]=temp;
	}
	
	fprintf(file,"\n");
	fprintf(file,"Class A sort\n\n");
	for(i=0;i<50;i++)
	{
		fprintf(file,"%3d ",arr1[i]);
		if((i+1)%10==0)
			fprintf(file,"\n");
	}
	
	fprintf(file,"\n");
	fprintf(file,"Class B sort\n\n");
	for(i=0;i<50;i++)
	{
		fprintf(file,"%3d ",arr2[i]);
		if((i+1)%10==0)
			fprintf(file,"\n");
	}
	fclose(file);
	
	file=fopen("output2.txt","w");
	fprintf(file,"Stem-and-leaf display Class A & Class B\n\n");
	fprintf(file,"              Class A     Class B\n");
	//21
	int count1[11]={0},count2[11]={0};
	for(i=0;i<50;i++)
	{
		switch(arr1[i]/10)
		{
			case 10:
				count1[10]++;
				break;
			case 9:
				count1[9]++;
				break;
			case 8:
				count1[8]++;
				break;
			case 7:
				count1[7]++;
				break;
			case 6:
				count1[6]++;
				break;
			case 5:
				count1[5]++;
				break;
			case 4:
				count1[4]++;
				break;
			case 3:
				count1[3]++;
				break;
			case 2:
				count1[2]++;
				break;
			case 1:
				count1[1]++;
				break;
			case 0:
				count1[0]++;
				break;
		}
		switch(arr2[i]/10)
		{
			case 10:
				count2[10]++;
				break;
			case 9:
				count2[9]++;
				break;
			case 8:
				count2[8]++;
				break;
			case 7:
				count2[7]++;
				break;
			case 6:
				count2[6]++;
				break;
			case 5:
				count2[5]++;
				break;
			case 4:
				count2[4]++;
				break;
			case 3:
				count2[3]++;
				break;
			case 2:
				count2[2]++;
				break;
			case 1:
				count2[1]++;
				break;
			case 0:
				count2[0]++;
				break;
		}
	}
	int temp1=50,temp2=49;
	for(i=10;i>=0;i--)
	{
		temp1=temp1-count1[i];
		for(j=0;j<21-count1[i];j++)
			fprintf(file," ");
		for(j=temp1;j<temp1+count1[i];j++)
		{
			fprintf(file,"%d",arr1[j]%10);
		}
		fprintf(file,"  %-3d",i);
		
		
		for(j=temp2;j>temp2-count2[i];j--)
		{
			fprintf(file,"%d",arr2[j]%10);
		}
		fprintf(file,"\n");
		temp2=temp2-count2[i];
	}
	
	
	int a[50],b[50],tmax=1,max=1;
	j=0;
	for(i=0;i<49;i++)
	{
		if(i==48)
		{
			if(arr1[i]==arr1[i+1])
				tmax++;
			if(tmax==max)
			{
				a[j]=arr1[i];
				j++;
			}
			else if(tmax>max)
			{
				j=0;
				max=tmax;
				a[j]=arr1[i];
				j++;
			}
		}
		else
		{
			if(arr1[i]==arr1[i+1])   //或讽狡计2a[0]纔舦ê或? 
				tmax++;
			else
			{
				if(tmax==max)
				{
					a[j]=arr1[i];
					j++;
				}
				else if(tmax>max)
				{
					j=0;
					max=tmax;
					a[j]=arr1[i];
					j++;
				}
				tmax=1;				//拜肈翴硂 
			}
		}
	}
	
	int k=0;
	max=1;							//癘眔﹍1(max&tmax) 
	tmax=1;
	for(i=0;i<49;i++)
	{
		if(i==48)
		{
			if(arr2[i]==arr2[i+1])
				tmax++;
			if(tmax==max)
			{
				b[k]=arr2[i];
				k++;
			}
			else if(tmax>max)
			{
				k=0;
				max=tmax;
				b[k]=arr2[i];
				k++;
			}
		}
		else
		{
			if(arr2[i]==arr2[i+1])   //或讽狡计2a[0]纔舦ê或? 
				tmax++;
			else
			{
				if(tmax==max)
				{
					b[k]=arr2[i];
					k++;
				}
				else if(tmax>max)
				{
					k=0;
					max=tmax;
					b[k]=arr2[i];
					k++;
				}
				tmax=1;				//拜肈翴硂 
			}
		}
	} 
	float t;
	t=(float)(arr1[24]+arr1[25])/2;
	if((int)t==(int)(t+0.5))
		fprintf(file,"\nmedian A : %d\nmode   A : ",(int)t);
	else
		fprintf(file,"\nmedian A : %.1f\nmode   A : ",t);
	for(i=0;i<j;i++)
	{
		fprintf(file,"%d ",a[i]);
	}
	
	t=(float)(arr2[24]+arr2[25])/2;
	if((int)t==(int)(t+0.5))
		fprintf(file,"\n\nmedian B : %d\nmode   B : ",(int)t);
	else
		fprintf(file,"\nmedian B : %.1f\nmode   B : ",t);
	for(i=0;i<k;i++)
	{
		fprintf(file,"%d ",b[i]);
	}
	fclose(file);
    return 0;
}


