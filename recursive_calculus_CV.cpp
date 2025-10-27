//
// Created by Carlo Villoresi on 04/10/25
//

#include <iostream>   // libreria standard per input/output
#include <vector>     // libreria per usare il tipo std::vector
using namespace std;  // per evitare di scrivere std:: ogni volta


/**** DEFINIZIONE DELLA CLASSE ****/

class PROD_ARR {
private:
    vector<double> valori;               // vettore che contiene i numeri inseriti da tastiera

    /* funzione ricorsiva che calcola il prodotto dei valori positivi
       partendo dall'indice i fino alla fine dell'array */
    double prod_ricor(int i) {
        if (i == valori.size())          // caso base: se l’indice arriva alla fine
            return 1;                    // ritorna 1, perché 1 è l’elemento neutro della moltiplicazione

        if (valori[i] > 0)                          // se l’elemento corrente è positivo
            return valori[i] * prod_ricor(i + 1);   // lo moltiplico per il prodotto dei restanti elementi
        else
            return prod_ricor(i + 1);               // se è 0 o negativo, salta e va al successivo
    }

    // funzione che controlla se esistono numeri positivi nell’array
    bool val_pos() {
        for (double v : valori)           // scorre tutti gli elementi del vettore
            if (v > 0) return true;       // appena ne trova uno positivo ritorna true
        return false;                     // se non trova nessun positivo ritorna false
    }

public:
    // metodo per leggere i valori da tastiera
    void leggi_val() {
        int n;
        cout << "Quanti numeri vuoi inserire? ";
        cin >> n;                         // lettura dimensione dell’array
        valori.resize(n);                 // il vettore viene ridimensionato a n elementi

        cout << "Inserisci " << n << " numeri reali:\n";
        for (int i = 0; i < n; i++)       // ciclo per inserire ogni elemento
            cin >> valori[i];             // salvo il valore nel vettore
    }

    // metodo iterativo per calcolare il prodotto dei numeri positivi
    double prod_iter() {
        double prodotto = 1;              // inizializzo il prodotto a 1
        bool positivo = false;            // variabile per capire se ho trovato almeno un numero > 0

        for (double v : valori) {         // scorro tutti gli elementi
            if (v > 0) {                  // considero solo i positivi
                prodotto *= v;            // aggiorno il prodotto
                positivo = true;          // segno che esiste almeno un valore positivo
            }
        }
        // se non trova nessun valore positivo, return 0 (si usa operatore ternario per compattezza)
        return positivo ? prodotto : 0;
    }

    // metodo pubblico che gestisce il calcolo ricorsivo completo
    double prod_ricor_tot() {
        if (!val_pos())                // se non ci sono valori positivi
            return 0;                  // il prodotto deve essere 0
        return prod_ricor(0);        // altrimenti parte la ricorsione dall’indice 0
    }
};

/**** FUNZIONE PRINCIPALE ****/
int main() {
    PROD_ARR arr;                       // creo un oggetto della classe ArrayProdotto
    arr.leggi_val();                    // chiamo il metodo per leggere i valori da tastiera

    // calcolo e mostro i risultati con i due metodi
    cout << "\nProdotto iterativo: " << arr.prod_iter() << endl;
    cout << "Prodotto ricorsivo: " << arr.prod_ricor_tot() << endl;

    return 0;                             // fine del programma
}