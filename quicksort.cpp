#include <iostream>
#include <algorithm>
using namespace std;

// Partizionare usando lo schema di partizione Lomuto
int partition(int a[], int start, int end)
{
    // Scegli l'elemento più a destra come pivot dall'array
    int pivot = a[end];
    // gli elementi inferiori al pivot verranno spostati a sinistra di `pIndex`
    // gli elementi maggiori del pivot verranno spostati a destra di `pIndex`
    // elementi uguali possono andare in entrambi i modi
    int pIndex = start;
    // ogni volta che troviamo un elemento minore o uguale al pivot, `pIndex`
    // viene incrementato e quell'elemento viene posizionato prima del pivot.
    for (int i = start; i < end; i++)
    {
        if (a[i] <= pivot)
        {
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }
    // scambia `pIndex` con pivot
    swap (a[pIndex], a[end]);
    // restituisce `pIndex` (indice dell'elemento pivot)
    return pIndex;
}

// Quicksort
void quicksort(int a[], int start, int end)
{
    // condizione di base
    if (start >= end) {
        return;
    }
    // riorganizza gli elementi attraverso il pivot
    int pivot = partition(a, start, end);

    // ricorre su un subarray contenente elementi inferiori al pivot
    quicksort(a, start, pivot - 1);

    // ricorrono su subarray contenenti elementi che sono più del pivot
    quicksort(a, pivot + 1, end);
}

// Implementazione C++ dell'algoritmo Quicksort
int main()
{
    int a[] = { 1, 6, 7, 3, 2, 5, 8, 4 };
    int n = sizeof(a)/sizeof(a[0]);

    quicksort(a, 0, n - 1);

    // stampa l'array ordinato
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
