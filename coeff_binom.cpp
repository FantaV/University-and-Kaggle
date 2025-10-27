#include <iostream>
#include <cmath>

// funzione per calcolare combinazioni n choose k
long long coeff_bin(int n, int k) {      // doppio long per evitare saturazione ram
    if (k < 0 || k > n) return 0;   // Se k è negativo o maggiore di n, la combinazione non ha senso
    if (k == 0 || k == n) return 1;

    // inizializzazione numeratore e denominatore
    long long num = 1;
    long long den = 1;
    
    for (int i = 1; i <= k; ++i) {
        num *= (n - (k - i));
        den *= i;
    }
    return num / den;
}

// funzione che calcola la probabilità su una estrazione di 3 estrazioni
// w, k, r: quante di ciascun colore vogliamo ottenere nell’estrazione
double prob_three(int p1, int p2, int p3, int w, int k, int r) {
    int total = p1 + p2 + p3;
    int draw = w + k + r;
    if (draw != 3) {
        std::cerr << "Errore: numero estrazioni deve essere 3\n";  // std::cerr stampa l’errore sullo stream di errore (non su std::cout)
        return 0.0;
    }
    // numero di modi favorevoli estraendo (estrazione da 3 con 3 colori diversi):
    long long favorable = coeff_bin(p1, w) * coeff_bin(p2, k) * coeff_bin(p3, r);

    // numero totale di modi di estrarre 3 palline da total:
    long long totalWays = coeff_bin(total, draw);
    return static_cast<double>(favorable) / static_cast<double>(totalWays);
    // static_cast<double> serve per forzare la divisione in floating point
    // (altrimenti, essendo long long, farebbe una divisione intera e troncherebbe i decimali).
}

int main() {
    int p_wht = 8;
    int p_blk = 6;
    int p_red = 2;

    // probabilità di avere 3 palline bianche
    double w3 = prob_three(p_wht, p_blk, p_red, 3, 0, 0);
    std::cout << "Probabilità 3 bianche = " << w3 << "\n";

    // probabilità di avere 2 bianche e 1 nera
    double w2b1 = prob_three(p_wht, p_blk, p_red, 2, 1, 0);
    std::cout << "Probabilità 2 bianche e 1 nera = " << w2b1 << " (" << w2b1*100 << "%)" << "\n";

    // probabilità di avere 1 bianca, 1 nera, 1 rossa (arrotondato)
    double w1b1r1 = prob_three(p_wht, p_blk, p_red, 1, 1, 1);
    std::cout << "Probabilità 1 bianca, 1 nera, 1 rossa = "
              << std::round(w1b1r1 * 100) / 100
              << " (" << std::round(w1b1r1 * 10000) / 100 << "%)"
              << "\n";
    return 0;
}