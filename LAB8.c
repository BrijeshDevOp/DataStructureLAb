#include <stdio.h>
#include <conio.h>
#define infinity 999

// Function implementing Dijkstra's algorithm
void dij(int n, int v, int cost[10][10], int dist[100])
{
	int i, u, count, w, flag[10], min;

	// Initialize the distance and flag arrays
	for (i = 1; i <= n; i++)
	{
		flag[i] = 0;		  // Initially, no nodes are visited
		dist[i] = cost[v][i]; // Distance from source to each node
	}

	count = 2; // Count of nodes processed, starting with the source

	// Main loop to find the shortest path
	while (count <= n)
	{
		min = infinity; // Initialize min to a large value

		// Find the unvisited node with the smallest distance
		for (w = 1; w <= n; w++)
		{
			if (dist[w] < min && !flag[w])
			{
				min = dist[w];
				u = w; // u is the node with the smallest distance
			}
		}

		flag[u] = 1; // Mark the node as visited
		count++;	 // Increment the count of processed nodes

		// Update the distance array
		for (w = 1; w <= n; w++)
		{
			if ((dist[u] + cost[u][w] < dist[w]) && !flag[w])
			{
				dist[w] = dist[u] + cost[u][w]; // Update the distance to node w
			}
		}
	}
}

void main()
{
	int n, v, i, j, cost[10][10], dist[10];

	// clrscr(); // Clear the screen (not needed in modern environments)

	// Prompt user for the number of nodes
	printf("\n Enter the number of nodes:");
	scanf("%d", &n);

	// Prompt user for the cost matrix
	printf("\n Enter the cost matrix:\n");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &cost[i][j]);
			if (cost[i][j] == 0)
			{
				cost[i][j] = infinity; // Replace 0 with infinity for non-edges
			}
		}
	}

	// Prompt user for the source node
	printf("\n Enter the source node:");
	scanf("%d", &v);

	// Call the Dijkstra function
	dij(n, v, cost, dist);

	// Print the shortest path from the source to all other nodes
	printf("\n Shortest path:\n");
	for (i = 1; i <= n; i++)
	{
		if (i != v)
		{
			printf("%d -> %d, cost = %d\n", v, i, dist[i]);
		}
	}

	getch(); // Wait for user input before closing the program
}

/*

Summary of Dijkstra's Algorithm

*Initialization: Set the distance of the source node to itself to 0 and all other distances to infinity.

*Relaxation: Iteratively update the shortest distances to each node by considering the shortest known path to each node.

*Selection: At each step, select the unvisited node with the smallest known distance and mark it as visited.

*Update: Update the distances to the neighboring nodes of the selected node.

*Repeat: Continue until all nodes are visited.

*/