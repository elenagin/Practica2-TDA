#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

//Tratamiento en bits del bitwise
typedef struct Node
{
	int id;
	float cost;
	struct Node * nextn[4];
	uint8_t c_state;
}node;

node * new_node(int id);
node * new_conection(node **Inicio, int id);

int crear_grafo ()
{
	node *Inicio, *temp;
	int c=11, id=12;
	Inicio = new_node(c);
	//printf("%d\n", Inicio->id);


	Inicio = new_conection(&Inicio, id);
	printf("%d\n", Inicio->id);

	temp= Inicio->nextn[2];
	printf("%d\n", temp->id);

	temp = temp -> nextn[2];
	printf("%d\n", temp->id);

	temp = temp -> nextn[3];
	printf("%d\n", temp->id);

	temp = temp -> nextn[4];
	printf("%d\n", temp->id);

	temp = temp -> nextn[4];
	printf("%d\n", temp->id);

	temp = temp -> nextn[3];
	printf("%d\n", temp->id);

	temp = temp -> nextn[2];
	printf("%d\n", temp->id);

	temp = temp -> nextn[2];
	printf("%d\n", temp->id);

}

node * new_node(int id)
{
	//printf("%d", id);
	node *temp;
	temp =(node*)malloc(sizeof(node));
	temp->id = id;
	temp->c_state = 0;
	temp -> nextn[1] = NULL;
	temp -> nextn[2] = NULL;
	temp -> nextn[3] = NULL;
	temp -> nextn[4] = NULL;
	return temp;
}

node * new_conection(node **Inicio, int id)
{
	node *newNode11,*newNode12,*newNode13,*newNode21,*newNode22,*newNode23,*newNode31,*newNode32,*newNode33, *temp;
	newNode11 = *Inicio;
	newNode12 = new_node(12);
	newNode13 = new_node(13);
	newNode21 = new_node(21);
	newNode22 = new_node(22);
	newNode23 = new_node(23);
	newNode31 = new_node(31);
	newNode32 = new_node(32);
	newNode33 = new_node(33);
	//printf("%d\n", newNode->id);
	temp = newNode11;

	temp->nextn[2] = newNode12;
	temp->nextn[3] = newNode21;

	temp= newNode12;
	temp->nextn[2] = newNode13;
	temp->nextn[3] = newNode22;
	temp->nextn[4] = newNode11;

	temp= newNode13;
	temp->nextn[3] = newNode23;
	temp->nextn[4] = newNode12;
	
	temp= newNode23;
	temp->nextn[1] = newNode13;
	temp->nextn[3] = newNode33;
	temp->nextn[4] = newNode22;
	
	temp= newNode22;
	temp->nextn[1] = newNode12;
	temp->nextn[2] = newNode23;
	temp->nextn[3] = newNode32;
	temp->nextn[4] = newNode21;


	temp= newNode21;
	temp->nextn[1] = newNode11;
	temp->nextn[2] = newNode22;
	temp->nextn[3] = newNode31;
	
	temp= newNode31;
	temp->nextn[1] = newNode21;
	temp->nextn[2] = newNode32;

	temp= newNode32;
	temp->nextn[1] = newNode22;
	temp->nextn[2] = newNode33;
	temp->nextn[4] = newNode31;
	
	temp= newNode33;
	temp->nextn[1] = newNode23;
	temp->nextn[4] = newNode32;

	temp = newNode11;
	return temp;




	//printf("%d\n", temp->id);
	//printf("%d\n", temp->nextn[2]->id);

	//temp = temp->nextn[2];
	//printf("%d\n", temp->id);


	/*while(temp != NULL)
	{
		printf("%d    %d\n", temp->id, temp->nextn[2]->id);
		temp = temp->nextn[2];
	
	}*/

}
