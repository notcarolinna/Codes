#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

void menu() {

  cout << "Escolha uma opcao:\n";
  cout << "1 - Bubble Sort\n";
  cout << "2 - Quick Sort\n";
  cout << "3 - Merge Sort\n";
  cout << "4 - Selection Sort\n";
  cout << "0 - Sair\n";
}

void bubble_sort(vector<int> &v) {
  int n = v.size();
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (v[j] > v[j + 1]) {
        swap(v[j], v[j + 1]);
      }
    }
  }
}

void quicksort(vector<int> &v, int esquerda, int direita) {
  int i = esquerda, j = direita;
  int pivo = v[(esquerda + direita) / 2];
  while (i <= j) {
    while (v[i] < pivo)
      i++;
    while (v[j] > pivo)
      j--;
    if (i <= j) {
      swap(v[i], v[j]);
      i++;
      j--;
    }
  }
  if (esquerda < j)
    quicksort(v, esquerda, j);
  if (i < direita)
    quicksort(v, i, direita);
}

void merge(vector<int> &v, int esquerda, int meio, int direita) {
  int i, j, k;
  int n1 = meio - esquerda + 1;
  int n2 = direita - meio;
  vector<int> L(n1), R(n2);
  for (i = 0; i < n1; i++)
    L[i] = v[esquerda + i];
  for (j = 0; j < n2; j++)
    R[j] = v[meio + 1 + j];
  i = 0;
  j = 0;
  k = esquerda;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      v[k] = L[i];
      i++;
    } else {
      v[k] = R[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    v[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    v[k] = R[j];
    j++;
    k++;
  }
}

void mergesort(vector<int> &v, int esquerda, int direita) {
  if (esquerda < direita) {
    int meio = esquerda + (direita - esquerda) / 2;
    mergesort(v, esquerda, meio);
    mergesort(v, meio + 1, direita);
    merge(v, esquerda, meio, direita);
  }
}

void selection_sort(vector<int> &v) {
  int n = v.size();
  for (int i = 0; i < n - 1; i++) {
    int min_idx = i;
    for (int j = i + 1; j < n; j++) {
      if (v[j] < v[min_idx]) {
        min_idx = j;
      }
    }
    swap(v[i], v[min_idx]);
  }
}

int main() {

  int opcao;
  int tamanho;
  vector<int> v;

  while (true) {

    menu();
    cout << "Opção: ";
    cin >> opcao;

    if (opcao == 0) {
      break;
    }

    cout << "Digite o tamanho do vetor: ";
    cin >> tamanho;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 10000);

    v.resize(tamanho);
    for (int i = 0; i < tamanho; i++) {
      v[i] = dis(gen);
    }

    auto inicio = chrono::high_resolution_clock::now();

    switch (opcao) {
    case 1:
      bubble_sort(v);
      cout << "Bubble Sort:\n";
      break;
    case 2:
      quicksort(v, 0, tamanho - 1);
      cout << "Quick Sort:\n";
      break;
    case 3:
      mergesort(v, 0, tamanho - 1);
      cout << "Merge Sort:\n";
      break;
    case 4:
      selection_sort(v);
      cout << "Selection Sort:\n";
      break;
    default:
      cout << "Opção inválida!\n";
      continue;
    }

    auto fim = chrono::high_resolution_clock::now();
    auto duracao =
        chrono::duration_cast<chrono::microseconds>(fim - inicio).count();
    cout << "Vetor ordenado em " << duracao << " microsegundos:\n";

    for (int x : v) {
      cout << x << " ";
    }
    cout << "\n";
  }

  return 0;
}
