#include<stdio.h>
#include<stdlib.h>
struct List
{
	char data;
	struct List *next;
};

int insert(struct List **headPtr,char ch)
{
	struct List *curPtr;
	struct List *node;
	
	node = malloc(sizeof(struct List));//配置記憶體 
	node->data = ch;//匯入資料 
	node->next = NULL;//初始化 
	
	if(*headPtr==NULL)//鏈結尚未有node 
	{
		*headPtr=node;//開頭指標指向該node 
		(*headPtr)->next=NULL;//初始化 
	}
	else
	{
		curPtr=*headPtr;//從頭開始找 
		while(curPtr->next!=NULL)
		{
			curPtr=curPtr->next;//找到末項為止 
		}
		curPtr->next=node;	//將node新增至尾巴 
	}
	
}
void printList(struct List *curPtr)
{
	while(curPtr!=NULL)//印出後向後移
	{
		printf("%c --> ",curPtr->data); 
		curPtr=curPtr->next;
	}
	printf("NULL");//最後為NULL 
}

void printRevList(struct List *curPtr)//遞迴 
{
	if(curPtr!=NULL)//尚未讀到末項 
	{
		printRevList(curPtr->next);//繼續呼叫 
		printf(" <-- %c",curPtr->data);
	}
	else//讀到末項 
	{
		printf("NULL");
	}
	
}

int main()
{
	struct List *head = NULL;//紀錄開頭node位置 
	insert(&head,'a');//加入node至鏈結末項 
	insert(&head,'b');
	insert(&head,'c');
	insert(&head,'d');
	
	printf("Original linked list: ");
	printList(head);
	
	printf("\nReversed linked list: ");
	printRevList(head);
	
	return 0;
} 
