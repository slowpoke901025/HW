#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
	FILE *file;
	char str[]="evil";//the word you want to count 
	char str1[100]={};//�s���Ū�X�Ӫ��r�� 
	char str2[100]={};//�sstr1�׹��᪺���G 
	int count=0;
	
	if((file=fopen("hw2_q1.txt","a+"))!=NULL)//�ɮצ��\���} 
	{
		while(!feof(file))//��Щ|���]�쩳 
		{
			if(strcmp(str,str2)==0)//��str2�Pstr�۵� 
			{
				count++;//����++ 
			} 
			
			fscanf(file,"%s",str1);//Ū���@�ӳ�r�s�Jstr1 
			
			//�Nstr1�h���r���~�Ÿ���s�Jstr2 
			if(sscanf(str1,"%*[^a-zA-z]%[a-zA-Z]",str2)==0)//���}�Y�ε����Ÿ�,�Y�}�Y�L�Ÿ� 
			{
				sscanf(str1,"%[a-zA-z]",str2);//�ȥ�󵲧��Ÿ� 
			}
		}
		fprintf(file,"\nThe number of the times of the word \"%s\": %d time(s)",str,count);
		//�g�J���G
	}
	else//���}���� 
	{
		printf("File open failed");
		exit(1);
	} 
	
	fclose(file);
	return 0;
} 
