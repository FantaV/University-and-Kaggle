#include <iostream>
using namespace std;

const int D=100;

struct pila {
      int top ; //indice elemento top, se -1 pila vuota
      int elementi[D];  //elementi pila
};

pila CreaPila() {
      pila p;
      p.top=-1;
      return p;
}

int Top(pila p) {
      if (p.top==-1) cout<<"Pila vuota";
      else return p.elementi[p.top];
      return 0;
}

//L‟operazione primitiva Push può dar luogo ad un errore se l‟array è tutto pieno
void Push(int x, pila & p) {
      if (p.top==D-1)
            cout<<"Pila piena";
      else {
            p.elementi[p.top+1]=x;
            p.top++;
      }
}

void Pop(pila & p) {
      if (p.top==-1) cout<<"Pila vuota";
      else p.top--;
}


bool PilaVuota(pila p) {
      return (p.top==-1);
}

//Scriviamo una funzione per la memorizzazione di n valori letti da tastiera in una pila:
pila LeggiPila(int n) {
      cout<<"elemento "<<n<<"   ";
      pila p;
      p=CreaPila();
      int x;

      for (int i=0;i<n;i++) {
            cout<<"elemento "<<i<<"=";
            cin >> x;
            Push(x,p);
      }

      return p;
}
//Scriviamo una funzione per la stampa su video degli elementi di una pila. Notiamo che la funzione non svuota la pila perché il parametro è passato per valore: quindi la funzione svuota una copia della pila originaria.
void ScriviPila(pila p) {
      int x;
      while(!PilaVuota(p)) {
            x=Top(p);
            cout << x << "  ";
            Pop(p);
      }
}


int main() {
      cout << "Inizio" <<endl;
      pila p;
      int n;

      cout<<"per terminare inserire 1000"<<"   inserire numero di elementi "<<endl; cin>>n;
      while(n !=1000) {
            p = LeggiPila (n);

            ScriviPila(p);
            cout<<"xxxxxx";
            Push(99, p);
            Push(88, p);
            cout<<endl;
            ScriviPila(p);
            cout<<"yyyyyyy";
            Pop(p);
            cout<<"zzzzzzz";
            cout<<Top(p)<<endl;
            cout<<"KKKKKKK";
            cout<<endl;
            ScriviPila(p);
      }
      return 0;
}
