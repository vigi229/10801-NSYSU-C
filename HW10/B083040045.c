#include <stdio.h>
#include <stdlib.h>
void myswap(int *x,int *y)
{
	int z;
	z=*x;
	*x=*y;
	*y=z;
}
int mysubtotal(int x,int y)
{
	if(x==y)
		return y;
	else
		return mysubtotal(x+1,y)+x;
}
int main() 
{
	int a,b;
	while((scanf("%d%d",&a,&b))!=EOF)
	{
		if(a>b)
			myswap(&a,&b);
		printf("%d到%d的總和為:%d\n",a,b,mysubtotal(a,b));	
	}	
    return 0;
}

