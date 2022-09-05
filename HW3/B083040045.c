#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
	//Exercise 1
	int a,b,c,d;
	printf("輸入四邊長:");
	scanf("%d %d %d %d",&a,&b,&c,&d);
	
	if(a==b&&b==c&&c==d)
		printf("菱形\n\n");
	else if(a==c&&b==d&&a!=b) 
		printf("平行四邊形\n\n");
	else if(a+b+c>d&&a+c+d>b&&b+c+d>a&&a+b+d>c)
		printf("其他四邊形\n\n");
	else
		printf("Banana!\n\n");
		
		
	//Exercise 2
	float input;
	printf("整數:");
	scanf("%f",&input);
	if(input-(int)input==0)
  		printf("八進位表示 %o\n十六進位表示 %x",(int)input,(int)input);
 	else
  		printf("Error!");
	
	return 0;
}
