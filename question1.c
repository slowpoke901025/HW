#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
	FILE *file;
	char str[]="evil";//the word you want to count 
	char str1[100]={};//存文件讀出來的字串 
	char str2[100]={};//存str1修飾後的結果 
	int count=0;
	
	if((file=fopen("hw2_q1.txt","a+"))!=NULL)//檔案成功打開 
	{
		while(!feof(file))//游標尚未跑到底 
		{
			if(strcmp(str,str2)==0)//當str2與str相等 
			{
				count++;//次數++ 
			} 
			
			fscanf(file,"%s",str1);//讀取一個單字存入str1 
			
			//將str1去除字母外符號後存入str2 
			if(sscanf(str1,"%*[^a-zA-z]%[a-zA-Z]",str2)==0)//丟棄開頭及結尾符號,若開頭無符號 
			{
				sscanf(str1,"%[a-zA-z]",str2);//僅丟棄結尾符號 
			}
		}
		fprintf(file,"\nThe number of the times of the word \"%s\": %d time(s)",str,count);
		//寫入結果
	}
	else//打開失敗 
	{
		printf("File open failed");
		exit(1);
	} 
	
	fclose(file);
	return 0;
} 
