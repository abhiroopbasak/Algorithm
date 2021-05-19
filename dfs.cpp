#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

struct Vertex {
   char label;
   bool visited;
};

int stack[MAX]; 
int top = -1; 

struct Vertex* lstVertices[MAX];

int adjMatrix[MAX][MAX];

int vertexCount = 0;


void push(int item) { 
   stack[++top] = item; 
} 

int pop() { 
   return stack[top--]; 
} 

int peek() {
   return stack[top];
}


void addVertex(char label) {
   struct Vertex* vertex = (struct Vertex*) malloc(sizeof(struct Vertex));
   vertex->label = label;  
   vertex->visited = false;     
   lstVertices[vertexCount++] = vertex;
}

void addEdge(int start,int end) {
   adjMatrix[start][end] = 1;
   adjMatrix[end][start] = 1;
}
void displayVertex(int vertexIndex) {
   printf("%c ",lstVertices[vertexIndex]->label);
}       

int getAdjUnvisitedVertex(int vertexIndex) {
   int i;

   for(i = 0; i < vertexCount; i++) {
      if(adjMatrix[vertexIndex][i] == 1 && lstVertices[i]->visited == false) {
         return i;
      }
   }

   return -1;
}

void depthFirstSearch() {
   int i;
   lstVertices[0]->visited = true;
   displayVertex(0);
   push(0);

   while(!(top == -1)) {
      int unvisitedVertex = getAdjUnvisitedVertex(peek());

      if(unvisitedVertex == -1) {
         pop();
      } else {
         lstVertices[unvisitedVertex]->visited = true;
         displayVertex(unvisitedVertex);
         push(unvisitedVertex);
      }
   }     
   for(i = 0;i < vertexCount;i++) {
      lstVertices[i]->visited = false;
   }        
}

int main() {
   int i, j;

   for(i = 0; i < MAX; i++)    
      for(j = 0; j < MAX; j++) 
         adjMatrix[i][j] = 0;
   

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
 

   printf("Depth First Search: ");
   depthFirstSearch(); 

   return 0;   
}
