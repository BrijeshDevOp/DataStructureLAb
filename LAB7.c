// KRUSKAL'S ALGORITHM
#include <stdio.h>
#include <conio.h>

// Global variables for cost matrix, root array, and other necessary variables
int cost[10][10], root[10], min, edge = 1, mincost = 0;
int i, j, a, b, u, v, n;

void main()
{
    int i, j, n;
    // clrscr(); // Clear screen - commented out as it may not be needed in modern environments

    // Prompt user for number of vertices
    printf("\n Enter the Number of Vertices:\n");
    scanf("%d", &n);

    // Prompt user for the cost matrix
    printf("\n Enter the cost Matrix :\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &cost[i][j]);

    // Main loop to find the minimum spanning tree using Kruskal's algorithm
    while (edge < n)
    {
        // Initialize min to a large number (999) to find the minimum edge
        for (i = 1, min = 999; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                // Find the minimum cost edge in the graph
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i; // Store the row index
                    b = v = j; // Store the column index
                }
            }
        }

        // Find the root of the vertices u and v
        while (root[u])
        {
            u = root[u];
        }
        while (root[v])
        {
            v = root[v];
        }

        // If u and v are not in the same set, include this edge in the MST
        if (u != v)
        {
            printf("\n %d ----->(%d,%d) = %d", edge++, a, b, min);
            mincost += min; // Add the cost of this edge to the total minimum cost
            root[v] = u;    // Union the sets by setting root of v to u
        }

        // Mark this edge as processed by setting its cost to a large number
        cost[a][b] = cost[b][a] = 999;
    }

    // Output the total minimum cost of the spanning tree
    printf("\n\t Minimum Cost = %d", mincost);
    getch(); // Wait for user input before closing the program
}

/*

Kruskal's Algorithm

* Input the Graph: Read the number of vertices and the cost matrix.

* Initialize Structures: Initialize variables and arrays to track edges and their roots.

* Find Minimum Edge: In each iteration, find the edge with the minimum cost that connects two different sets.

* Cycle Detection: Use root array to check if the selected edge forms a cycle.

* Include Edge: If no cycle is formed, include the edge in the MST and update the root array.

* Repeat: Repeat until the MST includes n-1 edges.

* Output Result: Print the edges included in the MST and their total cost.

*/