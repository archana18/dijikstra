#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#define ARRAYSIZE(x) (sizeof(x)/sizeof(*(x)))
int source;
#define V 5
int mind(int dist[], int set1[])
{
   
  int min = INT_MAX, min_index;

  for (int v = 0; v < V; v++)
   if (set1[v] == 0 && dist[v] <= min)
       min = dist[v], min_index = v;

  return min_index;
}
  

void display(int dist[], int n)
{
   printf("Vertex   Distance from Source\n");
   for (int i = 0; i < V; i++)
   {
      if(dist[i] == INT_MAX)
      {
        printf("%d \t\t INFINITY\n", i);
      }
      else
      {
        printf("%d \t\t %d\n", i, dist[i]);
      }
   }

}
  

void dijkstra(int graph[V][V], int src)
{
     int dist[V];     
     int set1[V]; 
  
    
     for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, set1[i] = 0;
  
     
     dist[src] = 0;
  
 
     for (int count = 0; count < V-1; count++)
     {
       
       int u = mind(dist, set1);
  
       
       set1[u] = 1;
  
       
       for (int v = 0; v < V; v++)
  
         
         if (set1[v] == 0 && graph[u][v] > 0&& dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v])
         {
            dist[v] = dist[u] + graph[u][v];
         }
     }     
     display(dist, V);
}
 
int getmatrix(char *fileName)
{
  int i;
  int j; int lines=0; int ch=0;
  FILE* f = fopen(fileName, "r"); 

  
  if (f)
  {
      int array[5][5];
      size_t i, j, k;
      char buffer[BUFSIZ], *ptr;
      
      for ( i = 0;fgets(buffer, sizeof buffer, f); ++i )
        {
          for ( j = 0, ptr = buffer; j < ARRAYSIZE(*array); ++j, ++ptr )
          {
           // if(i<lines &&j<lines)
              array[i][j] = (int)strtol(ptr, &ptr, 10);
              printf("%d ",array[i][j]);
          }
          printf("\n");
        }
  

      dijkstra(array, source);
  exit:
    fclose(f);
   
    return 0;
  }
  return 1;
}



int main(int argc, char *argv[])
{ 
  char  *fileName = argv[1]; 
  source = atoi(argv[2]);
  getmatrix(fileName);  
  return 0;
}