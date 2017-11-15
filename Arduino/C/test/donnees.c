#include "donnees.h"

int lectureEcritureCSV(Bpm *tab) {
  int compteur = 0;
  char chaine[20];

  FILE* fichier = fopen("csv_test.csv", "r");
  if (fichier == NULL) {
    printf("ERREUR, le fichier n'a pu être lu, arrêt du programme...");
    exit(0);
  }

  while(fgets(chaine, NBR_MAX_VALEURS, fichier)) {
    sscanf(chaine, "%d;%d", &tab[compteur].temps, &tab[compteur].freq);
    compteur++;
  }

  return compteur;
}
