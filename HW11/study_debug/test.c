#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
int main(void)
{
	FILE *fp;
	FILE *fp_in;
	FILE *fp_out;
	int i,num1=0,num_in=0,num_out;
	int tool=0,index;
	char ch,data[1000];
	
	//���Ͷü� 
	/* 
	srand(time(NULL));
	fp=fopen("input1.txt","w");
	for(i=0; i<1000; i++)
	{
		tool=rand()%2;
		if(tool==0)
		{
			index=rand()%25+65;
		}
		else
		{
			index=rand()%25+97;
		}
		fprintf(fp,"%c",index);
	}
	fclose(fp);
	*/ 
	
	//�Ĥ@�D 
	fp_in=fopen("input1.txt","r");
	for(i=0; i<1000; i++)
	{
		data[i]=fgetc(fp_in);
		
	}
	while(ch != '*')
	{
		printf("�z�bTEST1.txt�Q�M��ƶq���r����: ");
    	scanf(" %c",&ch);
    	if((ch>=65 && ch<=90 )||(ch>=97 && ch<=122))
    	{
    		if(ch>=97)																//�N�p�g�����j�g 
			{
    			ch=ch-32;    			
			}
			else
			{
				for(i=0; i<1000; i++)               								//�p���J�r���X�{���� 
				{
					if(ch==data[i] || (ch+32)==data[i])
					{
						num1++;
					}
				}					
			}
			printf("�Ӧr��'%c'�b�Ӥ�󤤼ƶq��: %d\n\n",ch,num1);			
    	}
		else
		{
		printf("Wrong input\n\n");
	    num1=0;
		}
	}
	printf("��J����\n\n");
	fclose(fp_in);
	
	
	//�ĤG�D 
	fp_in=fopen("input1.txt","r");
	fp_out=fopen("output2.txt","w");
	printf("�C�檺�r���ơG ");
	scanf("%d",&num_in);
    while(num_in!=-1){										//�P�O�̫��_��� 
		if(num_in>0){
			num_out=num_in;			
			printf("��粒��!\n");
		}
		else
		{ 
			printf("��J���~�A�b�դ@��\n");
		} 
		printf("�C�檺�r���ơG "); 
		scanf("%d",&num_in);	
	}
	i=0;													//�g�Joutput2.txt 
	while(data[i]=fgetc(fp_in)!=EOF) {				
		fputc(data[i],fp_out);
		i++;
		if((i%num_out) ==  0)
		{
			fprintf(fp_out,"\n");
		}
	}	
	
    printf("�����ק�\n"); 
    fclose(fp_in);
    fclose(fp_out);
	
	return 0;
}
