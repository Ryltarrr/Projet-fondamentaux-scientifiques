#include "../headers/menu.h"

int main() {
  // tableau de structures contenant toutes
  // les valeurs du fichier CSV
  Bpm tab[NBR_MAX_VALEURS];
  // Permet de savoir le nombre de ligne
  // de donnees dans le fichier CSV
  int compteur = lectureEcritureCSV(tab);
  // affiche le menu et assigne le numero
  // de la tache à la variable choix
  int choix = afficherMenu();
  // tant que choix est different de 0
  // on effectue la tache choisie et
  // on redemande le choix de l'utilisateur
  while (choix != 0) {
    tacheChoisie(choix, tab, compteur);
    choix = afficherMenu();
  }
  printf("Au revoir et \x85 bient\x93t !\n");
  return 0;
}


