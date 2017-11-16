#include "menu.h"

int afficherMenu () {
  int choix = -1;
  printf("\nMenu :\nSaisissez un mode de fonctionnement \x85 effectuer.\n");
  printf("0 - Pour quitter ce programme.\n");
  printf("1 - Coeur allum\x82\n");
  printf("2 - Un sur deux\n");
  printf("3 - Un sur trois\n");
  printf("4 - Chenille\n");
  printf("5 - Chenille deux\n");
  printf("6 - Battement\n");
  printf("7 - Coeur bris\x82\n");
  printf("8 - LED1\n");
  printf("9 - LED2\n");
  printf("10 - LED3\n");
  printf("11 - LED4\n");
  printf("12 - LED5\n");
  printf("13 - LED6\n");
  printf("14 - LED7\n");
  printf("15 - LED8\n");
  printf("16 - LED9\n");
  printf("17 - LED10\n");
  scanf("%i", &choix);

  while (choix < 0 || choix > 17) {
    printf("Cette tache n'existe pas, veuillez saisir une valeur de tache valide : ");
    scanf("%i", &choix);
  }
  printf("\n");
  return choix;
}

void tacheChoisie(int choix) {
  switch (choix) {
  case 1:
    CoeurAllume();
    break;
  case 2:
    UnSurDeux();
    break;
  case 3:
    UnSurtrois();
    break;
  case 4:
    Chenille();
    break;
  case 5:
    ChenilleDeux();
    break;
  case 6:
    Battement();
    break;
  case 7:
    CoeurBrise();
    break;
  case 8:
    LED1();
    break;
  case 9:
    LED2();
    break;
  case 10:
    LED3();
    break;
  case 11:
    LED4();
    break;
  case 12:
    LED5();
    break;
  case 13:
    LED6();
    break;
  case 14:
    LED7();
    break;
  case 15:
    LED8();
    break;
  case 16:
    LED9();
    break;
  case 17:
    LED10();
    break;


  default:
    printf("La valeur saisie ne correspond \x85 aucun mode...");
    break;
  }
}
