#include <stdio.h>
#include <stdlib.h>

void inputArray(int arr[], int n);
void printArray(int arr[], int n);

// TC: O(N)
// SC: O(1)
int linear_search(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

// TC: O(log(N)), here log is with base 2
// SC: O(1)
int binary_search(int arr[], int n, int target)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    // int *arr = (int *)malloc(sizeof(int) * n);
    int arr[100];
    if (n > 100)
    {
        printf("MAX SIZE EXCEED");
        exit(1);
    }

    inputArray(arr, n);
    printArray(arr, n);

    int target;
    printf("Enter target: ");
    scanf("%d", &target);

    printf("Element found at index(linear): %d\n", linear_search(arr, n, target));
    printf("Element found at index(binary): %d\n", binary_search(arr, n, target));

    return 0;
}

void inputArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i);
        scanf("%d", &arr[i]);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}