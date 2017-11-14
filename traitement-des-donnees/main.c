#include "menu.h"

int main() {
  Bpm tab[NBR_MAX_VALEURS];
  int compteur = lectureEcritureCSV(tab);
  int choix = afficherMenu();
  while (choix != 0) {
    tacheChoisie(choix, tab, compteur);
    choix = afficherMenu();
  }
  printf("Au revoir et à bientôt !\n");
  return 0;
}


