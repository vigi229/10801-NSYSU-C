#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	char c;
	printf("�п�J���N�r��:");
	scanf("%c",&c);
	printf("\t%6c\n",c);                                         //%6c��]�tc�@6bytes�A�e5�ӬO�Ů� 
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
