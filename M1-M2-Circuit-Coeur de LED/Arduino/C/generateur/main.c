#include <stdio.h>
#include <stdlib.h>
#include "coeur.h"
#include "coeur.c"

float a, b, c, r, n, p, w, l, x1, x2, x0, q;
int d, g, k,res,v,h;

int main()
{
    int op;
    int continuer = 1;
    do
    {
        printf("Choisir un mode de fonctionnement :\n");
        printf("1 - Coeur allume\n");
        printf("2 - Un sur deux\n");
        printf("3 - Un sur trois\n");
        printf("4 - Chenille\n");
        printf("5 - Factorielle\n");
        printf("6 - Racine carre\n");
        printf("7 - Racine nieme\n");
        printf("8 - Fonction trinome\n");
        printf("0 - Quitter\n\n");
        printf("- Choisissez:");
        scanf("%i", &op);

        switch (op)
        {
               case 1:
                    CoeurAllume(a,b);
               break;
               case 2:
                    substraction(a,b);
               break;
               case 3:
                    multiplication(a,b);
               break;
               case 4:
                    division(a,b);
               break;
               case 5:
                    fact(v);
               break;
               case 6:
                    racine_carree(q,a);
               break;
               case 7:
                    nth_root(n,a,p);
               break;
               case 8:
                    trinome(a,b,w);
               break;
               case 0:
               printf("\nAu revoir bonne journee");
               return 0;
               break;
               default :
                    printf("Desole, je n'ai pas compris votre decision\n");
               break;
        }
        printf("Continuer=1 ;Quitter=0 :");
        scanf("%d", &continuer);
    }
    while (continuer) ;
    system("PAUSE");
    printf("\nAu revoir bonne journee\n");
    return 0;
}
