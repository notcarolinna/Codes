#include <cstdlib>
#include <ctime>
#include <iostream>

#define MAX 2000000

void swim(int v[], int pos);
void put(int v[], int *tam, int data);
void sink(int v[], int tam, int pos);
int get(int v[], int *tam);
void print(int v[], int tam, int b, int elem, int sp);
void sort(int v[], int tam);

void swim(int v[], int pos) {
  while (pos > 1 && v[pos / 2] < v[pos]) {
    int temp = v[pos];
    v[pos] = v[pos / 2];
    v[pos / 2] = temp;
    pos = pos / 2;
  }
}

void put(int v[], int *tam, int data) {
  v[*tam] = data;
  swim(v, *tam);
  (*tam)++;
}

void sink(int v[], int tam, int pos) {
  while (2 * pos <= tam) {
    int j = 2 * pos;
    if (j < tam && v[j] < v[j + 1])
      j++;
    if (v[pos] >= v[j])
      break;
    int temp = v[pos];
    v[pos] = v[j];
    v[j] = temp;
    pos = j;
  }
}

int get(int v[], int *tam) {
  int res = v[1];
  v[1] = v[--(*tam)];
  sink(v, *tam, 1);
  return res;
}

void print(int v[], int tam, int b, int elem, int sp) {
  int i, j;

  for (j = 1; j < tam; j++)
    std::cout << v[j] << " ";
  std::cout << "\n";

  while (1) {
    for (j = 0; j <= sp / 2; j++)
      std::cout << " ";
    for (i = b; i < b + elem; i++) {
      if (i == tam)
        return;
      std::cout << v[i];
      for (j = 0; j < sp; j++)
        std::cout << " ";
    }
    std::cout << "\n";
    b = b + elem;
    elem = 2 * elem;
    sp = sp / 2;
  }
}

void sort(int v[], int tam) {
  for (int i = tam / 2; i >= 1; i--) {
    sink(v, tam, i);
  }
  for (int i = tam; i > 1; i--) {
    int temp = v[1];
    v[1] = v[i];
    v[i] = temp;
    sink(v, i - 1, 1);
  }
}

int main() {
  std::srand(std::time(0));

  int v[MAX + 1];
  v[1] = 0; 
  int tam = 1;

  for (int i = 0; i < MAX; i++)
  put(v, &tam, std::rand() % (MAX * 10)); 
  long start = clock();
  sort(v, tam);
  long end = clock();
  
  std::cout << "Time for " << MAX << " elements: " << (end - start) << " ns\n";

  return 0;
}
