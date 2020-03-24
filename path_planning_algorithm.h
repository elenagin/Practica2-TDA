typedef struct Table
{
  int id;
  int short_distance;
  int Previous_vertex;
} table;

void stupid();

void start()
{
  table *row_A, *row_B, *row_C, *row_D, *row_E;
  node *root;
  int unvisited[5] = {-1, 1, 2, 3, 4}, visited[5] = {0, -1, -1, -1, -1};

  row_A->id = 0;
  row_A->short_distance = 0;
  row_A->Previous_vertex = 0;
  row_B->id = 1;
  row_B->short_distance = 32768;
  row_B->Previous_vertex = 0;
  row_C->id = 2;
  row_C->short_distance = 32768;
  row_C->Previous_vertex = 0;
  row_D->id = 3;
  row_D->short_distance = 32768;
  row_D->Previous_vertex = 0;
  row_E->id = 4;
  row_E->short_distance = 32768;
  row_E->Previous_vertex = 0;

  root = create_graph();

  switch (root->id)
  {
  case 0:
    stupid(root, row_A, &visited, &unvisited);
    printf("Dentro de A");
    break;

  case 1:
    stupid(root, row_B, &visited, &unvisited);
    printf("Dentro de B");
    break;

  case 2:
    stupid(root, row_C, &visited, &unvisited);
    printf("Dentro de C");
    break;

  case 3:
    stupid(root, row_D, &visited, &unvisited);
    printf("Dentro de D");
    break;

  case 4:
    stupid(root, row_E, &visited, &unvisited);
    printf("Dentro de E");
    break;
  }
}

void stupid(node *graph, table *row, int *visited[5], int *unvisited[5])
{
  int i, j, temp[2][5];
  
  printf("%d blaaa\n", *graph->nextn[i]->id);

  while (graph->nextn[i] != NULL)
  {
    for (j = 0; j < 5; j++)
      if (graph->nextn[i] == unvisited[j]){
        temp[j][0] = graph->cost[i];
        temp[j][1] = graph->nextn;
        printf("Costo %d \n", graph->cost[i]);
        printf("id %d \n", graph->nextn);
      }
  i++;
  }
}
