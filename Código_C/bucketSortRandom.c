#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

struct Node {
  int data;
  struct Node *next;
};

void BucketSort(int arr[], int n, int num_buckets);
struct Node *InsertionSort(struct Node *list);
void print(int arr[], int n);
void printBuckets(struct Node *list);
int getBucketIndex(int value, int num_buckets);

void generateRandomArray(int arr[], int n, int max_value);
void swap(int *a, int *b);
int n, num_buckets;

int main(void) {

  printf("Digite o número de elementos no array: ");
  scanf("%d", &n);

  printf("Digite o número de baldes: ");
  scanf("%d", &num_buckets);

  int array[n];
  generateRandomArray(array, n, n);

  printf("Array gerado aleatoriamente:\n");
  print(array, n);

  clock_t start_time = clock();

  BucketSort(array, n, num_buckets);

  clock_t end_time = clock();
  double total_time = (double)(end_time - start_time) * 1000.0 / CLOCKS_PER_SEC; // Multiplica por 1000 para obter milissegundos

  printf("Array ordenado:\n");
  print(array, n);
  printf("Tempo total de execução: %.2f milissegundos\n", total_time);

  return 0;
}

void BucketSort(int arr[], int n, int num_buckets) {
  int i, j;
  struct Node **buckets;
  buckets = (struct Node **)calloc(num_buckets, sizeof(struct Node *));
   //cria baldes vazios e aloca a memória deles

  for (i = 0; i < n; ++i) {
    struct Node *current;
    int pos = getBucketIndex(arr[i], num_buckets);
    current = (struct Node *)malloc(sizeof(struct Node));
    current->data = arr[i];
    current->next = buckets[pos];
    buckets[pos] = current;
  }//aloca em cada balde, os elementos do array, baseado na função getindex

  /*for (i = 0; i < num_buckets; i++) {
    printf("Bucket[%d]: ", i);
    printBuckets(buckets[i]);
    printf("\n");
  }
  */
  

 
  for (i = 0; i < num_buckets; ++i) {
    buckets[i] = InsertionSort(buckets[i]);
  }//ordena os baldes usando a função insertion sort
  
  /*printf("-------------\n");
  printf("Bucktets after sorting\n");
  for (i = 0; i < num_buckets; i++) {
    printf("Bucket[%d]: ", i);
    printBuckets(buckets[i]);
    printf("\n");
  }*/
  

  for (j = 0, i = 0; i < num_buckets; ++i) { //loop pra percorrer todos os baldes, i - balde
    struct Node *node;
    node = buckets[i];
    while (node) { //loop pra percorrer todos os nós no balde
      arr[j++] = node->data;
      node = node->next;
    }//atribui à posição j do array, a informação do nó atual, é isso que vai reordenar os elementos de volta no array
  }

  for (i = 0; i < num_buckets; ++i) {
    struct Node *node = buckets[i];
    while (node) {
      struct Node *temp = node;
      node = node->next;
      free(temp);
    }
  } //libera o espaço alocado pelos nos

  free(buckets); //libera a memória do struct node
}

struct Node *InsertionSort(struct Node *list) {
  struct Node *k, *nodeList;
  if (list == NULL || list->next == NULL) {
    return list;
  }

  nodeList = list;
  k = list->next;
  nodeList->next = NULL;
  while (k != NULL) {
    struct Node *ptr;
    if (nodeList->data > k->data) {
      struct Node *tmp;
      tmp = k;
      k = k->next;
      tmp->next = nodeList;
      nodeList = tmp;
      continue;
    }

    for (ptr = nodeList; ptr->next != NULL; ptr = ptr->next) {
      if (ptr->next->data > k->data)
        break;
    }

    if (ptr->next != NULL) {
      struct Node *tmp;
      tmp = k;
      k = k->next;
      tmp->next = ptr->next;
      ptr->next = tmp;
      continue;
    } else {
      ptr->next = k;
      k = k->next;
      ptr->next->next = NULL;
      continue;
    }
  }
  return nodeList;
}


int getBucketIndex(int value, int num_buckets) {
  return (value * num_buckets) / n;
}


void print(int ar[], int n) {
  int i;
  for (i = 0; i < n; ++i) {
    printf("%d ", ar[i]);
  }
  printf("\n");
}

void printBuckets(struct Node *list) {
  struct Node *cur = list;
  while (cur) {
    printf("%d ", cur->data);
    cur = cur->next;
  }
}

void generateRandomArray(int arr[], int n, int max_value) {
  srand(time(NULL));
  for (int i = 0; i < n; ++i) {
    arr[i] = rand() % max_value;
  }
}
