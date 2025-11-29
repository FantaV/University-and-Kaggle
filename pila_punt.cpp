#include <iostream>
using namespace std;

struct rec
	{ int info;
	rec* next; };

typedef rec* pila;

pila CreaPila()
	{pila p;
	p=NULL;
	return p; }


bool PilaVuota(pila p)
	{return (p==NULL);}




void Push(int x, pila &p)
	 {rec* paux= new rec;
		    paux->info=x;
	       paux->next=p;
             p=paux; }

void Pop(pila & p)      {
		 if (p==NULL) cout<<"Pila vuota";
       		else
		{rec  * paux=p;
		p=p->next;
		delete paux ; } }

int Top(pila p)
{
		 if (p==NULL) cout<<"Pila vuota";
       		else return (p->info);
       		return 0;}



//Scriviamo una funzione per la memorizzazione di n valori letti da tastiera in una pila:

      void LeggiPila(int n, pila &p )
      {
            int x;
            for (int i=0;i<n;i++)
            {
                  cout<<"elemento ["<<i<<"]=";
                  cin >> x;
                  Push(x,p);
            };

      }



void Stampalista(pila piniz)
{pila p;
p=piniz;
cout<<"stampa lista"<<endl;
while(p !=NULL) {cout<<p->info<<endl;
 		p=p->next;  }
}

//fine while
//Scriviamo una funzione per la stampa su video degli elementi di una pila. Notiamo che la funzione non svuota la pila perché il parametro è passato per valore: quindi la funzione svuota una copia della pila originaria.



int main(){cout << "Inizio" <<endl;
pila p;
int n;

cout<<"per terminare inserire 1000"<<
"   inserire numero di elementi "<<endl;
cin>>n;
while(n !=1000)
{  p=CreaPila();
   LeggiPila (n, p);
 Stampalista(p);
 cout<<Top(p)<<endl;
 cout<<"KKKKKKK";
 Push(99, p);
 cout<<Top(p)<<endl;
 Push(88, p);
 cout<<Top(p)<<endl;
 cout<<endl;
 Stampalista(p);
 Pop(p);
 cout<<Top(p)<<endl;
 cout<<"zzzzzzz";
 Pop(p);
 cout<<Top(p)<<endl;
 cout<<"KKKKKKK";
  cout<<endl;
 Stampalista(p);

return 0;
}

}

