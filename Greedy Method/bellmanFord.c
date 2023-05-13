// NOT WORKING

#include <stdio.h>
#include <stdlib.h>  //malloc
#include <limits.h>  //for INT_MAX and INT_MIN
#include <stdbool.h> //for boolean datatype
int i, j;
typedef struct node
{
    int u; // source
    int v; // destination
    int cost;
    struct node *next;
} node;

node *temp, *head = NULL;

void insertNode(int u, int v, int cost)
{
    // Making the newnode to be inserted
    node *newnode = malloc(sizeof(node));
    newnode->u = u;
    newnode->v = v;
    newnode->cost = cost;
    newnode->next = NULL;

    // Insertion
    if (head == NULL)
    {
        head = newnode = temp;
    }
    else
    {
        temp->next = newnode;
        temp = newnode;
    }
}

void displayEdgeList()
{
    temp = head;
    while (temp != NULL)
    {
        printf("%d --> %d --> %d", temp->u, temp->v, temp->cost);
        temp = temp->next;
    }
}

void bellmanFord(int n, int src, int adjMatrix[n][n])
{
    // Create a distance array
    int dist[n];
    for (i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[src] = 0; // Source vertex initialisation

    // Make a list of edges. Here i am using linked list, array with structure data type can also be used
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (adjMatrix[i][j] != 0)
            {
                insertNode(i, j, adjMatrix[i][j]);
            }
        }
    }

    displayEdgeList();

    // Traverse the list and RELAX the edges V-1 times (V=n)
    for (i = 0; i < n - 1; i++)
    {
        bool relaxed = false; // to stop the iteration if relaxation doesn't happen anymore
        temp = head;
        while (temp != NULL)
        {
            if (dist[temp->u] != INT_MAX && dist[temp->u] + temp->cost < dist[temp->v])
            {
                dist[temp->v] = dist[temp->u] + temp->cost;
                relaxed = true;
            }

            temp = temp->next;
        }

        if (relaxed == false)
        {
            break;
        }
    }

    // printing answer
    for (i = 0; i < n; i++)
    {
        printf("\t%d", dist[i]);
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

    bellmanFord(n, src, adjMatrix);
}
