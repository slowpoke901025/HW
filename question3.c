#include<stdio.h>
#include<stdlib.h>
struct Node
{
	char data;
	int linkNum;//�P��node�����۳s��node�ƶq 
	int visit;//�Ω��M�禡,��ܬO�_�w�g�P�_�L 
	struct Node *connectedNode[25];//�P��node�۳s��node 
}; 


void displayConnectedNode(struct Node *node)
{
	int index;
	printf("Nodes connected to %c:\n",node->data);
	for(index=0;index<node->linkNum;index++)
	{
		printf("%c ",node->connectedNode[index]->data);//�L�X�����۳s��node 
	}
	puts("");
}

void resetVisit(struct Node * node[],int num)//�k�svisit 
{
	int i=0;
	while(i<num)
	{
		node[i++]->visit=0;
	}
	
}
int isConnected(struct Node *node1,struct Node *node2)//���j 
{
	int index=0;
	node1->visit++;//��ܸ�node�w�g�P�_�L 
	
	//�i�JWHILE�N���enode1�Ψ�Ĥ@�Ӭ۳s��node != node2 
	while(node1->connectedNode[index]!=NULL&&node1->connectedNode[index]->data!=node2->data)
	{
		if(node1->connectedNode[index]->visit==0)//��node�|���P�_�L 
		{
			if(isConnected(node1->connectedNode[index],node2))//�A���I�s�禡 
			{
				break;//��return 1
			}
		}
		index++;//�U�@�Ӭ۳s��node 
	}
	
	if(node1->connectedNode[index]!=NULL)//��� 
	{
		
		return 1;
	}
	else//�S��� 
	{
		return 0;
	}
	
}

void Connect(struct Node *node1,struct Node *node2)//�s��Node 
{
	node1->connectedNode[node1->linkNum++]=node2;
	node2->connectedNode[node2->linkNum++]=node1;
}


int main()
{
	struct Node a={'a'},b={'b'},f={'f'},g={'g'},h={'h'},x={'x'},y={'y'},z={'z'}; 
	struct Node *net[] = {&a,&b,&f,&g,&h,&x,&y,&z};
	int num = 8;//�@�K��node 
	
	Connect(&a,&b);//�s��node 
	Connect(&b,&g);
	Connect(&b,&z);
	Connect(&g,&h);

	Connect(&y,&x);
	Connect(&y,&f);

	displayConnectedNode(&b);//�L�X�Pb�s����node 
	displayConnectedNode(&y);
	
	//�P�_���node�O�_�ݩ�P�@�쵲 
	printf("Is \"%c\" and \"%c\" connected? : %s\n",a.data,h.data,isConnected(&a,&h)?"Yes":"No");
	resetVisit(net,num);//�Nvisit�k�s 
	printf("\nIs \"%c\" and \"%c\" connected? : %s\n",x.data,a.data,isConnected(&x,&a)?"Yes":"No");
	
	return 0;
} 
