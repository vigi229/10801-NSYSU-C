#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() 
{
	//9.1
	FILE *file=fopen("input1.txt","w");
	srand(time(NULL));
	int count=0,a,i,j;
	char str[1001],input;
	while(count<1000)	//65~90 97~122
	{
		a=rand()%58+65;
		if(a>90&&a<97)
			continue;
		else
		{
			str[count]=(char)a;
			count++;
		}
	}
	fputs(str,file);
	fclose(file);
	
	file=fopen("input1.txt","r");
	fgets(str,sizeof(str),file);
	
	printf("�z�b input.txt ���Q��M�ƶq���r����:");
	scanf(" %c",&input);
	while(input!='*')
	{
		if((input>=65&&input<=90)||(input>=95&&input<=122))
		{
			count=0;
			for(i=0;i<1000;i++)
			{
				if(str[i]==input||str[i]==input-32||str[i]==input+32)
					count++;
			}
			printf("�Ӧr��'%c'�b�Ӥ�󤤼ƶq��%d\n\n",input,count);
		}
		else
			printf("Wrong Input\n\n");
		
		printf("�z�b input.txt ���Q��M�ƶq���r����:");
		scanf(" %c",&input);	
	}
	
	//9.2
	int n;
	do{
		printf("\n�C�檺�r����:");
		scanf("%d",&n);
		
		if(n==-1)
		{
			printf("�����ק�C\n");
			break;
		}
		else if(n>0)
		{
			FILE *file2=fopen("output2.txt","w");
			char str2[n+1];
			if(1000%n==0)
			{
				for(i=0;i<1000/n;i++)
				{
					for(j=0;j<n;j++)
					{
						str2[j]=str[j+n*i];
					} 
					str2[n]='\0';
					fprintf(file2,"%s\n",str2);

				}
			}
			else
			{
				char str3[1000%n+1];
				for(i=0;i<=1000/n;i++)
				{
					if(i==1000/n)
					{
						for(j=0;j<1000%n;j++)
						{
							str3[j]=str[j+n*i];
						}
						str3[1000%n]='\0';
						fprintf(file2,"%s\n",str3);

					}
					else
					{
						for(j=0;j<n;j++)
						{
							str2[j]=str[j+n*i];
						}
						str2[n]='\0';
						fprintf(file2,"%s\n",str2);
					}
				}
			}
			printf("��粒��!\n");
			fclose(file2);
		}
		else
		{
			printf("��J���~�A�A�դ@���C\n");
		}
	} while(n!=-1);

	fclose(file);
	

    return 0;
}

