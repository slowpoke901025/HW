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
	
	node = malloc(sizeof(struct List));//�t�m�O���� 
	node->data = ch;//�פJ��� 
	node->next = NULL;//��l�� 
	
	if(*headPtr==NULL)//�쵲�|����node 
	{
		*headPtr=node;//�}�Y���Ы��V��node 
		(*headPtr)->next=NULL;//��l�� 
	}
	else
	{
		curPtr=*headPtr;//�q�Y�}�l�� 
		while(curPtr->next!=NULL)
		{
			curPtr=curPtr->next;//��쥽������ 
		}
		curPtr->next=node;	//�Nnode�s�W�ܧ��� 
	}
	
}
void printList(struct List *curPtr)
{
	while(curPtr!=NULL)//�L�X��V�Ჾ
	{
		printf("%c --> ",curPtr->data); 
		curPtr=curPtr->next;
	}
	printf("NULL");//�̫ᬰNULL 
}

void printRevList(struct List *curPtr)//���j 
{
	if(curPtr!=NULL)//�|��Ū�쥽�� 
	{
		printRevList(curPtr->next);//�~��I�s 
		printf(" <-- %c",curPtr->data);
	}
	else//Ū�쥽�� 
	{
		printf("NULL");
	}
	
}

int main()
{
	struct List *head = NULL;//�����}�Ynode��m 
	insert(&head,'a');//�[�Jnode���쵲���� 
	insert(&head,'b');
	insert(&head,'c');
	insert(&head,'d');
	
	printf("Original linked list: ");
	printList(head);
	
	printf("\nReversed linked list: ");
	printRevList(head);
	
	return 0;
} 
