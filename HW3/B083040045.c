#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
	//Exercise 1
	int a,b,c,d;
	printf("��J�|���:");
	scanf("%d %d %d %d",&a,&b,&c,&d);
	
	if(a==b&&b==c&&c==d)
		printf("�٧�\n\n");
	else if(a==c&&b==d&&a!=b) 
		printf("����|���\n\n");
	else if(a+b+c>d&&a+c+d>b&&b+c+d>a&&a+b+d>c)
		printf("��L�|���\n\n");
	else
		printf("Banana!\n\n");
		
		
	//Exercise 2
	float input;
	printf("���:");
	scanf("%f",&input);
	if(input-(int)input==0)
  		printf("�K�i���� %o\n�Q���i���� %x",(int)input,(int)input);
 	else
  		printf("Error!");
	
	return 0;
}
