#include <cstdlib>
#include <ctime>
#include <iostream>

#define MAX 2000000

void swim(int v[], int k);
void put(int v[], int *size, int data);
void sink(int v[], int size, int k);
int get(int v[], int *size);
void print(int v[], int size, int b, int elem, int sp);
void sort(int v[], int size);

void swim(int v[], int k) {
  while (k > 1 && v[k / 2] < v[k]) {
    int tmp = v[k];
    v[k] = v[k / 2];
    v[k / 2] = tmp;
    k = k / 2;
  }
}

void put(int v[], int *size, int data) {
  v[*size] = data;
  swim(v, *size);
  (*size)++;
}

void sink(int v[], int size, int k) {
  while (2 * k <= size) {
    int j = 2 * k;
    if (j < size && v[j] < v[j + 1])
      j++;
    if (v[k] >= v[j])
      break;
    int tmp = v[k];
    v[k] = v[j];
    v[j] = tmp;
    k = j;
  }
}

int get(int v[], int *size) {
  int res = v[1];
  v[1] = v[--(*size)];
  sink(v, *size, 1);
  return res;
}

void print(int v[], int size, int b, int elem, int sp) {
  int i, j;

  for (j = 1; j < size; j++)
    std::cout << v[j] << " ";
  std::cout << "\n";

  while (1) {
    for (j = 0; j <= sp / 2; j++)
      std::cout << " ";
    for (i = b; i < b + elem; i++) {
      if (i == size)
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

void sort(int v[], int size) {
  for (int i = size / 2; i >= 1; i--) {
    sink(v, size, i);
  }
  for (int i = size; i > 1; i--) {
    int tmp = v[1];
    v[1] = v[i];
    v[i] = tmp;
    sink(v, i - 1, 1);
  }
}

int main() {
  // Initialize random generator
  std::srand(std::time(0));

  int v[MAX + 1];
  v[1] = 0; // Position 0 is not used
  int size = 1;

  for (int i = 0; i < MAX; i++)
    put(v, &size, std::rand() % (MAX * 10)); // Fill randomly

  // print(v, size, 1, 1, 64);
  // std::cout << "\n";

  // Sort
  long start = clock();
  sort(v, size);
  long end = clock();

  // std::cout << "\nSorted:\n";
  // for (int i = 1; i < size; i++)
  //     std::cout << v[i] << " ";
  // std::cout << "\n";

  std::cout << "Time for " << MAX << " elements: " << (end - start) << " ns\n";

  return 0;
}
