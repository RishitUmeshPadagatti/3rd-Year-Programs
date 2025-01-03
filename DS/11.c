// 11. Develop a Program in C for the following operations on Graph(G) of Cities
// a. Create a Graph of N cities using Adjacency Matrix.
// b. Print all the nodes reachable from a given starting node in a digraph using DFS/BFS method

#include <stdio.h>
#include <stdlib.h>

int a[50][50], n, visited[20];
int q[20], front=-1, rear=-1;
int s[20], top=-1;

void create(){
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix\n");
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            scanf("%d", &a[i][j]);
        }
    }
}

void bfs(int v){
    int cur, i;
    visited[v] = 1;
    q[++rear] = v;
    while(front != rear){
        cur = q[++front];
        for (i=1; i<=n; i++){
            if ((a[cur][i]==1) && (visited[i]==0)){
                q[++rear] = i;
                visited[i] = 1;
                printf("%d-> ", i);
            }
        }
    }
}

void dfs(int v){
    int i;
    visited[v] = 1;
    s[++top] = v;
    for (i=1; i<=n; i++){
        if ((a[v][i]==1) && (visited[i]==0)){
            printf("%d-> ", i);
            dfs(i);
        }
    }
}

int main(){
    int ch, start;
    while(1){
        printf("\n\n1. Create Graph");
        printf("\n2. BFS");
        printf("\n3. DFS");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: create(); break;
            case 2: for (int i=1; i<=n; i++)
                        visited[i] = 0;
                    printf("Enter the starting vertex: ");
                    scanf("%d", &start);
                    printf("Nodes reachable from starting vertex %d are: ", start);
                    bfs(start);
                    break;
            case 3: for (int i=1; i<=n; i++)
                        visited[i] = 0;
                    printf("Enter the starting vertex: ");
                    scanf("%d", &start);
                    printf("Nodes reachable from starting vertex %d are: ", start);
                    dfs(start);
                    break;
            case 4: exit(0);
            default:printf("Invalid Choice\n");
        }
    }

    return 0;
}