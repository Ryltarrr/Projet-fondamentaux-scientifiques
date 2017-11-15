#include "menu.h"

int afficherMenu () {
  int choix = -1;
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
  printf("9 - Rechercher et afficher les max et min du pouls avec leur temps associ�.\n\nVotre choix : ");
  scanf("%i", &choix);
  while (choix < 0 || choix > 9) {
    printf("Cette t�che n'existe pas, veuillez saisir une valeur de t�che valide : ");
    scanf("%i", &choix);
  }
  printf("\n");
  return choix;
}

void tacheChoisie(int choix, Bpm *tab, int compteur) {
  switch (choix) {
  case 1:
    afficherDonneesOrdreCSV(tab, compteur);
    break;
  case 2:
    afficherDonneesTempsCrois(tab, compteur);
    break;
  case 3:
    afficherDonneesTempsDecrois(tab, compteur);
    break;
  case 4:
    afficherDonneesPoulsCrois();
    break;
  case 5:
    afficherDonneesPoulsDecrois();
    break;
  case 6:
    afficherPoulsTempsDonne(tab, compteur);
    break;
  case 7:
    afficherMoyPoulsPlageTemps(tab, compteur);
    break;
  case 8:
    afficherNbrLignes(compteur);
    break;
  case 9:
    afficherMaxMin(tab, compteur);
    break;
  default:
    printf("La valeur saisie ne correspond � aucune t�che...");
    break;
  }
}
