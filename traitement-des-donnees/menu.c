#include "menu.h"

int afficherMenu () {
  int choix;
  printf("\nMenu :\nSaisissez une tache � effectuer.\n");
  printf("0 - Pour quitter ce programme.\n");
  printf("1 - Afficher les donn�es du fichier CSV.\n");
  printf("2 - Afficher les donn�es dans l'ordre croissant du temps.\n");
  printf("3 - Afficher les donn�es dans l'ordre d�croissant du temps.\n");
  printf("4 - Afficher les donn�es dans l'ordre croissant du pouls.\n");
  printf("5 - Afficher les donn�es dans l'ordre d�croissant du pouls.\n");
  printf("6 - Rechercher et afficher le pouls d'un temps donn�.\n");
  printf("7 - Afficher la moyenne de pouls pour une plage de temps donn�.\n");
  printf("8 - Afficher le nombre de lignes de donn�es en m�moire.\n");
  printf("9 - Rechercher et afficher les max et min du pouls avec leur temps associ�.\nVotre choix : ");
  scanf("%i", &choix);
  tacheChoisie(choix);
  return 0;
}

void tacheChoisie(int choix) {
  switch (choix) {
  case 0:
    printf("Au revoir et � bient�t...");
    exit(0);
    break;
  case 1:
    afficherDonneesOrdreCSV();
    afficherMenu();
    break;
  case 2:
    afficherDonneesPoulsCrois();
    afficherMenu();
    break;
  case 3:
    afficherDonneesPoulsDecrois();
    afficherMenu();
    break;
  case 4:
    afficherDonneesTempsCrois();
    afficherMenu();
    break;
  case 5:
    afficherDonneesTempsDecrois();
    afficherMenu();
    break;
  case 6:
    afficherPoulsTempsDonne();
    afficherMenu();
    break;
  case 7:
    afficherMoyPoulsPlageTemps();
    afficherMenu();
    break;
  case 8:
    afficherNbrLignes();
    afficherMenu();
    break;
  case 9:
    afficherMaxMin();
    afficherMenu();
    break;
  default:
    printf("La valeur saisie ne correspond � aucune t�che...");
    afficherMenu();
    break;
  }
}
