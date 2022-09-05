#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	char c;
	printf("請輸入任意字元:");
	scanf("%c",&c);
	printf("\t%6c\n",c);                                         //%6c表包含c共6bytes，前5個是空格 
	printf("\t%5c%c%c\n",c,c,c);
	printf("\t%4c%c%c%c%c\n",c,c,c,c,c);
	printf("\t%3c%c%c%c%c%c%c\n",c,c,c,c,c,c,c);
	printf("\t%2c%c%c%c%c%c%c%c%c\n",c,c,c,c,c,c,c,c,c);
	printf("\t%c%c%c%c%c%c%c%c%c%c%c\n",c,c,c,c,c,c,c,c,c,c,c);
	printf("\t%2c%c%c%c%c%c%c%c%c\n",c,c,c,c,c,c,c,c,c);
	printf("\t%6c\n",c);
	printf("\t%5c%c%c\n",c,c,c);
	system("pause"); 
	return 0;
}
