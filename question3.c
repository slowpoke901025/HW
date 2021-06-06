#include<stdio.h>
#include<stdlib.h>
struct Node
{
	char data;
	struct Node *last;
	struct Node *left;
	struct Node *right;	
	
}; 

int limit=26;//node�ƶq�̦h26 

struct Node *insert(struct Node **LPtr,char value,char dir)
{
	if(limit>0)// node�ƶq����26 
	{
		struct Node *newPtr;
		newPtr = malloc(sizeof(struct Node));
	 
		if(dir=='L')//�s�W�ܥ��K 
		{
			(*LPtr)->left = newPtr;	
		}
		else if(dir=='R')//�s�W�ܥk�K
		{
			(*LPtr)->right = newPtr;	
		}
		//��l��&�s��node 
		newPtr->data = value;//�פJ��� 
		newPtr->last = *LPtr;//�s�� 
		newPtr->left = NULL;
		newPtr->right = NULL;
		limit--;
		
		return newPtr;//�^��node��m 
	}
	return NULL;//node�w��26	
}

void displayConnectedNode(struct Node *node)
{
	printf("Nodes connected to %c:\n",node->data);
	//�M��node�e�K,���K�Υk�K 
	if(node->last!=NULL)
	printf("%c ",node->last->data);
	
	if(node->left!=NULL)
	printf("%c ",node->left->data);
	
	if(node->right!=NULL)
	printf("%c ",node->right->data);
	
	puts("\n");	
}

int isConnected(struct Node *node1,struct Node *node2)
{
	struct Node *curPtr1=node1;
	struct Node *curPtr2=node2;
	
	while(curPtr1->last!=NULL)
	{
		curPtr1=curPtr1->last;//�M��node1���Y 
	}
	while(curPtr2->last!=NULL)
	{
		curPtr2=curPtr2->last;//�M��node2���Y 
	}
	
	return curPtr1==curPtr2 ? 1:0;//�Y�ݩ�P��,���Y���Ӭ��P�r�� 
}

struct Node *headInitialize(struct Node **sPtr,char value)//�t�m�媺�}�Y 
{
	(*sPtr)->data = value;//�פJ��� 
	(*sPtr)->last = NULL;//��l�� 
	(*sPtr)->left = NULL;
	(*sPtr)->right = NULL;
	limit--;//�̦h26��node,�α��@�� 
	return *sPtr;//�^��node��m 
}	

int main()
{
	struct Node *a,*b,*f,*g,*h,*x,*y,*z;//�ŧinodePtr 
	struct Node *chain1 = malloc(sizeof(struct Node));//�t�m�쵲 
	struct Node *chain2 = malloc(sizeof(struct Node));//�t�m�쵲
	
	a=headInitialize(&chain1,'a');//a��chain1���}�Y,�ñN���l�� 
	b=insert(&a,'b','L');//b��a�����K,�P�ɶפJdata 
	g=insert(&b,'g','L');
	z=insert(&b,'z','R');//z��b���k�K
	h=insert(&g,'h','R');
	
	y=headInitialize(&chain2,'y');//y��chain2���}�Y 
	f=insert(&y,'f','L');
	x=insert(&y,'x','R');
	
	displayConnectedNode(b);//�L�X�Pb�s����node 
	displayConnectedNode(y);
	
	//�P�_���node�O�_�ݩ�P�@�쵲 
	printf("Is \"%c\" and \"%c\" connected? : %s\n",a->data,h->data,isConnected(a,h)?"Yes":"No");
	printf("\nIs \"%c\" and \"%c\" connected? : %s\n",x->data,a->data,isConnected(x,a)?"Yes":"No");
	
	return 0;
} 
