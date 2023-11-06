#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// Function to find the partition position
int partition(int array[], int low, int high) {
  int pivot = array[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}

// Function to print array elements
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

// Function to generate random elements
void generateRandomArray(int array[], int size) {
  srand(time(NULL));
  for (int i = 0; i < size; ++i) {
    array[i] = rand() % size; // You can adjust the range as needed
  }
}

int main() {
  int n;
  printf("Digite o número de elementos no array: ");
  scanf("%d", &n);

  int data[n];
  generateRandomArray(data, n);

  //printf("Array não ordenado:\n");
  //printArray(data, n);

  clock_t start_time = clock();
  clock_t end_time = clock();
  double total_time = (double)(end_time - start_time) * 1000.0 / CLOCKS_PER_SEC;

  quickSort(data, 0, n - 1);

  printf("Array ordenado em ordem crescente:\n");
  printArray(data, n);
  printf("Tempo total de execução: %.2f milissegundos\n", total_time);
}
