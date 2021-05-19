#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



struct Vertex 
{
   char label;
   bool visited;
};


int queue[5];
int rear = -1;
int front = 0;
int queueItemCount = 0;
struct Vertex* lstVertices[5];
int adjMatrix[5][5];
int vertexCount = 0;

void insert(int data) 
{
   queue[++rear] = data;
   queueItemCount++;
}


int removeData() 
{
   
   return queue[front++]; 
}


void addVertex(char label) 
{
   struct Vertex* vertex = (struct Vertex*) malloc(sizeof(struct Vertex));
   vertex->label = label;  
   vertex->visited = false;     
   lstVertices[vertexCount++] = vertex;
}

void addEdge(int start,int end) 
{
   adjMatrix[start][end] = 1;
   adjMatrix[end][start] = 1;
}

void displayVertex(int vertexIndex) 
{
   printf("%c ",lstVertices[vertexIndex]->label);
}       

int getAdjUnvisitedVertex(int vertexIndex) 
{
   int i;
	
   for(i = 0; i<vertexCount; i++) {
      if(adjMatrix[vertexIndex][i] == 1 && lstVertices[i]->visited == false)
         return i;
   }
	
   return -1;
}

void bfs() {
   int i;

   lstVertices[0]->visited = true;

   displayVertex(0);   

   insert(0);
   int unvisitedVertex;

   while(queueItemCount != 0) 
   {
   		queueItemCount--;
   		int tempVertex=queue[front++]; 
       
      	while((unvisitedVertex = getAdjUnvisitedVertex(tempVertex)) != -1) 
		  {    
        	lstVertices[unvisitedVertex]->visited = true;
         	displayVertex(unvisitedVertex);
         	insert(unvisitedVertex);               
      }
		
   }   
    
   for(i = 0;i<vertexCount;i++) {
      lstVertices[i]->visited = false;
   }    
}




int main() {
   int i, j;
   
   for(i = 0; i<5; i++)
   {
   		for(j = 0; j<5; j++) 
   		{
   			adjMatrix[i][j] = 0;
		}
         
   }
     
	int nodes=4;
   char ch;
   printf("Enter nodes of a 5 member Graph \n");
   for(int i=0;i<=nodes;i++)
   {
   		printf("Enter node name: ");
   		scanf(" %c",&ch);
   		addVertex(ch);
   }
   for(int j=1;j<nodes;j++)
   {
   		addEdge(0,j);
   		addEdge(j,nodes);
   }
 
   
   printf("\nBreadth First Search: ");
   
   bfs();

   return 0;
}
