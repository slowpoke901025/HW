#include<stdio.h>
#include<stdlib.h>
struct Node
{
	char data;
	int linkNum;//與該node直接相連之node數量 
	int visit;//用於找尋函式,表示是否已經判斷過 
	struct Node *connectedNode[25];//與該node相連之node 
}; 


void displayConnectedNode(struct Node *node)
{
	int index;
	printf("Nodes connected to %c:\n",node->data);
	for(index=0;index<node->linkNum;index++)
	{
		printf("%c ",node->connectedNode[index]->data);//印出直接相連之node 
	}
	puts("");
}

void resetVisit(struct Node * node[],int num)//歸零visit 
{
	int i=0;
	while(i<num)
	{
		node[i++]->visit=0;
	}
	
}
int isConnected(struct Node *node1,struct Node *node2)//遞迴 
{
	int index=0;
	node1->visit++;//表示該node已經判斷過 
	
	//進入WHILE代表當前node1及其第一個相連之node != node2 
	while(node1->connectedNode[index]!=NULL&&node1->connectedNode[index]->data!=node2->data)
	{
		if(node1->connectedNode[index]->visit==0)//該node尚未判斷過 
		{
			if(isConnected(node1->connectedNode[index],node2))//再次呼叫函式 
			{
				break;//或return 1
			}
		}
		index++;//下一個相連之node 
	}
	
	if(node1->connectedNode[index]!=NULL)//找到 
	{
		
		return 1;
	}
	else//沒找到 
	{
		return 0;
	}
	
}

void Connect(struct Node *node1,struct Node *node2)//連接Node 
{
	node1->connectedNode[node1->linkNum++]=node2;
	node2->connectedNode[node2->linkNum++]=node1;
}


int main()
{
	struct Node a={'a'},b={'b'},f={'f'},g={'g'},h={'h'},x={'x'},y={'y'},z={'z'}; 
	struct Node *net[] = {&a,&b,&f,&g,&h,&x,&y,&z};
	int num = 8;//共八個node 
	
	Connect(&a,&b);//連結node 
	Connect(&b,&g);
	Connect(&b,&z);
	Connect(&g,&h);

	Connect(&y,&x);
	Connect(&y,&f);

	displayConnectedNode(&b);//印出與b連結的node 
	displayConnectedNode(&y);
	
	//判斷兩個node是否屬於同一鏈結 
	printf("Is \"%c\" and \"%c\" connected? : %s\n",a.data,h.data,isConnected(&a,&h)?"Yes":"No");
	resetVisit(net,num);//將visit歸零 
	printf("\nIs \"%c\" and \"%c\" connected? : %s\n",x.data,a.data,isConnected(&x,&a)?"Yes":"No");
	
	return 0;
} 
