#include "menu.h"

int afficherMenu () {
  int choix;
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
  printf("9 - Rechercher et afficher les max et min du pouls avec leur temps associé.\nVotre choix : ");
  scanf("%i", &choix);
  tacheChoisie(choix);
  return 0;
}

void tacheChoisie(int choix) {
  switch (choix) {
  case 0:
    printf("Au revoir et à bientôt...");
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
    printf("La valeur saisie ne correspond à aucune tâche...");
    afficherMenu();
    break;
  }
}
