#include "donnees.h"

void lectureCSV() {
  int i, j = 0;
  char chaine[20];
  Bpm tab[100];

  FILE* fichier = fopen("csv_test.csv", "r");
  if (fichier == NULL) {
    printf("ERREUR, le fichier n'a pu être lu, arrêt du programme...");
    exit(0);
  }

  while(fgets(chaine, 20, fichier)) {
    sscanf(chaine, "%d;%d", &tab[j].temps, &tab[j].freq);
    j++;
  }

  for (i = 0; i < j; i++) {
    printf("Temps : %d ; Frequence : %d\n", tab[i].temps, tab[i].freq);
  }
}
