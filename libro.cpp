/* Si crei la struttura libro, in cui ogni libro ha un codice numerico (numero intero) che lo caratterizza,
   un numero di pagine e un costo. Si memorizzino i dati di tre libri e si calcoli il costo medio per
   pagina dei libri e si stampino i dati dei tre libri in ordine crescente di costo per pagina.
*/

#include <iostream>

struct libro {
   std::string codice;
   int pagine;
   float prezzo;
};

float costo_pagina(float prezzo, int pagine) {
   return prezzo / pagine;
}

int main() {
   libro libri[3] = {
      {"0011", 20, 29.99},
      {"0964", 80, 14.99},
      {"0768", 239, 49.99}
   };

   float costi[sizeof(libri)/sizeof(libro)];
   for(int i = 0; i < sizeof(libri)/sizeof(libro); i++) {
      costi[i] = costo_pagina(libri[i].prezzo, libri[i].pagine);
   }

   // ordina libri per costo per pagina (bubble sort semplice)
   for(int i = 0; i < (sizeof(libri)/sizeof(libro))-1; i++) {
      for(int j = i+1; j < 3; j++) {
         if(costi[i] > costi[j]) {
            std::swap(costi[i], costi[j]);
            std::swap(libri[i], libri[j]);
         }
      }
   }

   // stampa libri ordinati
   std::cout << "Libri ordinati per costo per pagina:\n";
   for(int i = 0; i < sizeof(libri)/sizeof(libro); i++) {
      std::cout << "Codice: " << libri[i].codice
                << ", Pagine: " << libri[i].pagine
                << ", Prezzo: " << libri[i].prezzo
                << ", Costo/pagina: " << costi[i] << std::endl;
   }

   return 0;
}