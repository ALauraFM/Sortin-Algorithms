#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para preencher o array com números aleatórios
void fillArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    array[i] = rand() % size; // Números aleatórios entre 0 e 99
  }
}

// Função para realizar a ordenação pelo método Bubble Sort
void bubbleSort(int array[], int size) {
  for (int step = 0; step < size - 1; ++step) {
    for (int i = 0; i < size - step - 1; ++i) {
      if (array[i] > array[i + 1]) {
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}

// Função para imprimir o array
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main() {
  int size;
  
  printf("Digite o tamanho do array: ");
  scanf("%d", &size);
  
  int data[size];
  
  // Inicialize a semente para números aleatórios com o tempo atual
  srand(time(NULL));
  
  fillArray(data, size);

  clock_t start_time = clock();
  
  bubbleSort(data, size);

  clock_t end_time = clock();
  double total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
  
  printf("Array gerado aleatoriamente:\n");
  printArray(data, size);
  printf("Sorted Array in Ascending Order:\n");
  printArray(data, size);
  printf("Tempo total de execução: %.6f segundos\n", total_time);
  
  return 0;
}
