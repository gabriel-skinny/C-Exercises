#include <stdio.h>

void swap(int*, int*);
void arrayChange(int[]);

int main(){

  int a, b;
  int arr[3] = {1, 5, 2};

  int *p1 = arr;
  int p2 = *(p1 + 2);

  a = 1;
  b = 2;

  printf("\n a before swap: %d \n b before swap: %d \n\n", a, b);

  swap(&a, &b);

  arrayChange(arr);

  printf("\n\n\n a after swap: %d \n b after swap: %d \n\n", a, b);

  printf("\n Array element %d", p1[2]);

  return 0;
}

void arrayChange(int arr[]) {
  printf("%d", *(++arr));
}

void swap(int* a, int* b){
  int tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;

} 