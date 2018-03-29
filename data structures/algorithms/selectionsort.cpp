// C program for implementation of selection sort
#include <stdio.h>
// #include <cstdlib>
using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++) {
          if (arr[j] < arr[min_idx])
            min_idx = j;
       }
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

int main() {
  int* arr;
  arr = new int[5];
  for (size_t i = 0; i < 5; i++) {
    arr[i] = i;
    // arr[i] = rand() % 10 + 1;
    std::cout << arr[i] << " ";
  }

  selectionSort(arr)
}
