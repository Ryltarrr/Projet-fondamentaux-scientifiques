#include "menu.h"

int main() {
  Bpm tab[NBR_MAX_VALEURS];
  int compteur = lectureEcritureCSV(tab);
  int choix = afficherMenu();
  while (choix != 0) {
    tacheChoisie(choix, tab, compteur);
    choix = afficherMenu();
  }
  printf("Au revoir et \x85 bient\x93t !\n");
  return 0;
}


