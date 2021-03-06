#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

//Tratamiento en bits del bitwise
typedef struct Node
{
	int id;
	float cost[5];
	struct Node * nextn[5];
	uint8_t c_state;
}node;

typedef struct Coord
{	
	float Acost;
	int idT;
		
}coord;

node * new_node(int id);
node * new_map(int *no_nodes);
void road(node *Inicio, int no_nodes);

int main ()
{
	node *Inicio, *temp;
	int no_nodes;


	Inicio = new_map(&no_nodes);
	road(Inicio, no_nodes);
	
	
	
}

node * new_node(int id)
{
	//printf("%d", id);
	int i;
	node *temp;
	temp =(node*)malloc(sizeof(node));
	temp->id = id;
	temp-> c_state = 0;

	temp -> nextn[1] = NULL;
	temp -> nextn[2] = NULL;
	temp -> nextn[3] = NULL;
	temp -> nextn[4] = NULL;
	return temp;
}

node * new_map(int *no_nodes)
{
	node *nodeA, *nodeB, *nodeC, *nodeD, *nodeE, *temp;
	*no_nodes= 5;
	
	nodeA = new_node(1);
	nodeB = new_node(2);
	nodeC = new_node(3);
	nodeD = new_node(4);
	nodeE = new_node(5);

	nodeA -> nextn[1] = nodeB;
	nodeA -> cost[1] = 6;
	nodeA -> nextn[2] = nodeD;
	nodeA -> cost[2] = 1;

	nodeB-> nextn[1] = nodeA;
	nodeB-> cost[1] = 6;
	nodeB-> nextn[2] = nodeD;
	nodeB-> cost[2] = 2;
	nodeB-> nextn[3] = nodeE;
	nodeB-> cost[3] = 2;
	nodeB-> nextn[4] = nodeC;
	nodeB-> cost[4] = 5;

	nodeC-> nextn[1] = nodeB;
	nodeC-> cost[1] = 5;
	nodeC-> nextn[2] = nodeE;
	nodeC-> cost[2] = 5;

	nodeD -> nextn[1] = nodeA;
	nodeD-> cost[1] = 1;
	nodeD-> nextn[2] = nodeB;
	nodeD-> cost[2] = 2;
	nodeD-> nextn[3] = nodeE;
	nodeD-> cost[3] = 1;

	nodeE -> nextn[1] = nodeB;
	nodeE-> cost[1] = 2;
	nodeE-> nextn[2] = nodeC;
	nodeE-> cost[2] = 5;
	nodeE-> nextn[3] = nodeD;
	nodeE-> cost [3] = 1;

	temp = nodeA;
	return nodeB;

}

void road(node *Inicio, int no_nodes)
{
	int i,c,visited[no_nodes+1], idm;
	float mincost=0, minimum;
	node *temp;
	coord Table[no_nodes+1][no_nodes+1], cordTemp, null;
	null.Acost= 9999;
	null.idT = 9999;
	temp = Inicio;

	for(i=0 ; i<=no_nodes ; i++)
	{
		visited[i]=0;
	}

	for(i=0 ; i<=no_nodes; i++)
	{
		Table[i][1] = null;
	}

	cordTemp.Acost = 0;
	cordTemp.idT = temp -> id;

	Table[temp->id][1] = cordTemp;
	

	for(i=1 ; i<=no_nodes ; i++)
	{
				if(temp -> nextn[i] != NULL)
				{
				
					cordTemp.Acost = Table[temp->id][1].Acost + temp -> cost[i];
					cordTemp.idT = temp -> id;
					Table[temp-> nextn[i]->id][1] = cordTemp;
					cordTemp.Acost = 0;
					cordTemp.idT = 0;
				}
			
			//if(Table[i][1].Acost >= Table[i-1][1].Acost && Table[i-1][1].Acost != 0 )
			//{
			//	Table[i][1] = Table[i-1][1];
			//}
	}


	visited[temp->id]=1;
	minimum = Table[0][1].Acost;
	for (c = 1; c < no_nodes; c++)
    {
		if(visited[c]==0)
		{
			if (Table[c][1].Acost < minimum)
			{
				minimum = Table[c][1].Acost;
				idm = c;
			}
		}
    }
	printf("%f\n", minimum);
	visited[idm]=1;


	for(i=1 ; i<=no_nodes ; i++)
	{
		printf("%f\t%d\n", Table[i][1].Acost, Table[i][1].idT);
	}

}
