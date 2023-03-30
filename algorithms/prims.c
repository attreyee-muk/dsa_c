// A C program for Prim's Minimum
// Spanning Tree (MST) algorithm. The program is
// for adjacency matrix representation of the graph

#include <stdio.h>
#include <stdbool.h>
#define V 6
int minimum(int values[],bool setMST[]){
    int min=__INT_MAX__;
    int vertex;
    for(int i=0;i<V;i++){
        if(setMST[i]==false && values[i]<min){
            vertex=i;
            min=values[i];
        }
    }
    return vertex;
}

int printMST(int parent[],int graph[V][V]){
    printf("Egde \tWeight\n");
    for(int i=1;i<V;i++){
        printf("%d - %d \t%d \n",parent[i],i,graph[i][parent[i]]);
    }
}

int primMST(int graph[V][V]){
    int parent[V];
    int values[V];
    bool setMST[V];
    for(int i=0;i<V;i++){
        values[i]=__INT_MAX__;
        setMST[i]=false;

    }
    values[0]=0;
    parent[0]=-1;
    for(int i=0;i<V-1;i++){
        int U=minimum(values,setMST);
        setMST[U]=true;
        for(int j=0;j<V;j++){
            if(graph[U][j] && setMST[j]==false && graph[U][j]<values[j]){
                parent[j]=U;
                values[j]=graph[U][j];
            }
        }
    }
    printMST(parent,graph);
}

int main(){
    int graph[V][V] = { {0, 4, 6, 0, 0, 0},
						{4, 0, 6, 3, 4, 0},
						{6, 6, 0, 1, 8, 0},
						{0, 3, 1, 0, 2, 3},
						{0, 4, 8, 2, 0, 7},
						{0, 0, 0, 3, 7, 0} };

	primMST(graph);	
	return 0;
}