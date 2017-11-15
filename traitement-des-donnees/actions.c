#include "actions.h"

void afficherDonneesOrdreCSV(Bpm *tab, int compteur) {
  int i;
  printf("Données contenue dans le fichier CSV : \n");
  for (i = 1; i < compteur; i++) {
    printf("%d;%d\n", tab[i].temps, tab[i].freq);
  }
}

void afficherDonneesTempsCrois(Bpm *tab, int compteur) {
  int i;
  printf("Valeur du pouls dans le temps croissant :\n");
  for (i = 1; i < compteur; i++) {
    printf("%d BPM\n", tab[i].freq);
  }
}

void afficherDonneesTempsDecrois(Bpm *tab, int compteur) {
  int i, j = 0;
  Bpm reversedTab[NBR_MAX_VALEURS];

  for (i = compteur-1; i > 0; i--) {
    reversedTab[j].temps = tab[i].temps;
    reversedTab[j].freq = tab[i].freq;
    j++;
  }
  for (i = 0; i < compteur-1; i++) {
    printf("%d BPM\n", reversedTab[i].freq);
  }
}

void afficherDonneesPoulsCrois() {
  printf("\nA\n");
}

void afficherDonneesPoulsDecrois() {
  printf("\nA\n");
}

void afficherPoulsTempsDonne(Bpm *tab, int compteur) {
  int i, tps, trouve = 0;
  printf("Saisissez une valeur de temps pour connaître le pouls correspondant : ");
  scanf("%i", &tps);
  for (i = 1; i < compteur; i++) {
    if (tab[i].temps == tps) {
      printf("Pour le temps de %i millisecondes, le pouls est %i BPM.\n", tps, tab[i].freq);
      trouve = 1;
    }
  }
  if (trouve == 0) {
    printf("Désolé %i millisecondes ne correspond pas à une valeur de temps enregistrée.\n", tps);
  }
}

void afficherMoyPoulsPlageTemps(Bpm *tab, int compteur) {
  int i, debut, fin, dChange = 0, fChange = 0;
  float somme = 0.0;
  printf("Saisissez la valeur de début de la plage : ");
  scanf("%i", &debut);
  printf("Saisissez la valeur de fin de la plage : ");
  scanf("%i", &fin);
  for (i = 1; i < compteur; i++) {
    if (dChange == 0 || fChange == 0) {
      if (tab[i].temps == debut) {
        debut = i;
        dChange = 1;
      }
      if (tab[i].temps == fin) {
        fin = i;
        fChange = 1;
      }
    }
  }
  if (dChange == 0 && fChange == 0) {
    printf("La borne inférieur et la borne supérieur sont incorrectes, veuillez recommencer...\n");
  } else if (dChange == 0) {
    printf("La borne inférieur est incorrecte, veuillez recommencer...\n");
  } else if (fChange == 0) {
    printf("La borne supérieur est incorrecte, veuillez recommencer...\n");
  } else {
    for (i = debut; i <= fin; i++) {
      somme += tab[i].freq;
    }
    somme /= fin - debut + 1;
    printf("\nLa moyenne de %i à %i millisecondes est de %f BPM.\n", debut, fin, somme);
  }
}

void afficherNbrLignes(int compteur) {
  printf("Il y a %i lignes de données dans le fichier CSV.\n", compteur-1);
}

void afficherMaxMin(Bpm *tab, int compteur) {
  int i, max = -1, min = 220, tpsMax, tpsMin;
  for (i = 1; i < compteur; i ++) {
    if (tab[i].freq > max) {
      max = tab[i].freq;
      tpsMax = tab[i].temps;
    }
    if (tab[i].freq < min) {
      min = tab[i].freq;
      tpsMin = tab[i].temps;
    }
  }
  printf("La valeur maximale est : %i BPM à %i millisecondes.\n", max, tpsMax);
  printf("La valeur minimale est : %i BPM à %i millisecondes.\n", min, tpsMin);
}
/*
void insertionsort(Bpm *tab, int compteur) {
  int i, j, v;

  for(i = 2; i < n; ++i) {
    v = tab[i].freq;
    j = i;
    while(j > 0 && tab[j - 1].freq > v) {
      tab[j].freq = tab[j - 1].freq;
      j = j - 1;
    }
    l[j] = v;
  }

}
*/
