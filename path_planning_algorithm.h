
typedef struct Table{
  int id;
  int short_distance;
  int Previous_vertex;
}table;

void start(node * root){
  table * row_A, * row_B, * row_C, * row_D, * row_E;
  int unvisited[5]={0,1,2,3,4},visited[5]={-1,-1,-1,-1,-1};
  printf("%d, %d, %d, %d, %d \n",unvisited[0],unvisited[1],unvisited[2],unvisited[3],unvisited[4] );
  row_A->id = 0;
  //printf("%d\n",row_A->id);
  row_A->short_distance=0;
  //printf("%d\n",row_A->short_distance);
  row_A->Previous_vertex=0;
  //printf("%d\n",row_A->Previous_vertex);
  row_B -> id = 1;
  row_B ->short_distance=32768;
  row_B -> Previous_vertex=-1;
  row_C -> id = 2;
  row_C ->short_distance=32768;
  row_C -> Previous_vertex=-1;
  row_D -> id = 3;
  row_D ->short_distance=32768;
  row_D -> Previous_vertex=-1;
  row_E -> id = 4;
  row_E ->short_distance=32768;
  row_E -> Previous_vertex=-1;
  printf("ok\n");

  //for(int i=0;i<4;i++){

  //}

}
