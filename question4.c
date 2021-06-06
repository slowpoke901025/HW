#include<stdio.h>
#include<stdlib.h>

struct info
{
	char name[10];
	char Class[10];
	int score;
};

void instruction()//��J��T 
{
	puts("Welcome,enter choice:");
	puts("1 to input new grades.");
	puts("2 to print out all records in current file.");
	puts("-1 to leave.\n");
	printf("?");

}
void add(FILE *file) //�s�W��ƨ禡 
{
	struct info *student;
	student = malloc(sizeof(struct info));//�t�m�O���� 
	
	puts("You are inputting grade currently.");
	printf("Please enter student's name: ");
	scanf("%s",student->name);
	printf("Please enter the student's class: ");
	scanf("%s",student->Class);
	printf("Please enter the student's score: ");
	scanf("%d",&student->score);
	
	fprintf(file,"%-10s%-10s%-10d\n",student->name,student->Class,student->score);//�g�J��� 
	free(student);//����O���� 
	
	puts("1 record has been added.\n");
}

int addAgain()//�O�_�~��s�W�禡 
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
			return 1;//�~��s�W 
		}
		else if(choice!=0)
		{
			puts("Please enter a valid number\n");//��J�L�ĭ�	
		}	
	}
	return 0;//���~��s�W 
	
}
void printStudent(FILE *file)
{
	int count = 0;
	char str[100];
	
	rewind(file);//��Ц^��}�Y 
	while(fgets(str,100,file)!=NULL)//�p���Ƶ��� 
	{
		count++;
	}
	printf("There are %d student(s):\n",count);
	
	rewind(file);//��Ц^��}�Y 
	while(fgets(str,100,file)!=NULL)//Ū���æL�X��� 
	{
		printf("%s",str);
	}
	puts("");	
}
int main()
{
	FILE *file;
	if((file=fopen("grade.txt","a+"))!=NULL)//��󦨥\���} 
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
					add(file);//�s�W��� 
					
					if(!addAgain())//�P�_�O�_�~��s�W 
					{
						printf("Leaving the function...\n\n");
						break;	
					}
				}	
			}
			else if(choice==2)
			{
				printStudent(file);//Ū���æL�X��� 
			}
			else if(choice != -1)//��J�L�ĭ� 
			{
				puts("Please enter a valid number\n");
			}
	
		}while(choice!=-1);
		
		puts("Good Bye !");
			
	}
	else//���}�ҥ��� 
	{
		printf("file opened failed.");
		exit(1);
	}
	
	fclose(file);
	return 0;
} 
