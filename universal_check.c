/**VERIFICA UNIVERSALE **/
#include <stdio.h>
#define N  10
int main()
{
    int flagTrovato=0; /** FALSE **/
    int v[10];
    int i;
    /* INPUT ARRAY  */
    for(i=0;i<N;i++)
    {
        printf("Inserisci v[%d]\n",i);
        scanf("%d",&v[i]);
    }
    /** VERIFICA UNIVERSALE */
    i=0;/** inizializzo l'indice **/
    while(!flagTrovato && i<N)
    {
        if(v[i]!=0)
            flagTrovato=1;
        i++;
    }
    /** OUTPUT   **/
    if(flagTrovato==1)
        printf("Verifica universale fallita!\n");
    else
        printf("Verifica universale OK!\n");
    return 0;
}
