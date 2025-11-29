#include <iostream>
using namespace std;

void Hanoi (int n, int p1, int p2, int p3) {
    if (n == 1) {
    cout<<" muovi un disco da "<<p1<<" a "<<p3<<endl;
    return;
}
    else {
        Hanoi(n-1,p1, p3, p2);
        Hanoi(1,p1,p2,p3);
        Hanoi(n-1,p2, p1, p3);
    }
}

int main(void)
{
    int dischi; /* numero di dischi */
    int s, d, t; /* pali sorgente e destinazione */
    cout<<"Numero di dischi? ";
    cin>>dischi;
    cout<<"Palo sorgente 1 [1, 2 o 3] ";
    cout<<"Palo destinazione 3 [1, 2 o 3] ";
    cout<<"Palo ausiliario 2 [1, 2 o 3] "<<endl;
    int n=dischi;
    cout<<"INIZIO"<<endl;
    Hanoi (n,1,2,3);
    cout<<"FINE"<<endl;

    return 0;
}