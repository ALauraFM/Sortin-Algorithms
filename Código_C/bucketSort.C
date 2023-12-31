#include <stdio.h>
#include <stdlib.h>

#define NARRAY 7    // Tamanho do array
#define NBUCKET 7   // Numero de buckets
#define INTERVAL 10 // Intervalo de cada bucket

struct Node
{
  int data;
  struct Node *next;
};

void BucketSort(int arr[]);
struct Node *InsertionSort(struct Node *list);
void print(int arr[]);
void printBuckets(struct Node *list);
int getBucketIndex(int value);

void BucketSort(int arr[])
{
  int i, j;
  struct Node **buckets;

  // Criar os buckets e alocar a memória deles
  buckets = (struct Node **)calloc(NBUCKET, sizeof(struct Node *));

  // Preencher os buckets com seus respectivos elementos
  for (i = 0; i < NARRAY; ++i) {
    struct Node *current;
    int pos = getBucketIndex(arr[i]); // Funcao que calcula o bucket apropriado
    current = (struct Node *)malloc(sizeof(struct Node));
    current->data = arr[i];
    current->next = buckets[pos];
    buckets[pos] = current;
  }

  // Printa os buckets e seus elementos
  for (i = 0; i < NBUCKET; i++)
  {
    printf("Bucket[%d]: ", i);
    printBuckets(buckets[i]);
    printf("\n");
  }

  // Ordenando cada bucket
  for (i = 0; i < NBUCKET; ++i)
  {
    buckets[i] = InsertionSort(buckets[i]);
  }

  printf("-------------\n");
  printf("Bucktets after sorting\n");
  for (i = 0; i < NBUCKET; i++)
  {
    printf("Bucket[%d]: ", i);
    printBuckets(buckets[i]);
    printf("\n");
  }

  // Juntando os buckets em um array
  for (j = 0, i = 0; i < NBUCKET; ++i)
  {
    struct Node *node;
    node = buckets[i]; // Pega o primeiro elemento de cada bucket
    while (node)
    {
      arr[j++] = node->data;
      node = node->next;
    }
  }

  return;
}

// Funcao que calcula o bucket apropriado
int getBucketIndex(int value)
{
  return value / INTERVAL;
}

// Funcao para ordenar os elementos de um bucket
struct Node *InsertionSort(struct Node *list)
{
  struct Node *k, *nodeList;
  if (list == 0 || list->next == 0)
  {
    return list;
  }

  nodeList = list;
  k = list->next;
  nodeList->next = 0;
  while (k != 0)
  {
    struct Node *ptr;
    if (nodeList->data > k->data)
    {
      struct Node *tmp;
      tmp = k;
      k = k->next;
      tmp->next = nodeList;
      nodeList = tmp;
      continue;
    }

    for (ptr = nodeList; ptr->next != 0; ptr = ptr->next)
    {
      if (ptr->next->data > k->data)
        break;
    }

    if (ptr->next != 0)
    {
      struct Node *tmp;
      tmp = k;
      k = k->next;
      tmp->next = ptr->next;
      ptr->next = tmp;
      continue;
    }
    else
    {
      ptr->next = k;
      k = k->next;
      ptr->next->next = 0;
      continue;
    }
  }
  return nodeList;
}

void print(int ar[])
{
  int i;
  for (i = 0; i < NARRAY; ++i)
  {
    printf("%d ", ar[i]);
  }
  printf("\n");
}

// Print buckets
void printBuckets(struct Node *list)
{
  struct Node *cur = list;
  while (cur)
  {
    printf("%d ", cur->data);
    cur = cur->next;
  }
}

// Driver code
int main(void)
{
  int array[NARRAY] = {42, 32, 33, 52, 37, 47, 51};

  printf("Initial array: ");
  print(array);
  printf("-------------\n");

  BucketSort(array);
  printf("-------------\n");
  printf("Sorted array: ");
  print(array);
  return 0;
}