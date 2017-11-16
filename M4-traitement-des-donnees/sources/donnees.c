#include "../headers/donnees.h"

// fonction de lecture et d'ecriture
// du fichier CSV dans un tableau
// de structure Bpm
int lectureEcritureCSV(Bpm *tab) {
  int compteur = 0;
  char chaine[20];
  // Ouverture du fichier et verification
  // de l'ouverture + lecture
  FILE* fichier = fopen("Battements.csv", "r");
  if (fichier == NULL) {
    printf("ERREUR, le fichier n'a pu être lu, arrêt du programme...");
    exit(0);
  }
  // tant que l'on peut lire une ligne dans le fichier
  // on enregistre la ligne et on la formate
  while(fgets(chaine, NBR_MAX_VALEURS, fichier)) {
    sscanf(chaine, "%d;%f", &tab[compteur].temps, &tab[compteur].freq);
    compteur++;
  }
  // retourne le nombre de ligne du fichier
  return compteur;
}
