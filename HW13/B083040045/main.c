#include "B083040045.h"

int main(void) {
	FILE* file=fopen("input.txt","r");
	int a,count=0,find,target;
	fscanf(file,"%d",&count);
	int arr[count],i,head,tail;
	for(i=0;i<count;i++)
		fscanf(file,"%d",&arr[i]);
	fclose(file);
	
	mysort(arr,count);
	printf("Sorted finish.\nPlease input your target:");
	while((scanf("%d",&target))!=EOF)
	{
		head=0;
		tail=count-1;
		find=myBinarySearch(arr,target,head,tail);
		if(find==-1)
			printf("target not found.\n");
		else
			printf("target found at index %d.\n",find);
		printf("Please input your target:");
		
	}
	return 0;
}

