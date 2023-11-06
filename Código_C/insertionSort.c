#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print an array
void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void insertionSort(int array[], int size) {
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;

    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
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

  printf("Array gerado aleatoriamente:\n");
  printArray(data, n);
  clock_t start_time = clock();
  
  insertionSort(data, n);

  clock_t end_time = clock();
  double total_time = (double)(end_time - start_time) * 1000.0 / CLOCKS_PER_SEC;

  printf("Array ordenado em ordem crescente:\n");
  printArray(data, n);
  printf("Tempo total de execução: %.2f milissegundos\n", total_time);
}
