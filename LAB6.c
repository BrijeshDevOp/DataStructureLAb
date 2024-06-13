#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Function to perform Bubble Sort in Ascending order
void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to perform Selection Sort in Descending order
void selectionSort(int arr[], int n)
{
    int i, j, max_idx, temp;
    for (i = 0; i < n - 1; i++)
    {
        // Find the maximum element in unsorted array
        max_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[max_idx])
            {
                max_idx = j;
            }
        }
        // Swap the found maximum element with the first element
        temp = arr[max_idx];
        arr[max_idx] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int arr[100];
    int n, i;
    // clrscr();
    printf("Enter the size of the Array\n");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\n------------------------------------------------\n");
    printf("Array before sorting:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n------------------------------------------------\n");
    // Perform Bubble Sort in Ascending order
    bubbleSort(arr, n);
    printf("\nArray after Bubble Sort in Ascending order:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }

    // Perform Selection Sort in Descending order
    selectionSort(arr, n);
    printf("\n------------------------------------------------\n");
    printf("\nArray after Selection Sort in Descending order:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }

    getch();
    return 0;
}