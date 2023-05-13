// NOT WORKING

#include <stdio.h>
#include <limits.h>  //for INT_MAX and INT_MIN
#include <stdbool.h> //for boolean datatype
int i, j;

int minVertex(int n, int dist[n], bool visited[n])  //the greedy approach
{
    int min = INT_MAX;
    int u; // min vertex's index
    for (i = 0; i < n; i++)
    {
        if (dist[i] < min && visited[i] == false)
        {
            min = dist[i];
            u = i;
        }
    }
    return u;
}

void dijkstra(int n, int src, int adjMatrix[n][n])
{
    bool visited[n];
    int dist[n];
    int parent[n]; // to keep track of the graph

    // Initialisation
    for (i = 0; i < n; i++)
    {
        visited[i] = false; // becomes true after relaxation
    }

    for (i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }

    // For Source Vertex
    dist[src] = 0; // to get the src vertex selected in the first step [min value]
    parent[src] = -1;

    // Relaxation
    for (i = 0; i < n - 1; i++)
    {
        // choose the min vertex
        int u = minVertex(n, dist, visited);

        // make it visited [can be done in  last step]
        visited[u] = true;

        // relax it
        /* Conditions :
            1. should have adjacent edge
            2. adjacent vertex (j) should not be in visited array
            3. check if dist[u] + adjMatrix[u][j] < dist[j]
            4. u should not be infinite; */
        for (j = 0; j < n; j++)
        {
            if (adjMatrix[u][j] != 0 && visited[j] != true && (dist[u] + adjMatrix[u][j]) < dist[j] && u != INT_MAX)
            {
                dist[j] = dist[u] + adjMatrix[u][j];
                parent[j] = u; // keeping track of the shortest path
            }
        }
    }

    // Printing the result
    // printf("\nShortest path : ");
    // for (i = 0; i < n; i++)
    // {
    //     printf("\n%d ----> %d", parent[i], i);
    // }
    for (i = 0; i < n; i++)
    {
        printf("\t%d",dist[i]);
    }
}

int main()
{
    int n;
    printf("Enter the no. of vertices : ");
    scanf("%d", &n);
    int src; // source
    printf("Enter the source vertex : ");
    scanf("%d", &src);

    int adjMatrix[n][n];
    // Input for adjacency matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Enter cost from %d to %d : ", i, j);
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    dijkstra(n, src, adjMatrix);
}
