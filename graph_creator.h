

typedef struct Node
{
	int id;
	float cost;
	struct Node * nextn[4];
	uint8_t c_state;
}node;

node * new_node(int id);
node * new_connection(node **root, int id);
void load_graph(node * node);

node * create_graph (){
	node *root, *temp;
	int  id=0;
	root = new_node(0);

	root = new_connection(&root, id);

	return root;
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
	node_A -> cost=5/2;

	node_B -> nextn[0]=node_A;
	node_B -> nextn[1]=node_D;
	node_B -> nextn[2]=node_E;
	node_B -> nextn[3]=node_C;
	node_B -> cost=7/2;

	node_C -> nextn[0]=node_B;
	node_C -> nextn[1]=node_E;
	node_C -> cost=5/2;

	node_D -> nextn[0]=node_A;
	node_D -> nextn[1]=node_E;
	node_D -> nextn[2]=node_B;
	node_D -> cost=-3/2;

	node_E -> nextn[0]=node_B;
	node_E -> nextn[1]=node_D;
	node_E -> nextn[2]=node_C;
	node_E -> cost = 5/2;

	printf("A\n");
	load_graph(node_A);
	printf("B\n");
	load_graph(node_B);
	printf("C\n");
	load_graph(node_C);
	printf("D\n");
	load_graph(node_D);
	printf("E\n");
	load_graph(node_E);
	return node_A;
}

void load_graph(node * node){
	for(int i=0;i<=3;i++){
		if (node->nextn[i] != NULL) {
			printf("conectado a %d\n", node->nextn[i]->id);
		}else{
			printf("No conectado\n");
		}
	}
}
