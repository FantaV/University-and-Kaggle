#include <iostream>
#include <algorithm>
using namespace std;


void printArray(int arr[], int size){
    int i;
    for(i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


/*
 * Scambia il contanuto delle due variabili
 * indirizzate dai puntatori x e y.
 */
void scambia(int *x, int *y) {
  int z;

  z = *x;
  *x = *y;
  *y = z;
  return;
}


/*  Pseudo-codifica dell'algoritmo
**
**  Selection_sort(V):
**    1. per ogni i=0, 1, 2, ..., n-1 ripeti:
**    2.   seleziona l'elemento minimo nel sotto array 
**         {V[i], V[i+1], ..., V[n-1]} e scambialo con l'elemento V[i]
**  END
*/

void selection_sort(int x[], int n) {
  int i, j, min;
  for (i=0; i<n-1; i++) {
    min = i;
    {for (j=i+1; j<n; j++)
      if (x[j]<x[min])
        min = j;}
    scambia(&x[i], &x[min]);
  }
  return;
}



/*Pseudo-codifica dell'algoritmo
**  Insertion_sort(V):
**    1. per ogni i=1, 2, ..., n-1 ripeti:
**    2.   poni x = V[i]
**    3.   inserisci x nella posizione corretta nel sotto-array
**         ordinato <V[0], ..., V[i-1]> spostando a destra
**         gli elementi V[k]>x (0≤k<i).
**  END*/
void insertion_sort(int x[], int n) {
  int i, j, app;
  for (i=1; i<n; i++) {
    app = x[i];
    j = i-1;
    while (j>=0 && x[j]>app) {
      x[j+1] = x[j];
      j--;
    }
    x[j+1] = app;
  }
  return;
}


/*Pseudo-codifica dell'algoritmo
**
**  Bubble_sort(V):
**    1. flag = 1
**    2. k = n-1
**    3. fintanto che flag = 1 e k>0 ripeti:
**    4.   flag = 0
**    5.   per i=0, ..., k-1 ripeti:
**    6.     se a(i)>a(i+1) allora scambia a(i) ed a(i+1) e poni flag=1
**    7.   k=k-1
**  END
*/

void bubble_sort(int x[], int n) {
  int flag=1, k=n-1, i;

  while (flag == 1 && k > 0) {
    flag = 0;
    for (i=0; i<k; i++) {
      if (x[i]>x[i+1]) {
        scambia(&x[i], &x[i+1]);
        flag = 1;
      }
    }
    k = k-1;
  }
  return;
}


int main() 
{
    int array[]= {72, 50, 10, 44, 20, 8, 15};
    int i; 

    int size = sizeof(array)/sizeof(array[0]);
    printArray(array, size);
    insertion_sort(array, size-1); 
    printArray(array, size);
    int array2[]= {72, 50, 10, 44, 20, 8, 15};
    printArray(array2, size);
    bubble_sort(array2, size-1);
    printArray(array2, size);
    int array3[]= {72, 50, 10, 44, 20, 8, 15};
    printArray(array3, size);
    selection_sort(array3, size-1);
    printArray(array3, size);
    return 0;
}