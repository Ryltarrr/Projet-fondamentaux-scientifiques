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

void afficherMoyPoulsPlageTemps() {
  printf("\nA\n");
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
  printf("La valeur maximale est : %i à %i millisecondes.\n", max, tpsMax);
  printf("La valeur minimale est : %i à %i millisecondes.\n", min, tpsMin);
}
