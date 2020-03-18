

typedef struct Node
{
	int id;
	float cost;
	struct Node * nextn[4];
	uint8_t c_state;
}node;

node * new_node(int id);
node * new_connection(node **root, int id);


int create_graph (){
	node *root, *temp;
	int  id=12;
	root = new_node(0);

	root = new_connection(&root, id);

	return 0;

}

node * new_node(int id)
{
	node *temp;
	temp =(node*)malloc(sizeof(node));
	temp->id = id;
	temp->c_state = 0;
	temp -> nextn[0] = NULL;
	temp -> nextn[1] = NULL;
	temp -> nextn[2] = NULL;
	temp -> nextn[3] = NULL;

	return temp;
}

node * new_connection(node **root, int id)
{
	node *node_A,*node_B,*node_C,*node_D,*node_E;
	node_A = *root;
	node_B = new_node(1);
	node_C = new_node(2);
	node_D = new_node(3);
	node_E = new_node(4);

	node_A -> nextn[0]=node_B;
	node_A -> nextn[1]=node_D;

	node_B -> nextn[0]=node_A;
	node_B -> nextn[1]=node_D;
	node_B -> nextn[2]=node_E;
	node_B -> nextn[3]=node_C;

	node_C -> nextn[0]=node_B;
	node_C -> nextn[1]=node_E;

	node_D -> nextn[0]=node_A;
	node_D -> nextn[1]=node_E;
	node_D -> nextn[2]=node_B;

	node_E -> nextn[0]=node_B;
	node_E -> nextn[1]=node_D;
	node_E -> nextn[2]=node_C;

}
