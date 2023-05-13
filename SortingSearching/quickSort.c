#include <stdio.h>

void swap(int arr[], int first, int second)
{
    int temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
}

int partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int i = start,
        j = end;
    while (i < j)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap (arr,i,j);
        }
    }
    swap(arr, start, j);
    return j;
}

void quickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int loc = partition(arr, start, end);
        quickSort(arr, start, loc-1);
        quickSort(arr, loc+1, end);
    }
}

int main()
{
    int A[] = {1, 6, 8, 4, 6};
    quickSort(A, 0, 4);
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("\t%d", A[i]);
    }
    return 0;
}
