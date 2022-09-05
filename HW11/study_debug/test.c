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
	
	//產生亂數 
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
	
	//第一題 
	fp_in=fopen("input1.txt","r");
	for(i=0; i<1000; i++)
	{
		data[i]=fgetc(fp_in);
		
	}
	while(ch != '*')
	{
		printf("您在TEST1.txt想尋找數量的字元為: ");
    	scanf(" %c",&ch);
    	if((ch>=65 && ch<=90 )||(ch>=97 && ch<=122))
    	{
    		if(ch>=97)																//將小寫視為大寫 
			{
    			ch=ch-32;    			
			}
			else
			{
				for(i=0; i<1000; i++)               								//計算輸入字元出現次數 
				{
					if(ch==data[i] || (ch+32)==data[i])
					{
						num1++;
					}
				}					
			}
			printf("該字元'%c'在該文件中數量為: %d\n\n",ch,num1);			
    	}
		else
		{
		printf("Wrong input\n\n");
	    num1=0;
		}
	}
	printf("輸入結束\n\n");
	fclose(fp_in);
	
	
	//第二題 
	fp_in=fopen("input1.txt","r");
	fp_out=fopen("output2.txt","w");
	printf("每行的字元數： ");
	scanf("%d",&num_in);
    while(num_in!=-1){										//判別最後斷行數 
		if(num_in>0){
			num_out=num_in;			
			printf("更改完成!\n");
		}
		else
		{ 
			printf("輸入錯誤，在試一次\n");
		} 
		printf("每行的字元數： "); 
		scanf("%d",&num_in);	
	}
	i=0;													//寫入output2.txt 
	while(data[i]=fgetc(fp_in)!=EOF) {				
		fputc(data[i],fp_out);
		i++;
		if((i%num_out) ==  0)
		{
			fprintf(fp_out,"\n");
		}
	}	
	
    printf("結束修改\n"); 
    fclose(fp_in);
    fclose(fp_out);
	
	return 0;
}
