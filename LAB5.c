/*
5.Write a C program to Implement the following searching techniques:
a. Linear Search.
b. Binary Search.
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int linearSearch(int arr[], int n, int x);
int binarySearch(int arr[], int left, int right, int x);
// Main function
void main()
{
	int n, x, choice, arr[20], i, result, result2;
	// clrscr();
	printf("Enter the number of elements in the array: ");
	scanf("%d", &n);
	// int arr[n];
	printf("Enter the elements of the array:\n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	while (1)
	{
		printf("\n\nSearching Techniques\n");
		printf("1. Linear Search\n");
		printf("2. Binary Search\n");
		printf("3. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("\nEnter the element to be searched: ");
			scanf("%d", &x);
			result = linearSearch(arr, n, x);
			if (result == -1)
			{
				printf("\nElement not found\n");
			}
			else
			{
				printf("\nElement found at index %d\n", result + 1);
			}
			break;
		case 2:
			printf("\nEnter the element to be searched: ");
			scanf("%d", &x);
			result2 = binarySearch(arr, 0, n - 1, x);
			if (result2 == -1)
			{
				printf("\nElement not found\n");
			}
			else
			{
				printf("\nElement found at index %d\n", result2 + 1);
			}
			break;
		case 3:
			exit(0);
			break;
		default:
			printf("\nInvalid choice\n");
		}
	}
	getch();
}

// Function to perform linear search
int linearSearch(int arr[], int n, int x)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (arr[i] == x)
		{
			return i;
		}
	}
	return -1;
}

// Function to perform binary search
int binarySearch(int arr[], int left, int right, int x)
{
	int mid;
	if (left > right)
	{
		return -1;
	}
	mid = left + (right - left) / 2;
	if (arr[mid] == x)
	{
		return mid;
	}
	else if (arr[mid] > x)
	{
		return binarySearch(arr, left, mid - 1, x);
	}
	else
	{
		return binarySearch(arr, mid + 1, right, x);
	}
}