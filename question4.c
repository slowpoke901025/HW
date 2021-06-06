#include<stdio.h>
#include<stdlib.h>

struct info
{
	char name[10];
	char Class[10];
	int score;
};

void instruction()//輸入資訊 
{
	puts("Welcome,enter choice:");
	puts("1 to input new grades.");
	puts("2 to print out all records in current file.");
	puts("-1 to leave.\n");
	printf("?");

}
void add(FILE *file) //新增資料函式 
{
	struct info *student;
	student = malloc(sizeof(struct info));//配置記憶體 
	
	puts("You are inputting grade currently.");
	printf("Please enter student's name: ");
	scanf("%s",student->name);
	printf("Please enter the student's class: ");
	scanf("%s",student->Class);
	printf("Please enter the student's score: ");
	scanf("%d",&student->score);
	
	fprintf(file,"%-10s%-10s%-10d\n",student->name,student->Class,student->score);//寫入文件 
	free(student);//釋放記憶體 
	
	puts("1 record has been added.\n");
}

int addAgain()//是否繼續新增函式 
{
	int choice=1;
	while(choice!=0)
	{
		printf("Would you want to add new record? ");
		printf("1 for yes,0 for no.\n");
		printf("\n?");
		scanf("%d",&choice);
		printf("Your selection: %d\n\n",choice);
		
		if(choice==1)
		{
			return 1;//繼續新增 
		}
		else if(choice!=0)
		{
			puts("Please enter a valid number\n");//輸入無效值	
		}	
	}
	return 0;//不繼續新增 
	
}
void printStudent(FILE *file)
{
	int count = 0;
	char str[100];
	
	rewind(file);//游標回到開頭 
	while(fgets(str,100,file)!=NULL)//計算資料筆數 
	{
		count++;
	}
	printf("There are %d student(s):\n",count);
	
	rewind(file);//游標回到開頭 
	while(fgets(str,100,file)!=NULL)//讀取並印出資料 
	{
		printf("%s",str);
	}
	puts("");	
}
int main()
{
	FILE *file;
	if((file=fopen("grade.txt","a+"))!=NULL)//文件成功打開 
	{
		int choice;
		do
		{	
			instruction();
			scanf("%d",&choice);
			printf("Your selection: %d\n\n",choice);
			
			if(choice==1)
			{
				while(1)
				{
					add(file);//新增資料 
					
					if(!addAgain())//判斷是否繼續新增 
					{
						printf("Leaving the function...\n\n");
						break;	
					}
				}	
			}
			else if(choice==2)
			{
				printStudent(file);//讀取並印出資料 
			}
			else if(choice != -1)//輸入無效值 
			{
				puts("Please enter a valid number\n");
			}
	
		}while(choice!=-1);
		
		puts("Good Bye !");
			
	}
	else//文件開啟失敗 
	{
		printf("file opened failed.");
		exit(1);
	}
	
	fclose(file);
	return 0;
} 
