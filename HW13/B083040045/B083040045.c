#include <stdio.h>
#include <stdlib.h>
#include "B083040045.h"

void mysort(int a[],int n)
{
	int i,j,min,temp;
	for(i=0;i<n;i++)
	{
		min=a[i];
		temp=i;
		for(j=i;j<n;j++)
		{
			if(a[j]<min)
			{
				min=a[j];
				temp=j;
			}
		}
		a[temp]=a[i];
		a[i]=min;
	}
}

int myBinarySearch(int a[],int target,int h,int t)
{
	if(h==t)
	{
		if(a[h]==target)
			return h;
		else
			return -1;
	}	
	else if(h<t)
	{
		if(a[(h+t)/2]==target)
			return (h+t)/2;
		else if(a[(h+t)/2]>target)
		{
			t=(h+t)/2-1;
			myBinarySearch(a,target,h,t);
		}
		else
		{
			h=(h+t)/2+1;
			myBinarySearch(a,target,h,t);
		}
	}
	else
	{
		return -1;
	}
}
