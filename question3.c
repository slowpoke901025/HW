#include<stdio.h>
#include<stdlib.h>
struct Node
{
	char data;
	struct Node *last;
	struct Node *left;
	struct Node *right;	
	
}; 

int limit=26;//node數量最多26 

struct Node *insert(struct Node **LPtr,char value,char dir)
{
	if(limit>0)// node數量未滿26 
	{
		struct Node *newPtr;
		newPtr = malloc(sizeof(struct Node));
	 
		if(dir=='L')//新增至左枝 
		{
			(*LPtr)->left = newPtr;	
		}
		else if(dir=='R')//新增至右枝
		{
			(*LPtr)->right = newPtr;	
		}
		//初始化&連接node 
		newPtr->data = value;//匯入資料 
		newPtr->last = *LPtr;//連接 
		newPtr->left = NULL;
		newPtr->right = NULL;
		limit--;
		
		return newPtr;//回傳node位置 
	}
	return NULL;//node已滿26	
}

void displayConnectedNode(struct Node *node)
{
	printf("Nodes connected to %c:\n",node->data);
	//尋找node前枝,左枝及右枝 
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
		curPtr1=curPtr1->last;//尋找node1源頭 
	}
	while(curPtr2->last!=NULL)
	{
		curPtr2=curPtr2->last;//尋找node2源頭 
	}
	
	return curPtr1==curPtr2 ? 1:0;//若屬於同鍊,源頭應該為同字母 
}

struct Node *headInitialize(struct Node **sPtr,char value)//配置鍊的開頭 
{
	(*sPtr)->data = value;//匯入資料 
	(*sPtr)->last = NULL;//初始化 
	(*sPtr)->left = NULL;
	(*sPtr)->right = NULL;
	limit--;//最多26個node,用掉一個 
	return *sPtr;//回傳node位置 
}	

int main()
{
	struct Node *a,*b,*f,*g,*h,*x,*y,*z;//宣告nodePtr 
	struct Node *chain1 = malloc(sizeof(struct Node));//配置鏈結 
	struct Node *chain2 = malloc(sizeof(struct Node));//配置鏈結
	
	a=headInitialize(&chain1,'a');//a為chain1之開頭,並將其初始化 
	b=insert(&a,'b','L');//b為a的左枝,同時匯入data 
	g=insert(&b,'g','L');
	z=insert(&b,'z','R');//z為b的右枝
	h=insert(&g,'h','R');
	
	y=headInitialize(&chain2,'y');//y為chain2之開頭 
	f=insert(&y,'f','L');
	x=insert(&y,'x','R');
	
	displayConnectedNode(b);//印出與b連結的node 
	displayConnectedNode(y);
	
	//判斷兩個node是否屬於同一鏈結 
	printf("Is \"%c\" and \"%c\" connected? : %s\n",a->data,h->data,isConnected(a,h)?"Yes":"No");
	printf("\nIs \"%c\" and \"%c\" connected? : %s\n",x->data,a->data,isConnected(x,a)?"Yes":"No");
	
	return 0;
} 
