#include "menu.h"

int afficherMenu () {
  int choix = -1;
  printf("\nMenu :\nSaisissez une tache à effectuer.\n");
  printf("0 - Pour quitter ce programme.\n");
  printf("1 - Afficher les données du fichier CSV.\n");
  printf("2 - Afficher les données dans l'ordre croissant du temps.\n");
  printf("3 - Afficher les données dans l'ordre décroissant du temps.\n");
  printf("4 - Afficher les données dans l'ordre croissant du pouls.\n");
  printf("5 - Afficher les données dans l'ordre décroissant du pouls.\n");
  printf("6 - Rechercher et afficher le pouls d'un temps donné.\n");
  printf("7 - Afficher la moyenne de pouls pour une plage de temps donné.\n");
  printf("8 - Afficher le nombre de lignes de données en mémoire.\n");
  printf("9 - Rechercher et afficher les max et min du pouls avec leur temps associé.\n\nVotre choix : ");
  scanf("%i", &choix);
  while (choix < 0 || choix > 9) {
    printf("Cette tâche n'existe pas, veuillez saisir une valeur de tâche valide : ");
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
    printf("La valeur saisie ne correspond à aucune tâche...");
    break;
  }
}
