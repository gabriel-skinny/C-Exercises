#include <stdio.h>

void qsort(int[], int, int);

int main() {

  int numberArr[10] = {4, 1, 2, 8, 7, 4, 5, 6, 3, 9};

  for(int i = 0; i < 10; i++)
    printf("%d", numberArr[i]);


  printf("\nAfter Quick sotr\n");

  qsort(numberArr, 0, 9);

  for(int i = 0; i < 10; i++)
    printf("%d", numberArr[i]);

  return 0;  
}


void qsort(int arr[], int left, int rigth) {

  int i, last;
  void swap(int arr[], int i, int j);

  if (left >= rigth) 
    return; 
  
  swap(arr, left, (left + rigth) / 2);
  last = left;

  for (i = left + 1; i <=rigth; i++)  
    if (arr[i] < arr[left])
        swap(arr, ++last, i);
  
  swap(arr, left, last);

  qsort(arr, left, last - 1);
  qsort(arr, last + 1, rigth);
}

void swap(int arr[], int i, int j) {
  int temp;

  temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}