#include<stdio.h>
#include<stdlib.h>
int main()
{
    //dichiarazione variabili
    int flag,m,app,n=10,i,v[10];
    //fase di input
    /* INPUT */
    for(i=0;i<n;i++)
    {
        printf("inserisci vettore[%d]\n",i);
        scanf("%d",&v[i]);
    }
    /*ORDINAMENTO */
    m=n;
    do
    {
        flag=0; /*mi dice se l'array è ordinato oppure no */
        for(i=0;i<n-1;i++)
        {
            if(v[i]>v[i+1])
                //swapping
            {
                app=v[i];
                v[i]=v[i+1];
                v[i+1]=app;
                flag=1;
            }
        }
        n--;
    }while(flag==1); /*finchè ci sono scambi */
    //OUTPUT
    for(i=0;i<m;i++)
        printf("v[%d]=%d\n",i,v[i]);
    return 0;
}

