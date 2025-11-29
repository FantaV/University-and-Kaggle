#include <iostream>
using namespace std;
const int n = 8;
int T[n];//vettore rappresentativo delle 8 righe

// Controlla se la posizione è sicura
bool sicura(int regina, int riga){
    // Controlla se ogni regina precedente alla attuale
    // non si trovi sulla stessa riga o su una delle diagonali
    for (int i = 0; i < regina; i++){
        // ricava la posizione della regina nella riga iesima
        int rigaregi = T[i];
        // stessa riga o stessa diagonale
        if (rigaregi==riga ||
         rigaregi == riga - (regina - i) ||
         rigaregi == riga + (regina - i))
            return false;
    }
    return true;
}//fine sicura()

void tenta(int k){
    if (k < n){
        for (int i = 0; i < n; i++)
            // prima di inserire la k-esima regina in una riga
                // controlla se la posizione scelta è sicura
                    if (sicura(k, i)){
                        T[k] = i;
                        tenta(k + 1);// posiziona un'altra regina
                    }//fine if
    }else{
        // le n=8 regine sono posizionate (stampa)
        for (int i = 0; i < n; i++) cout << T[i] << " ";
        cout << endl;
    }//fine else
}//fine tenta

int main(){
    cout<<"inizio"<<endl;
    tenta(0);//regina iniziale in colonna 0
}