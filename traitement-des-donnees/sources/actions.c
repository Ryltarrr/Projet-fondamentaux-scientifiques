#include "../headers/actions.h"

// affiche les valeurs du fichier CSV
// ligne par ligne
void afficherDonneesOrdreCSV(Bpm *tab, int compteur) {
  int i;
  printf("Donnees contenue dans le fichier CSV : \n");
  for (i = 1; i < compteur; i++) {
    printf("%d;%d\n", tab[i].temps, tab[i].freq);
  }
}

// affiche le pouls selon le temps croissant
void afficherDonneesTempsCrois(Bpm *tab, int compteur) {
  int i;
  printf("Valeur du pouls dans le temps croissant :\n");
  for (i = 1; i < compteur; i++) {
    printf("%d BPM \x85 %d ms\n", tab[i].freq, tab[i].temps);
  }
}

// affiche le pouls selon le temps decroissant
void afficherDonneesTempsDecrois(Bpm *tab, int compteur) {
  int i, j = 0;
  Bpm reversedTab[NBR_MAX_VALEURS];

  for (i = compteur-1; i > 0; i--) {
    reversedTab[j].temps = tab[i].temps;
    reversedTab[j].freq = tab[i].freq;
    j++;
  }
  for (i = 0; i < compteur-1; i++) {
    printf("%d BPM \x85 %d ms\n", reversedTab[i].freq, reversedTab[i].temps);
  }
}

// afficher les valeurs du pouls de maniere croissante
void afficherDonneesPoulsCrois(Bpm *tab, int compteur) {
  Bpm tabCpy[NBR_MAX_VALEURS];
  int i;
  for (i = 1; i < compteur; i++) {
    tabCpy[i].temps = tab[i].temps;
    tabCpy[i].freq = tab[i].freq;
  }
  insertionsort(tabCpy, compteur);
  for (i = 1; i < compteur; i++) {
    printf("%d BPM \x85 %d ms.\n", tabCpy[i].freq, tabCpy[i].temps);
  }
}

// affiche les valeurs du pouls de maniere decroissante
void afficherDonneesPoulsDecrois(Bpm *tab, int compteur) {
  Bpm tabCpy[NBR_MAX_VALEURS];
  Bpm reversedTab[NBR_MAX_VALEURS];

  int i, j = 0;
  for (i = 1; i < compteur; i++) {
    tabCpy[i].temps = tab[i].temps;
    tabCpy[i].freq = tab[i].freq;
  }
  insertionsort(tabCpy, compteur);

  for (i = compteur-1; i > 0; i--) {
    reversedTab[j].temps = tabCpy[i].temps;
    reversedTab[j].freq = tabCpy[i].freq;
    j++;
  }
  for (i = 0; i < compteur-1; i++) {
    printf("%d BPM \x85 %d ms.\n", reversedTab[i].freq, reversedTab[i].temps);
  }
}

// affiche le pouls pour une valeur de temps demande par l'utilisateur
void afficherPoulsTempsDonne(Bpm *tab, int compteur) {
  int i, tps, trouve = 0;
  printf("Saisissez une valeur de temps pour conna\x8Ctre le pouls correspondant : ");
  scanf("%i", &tps);
  for (i = 1; i < compteur; i++) {
    if (tab[i].temps == tps) {
      printf("Pour le temps de %i ms, le pouls est %i BPM.\n", tps, tab[i].freq);
      trouve = 1;
    }
  }
  if (trouve == 0) {
    printf("%i ms ne correspond pas \x85 une valeur de temps enregistree,\nVeuillez recommencer...\n", tps);
  }
}

// afficher la moyenne du pouls pour une plage de temps
// l'utilisateur donne la valeur de temps de depart et de fin
void afficherMoyPoulsPlageTemps(Bpm *tab, int compteur) {
  int i, debut, fin, dChange = 0, fChange = 0;
  float somme = 0.0;
  printf("Saisissez la valeur de debut de la plage : ");
  scanf("%i", &debut);
  printf("Saisissez la valeur de fin de la plage : ");
  scanf("%i", &fin);
  for (i = 1; i < compteur; i++) {
    if (dChange == 0 || fChange == 0) {
      if (tab[i].temps == debut) {
        debut = i;
        dChange = 1;
      }
      if (tab[i].temps == fin) {
        fin = i;
        fChange = 1;
      }
    }
  }
  if (dChange == 0 && fChange == 0) {
    printf("La borne inf\x82rieur et la borne sup\x82rieur sont incorrectes, veuillez recommencer...\n");
  } else if (dChange == 0) {
    printf("La borne inf\x82rieur est incorrecte, veuillez recommencer...\n");
  } else if (fChange == 0) {
    printf("La borne sup\x82rieur est incorrecte, veuillez recommencer...\n");
  } else {
    for (i = debut; i <= fin; i++) {
      somme += tab[i].freq;
    }
    somme /= fin - debut + 1;
    printf("\nLa moyenne de la valeur %i \x85 la valeur %i est de %f BPM.\n", debut, fin, somme);
  }
}

// affiche le nombre de lignes donnees dans le fichier CSV
void afficherNbrLignes(int compteur) {
  printf("Il y a %i lignes de donnees dans le fichier CSV.\n", compteur-1);
}

// affiche les valeur max et min du pouls
// dans le fichier CSV
void afficherMaxMin(Bpm *tab, int compteur) {
  int i, max = -1, min = 220, tpsMax, tpsMin;
  for (i = 1; i < compteur; i ++) {
    if (tab[i].freq > max) {
      max = tab[i].freq;
      tpsMax = tab[i].temps;
    }
    if (tab[i].freq < min) {
      min = tab[i].freq;
      tpsMin = tab[i].temps;
    }
  }
  printf("La valeur maximale est : %i BPM \x85 %i ms.\n", max, tpsMax);
  printf("La valeur minimale est : %i BPM \x85 %i ms.\n", min, tpsMin);
}

// fonction de tri par insertion pour trier les valeurs
// du pouls par ordre croissant et decroissant
void insertionsort(Bpm *tab, int compteur) {
  int i, j, vFreq, vTemps;

  for(i = 2; i < compteur; ++i) {
    vFreq = tab[i].freq;
    vTemps = tab[i].temps;
    j = i;
    while(j > 1 && tab[j - 1].freq > vFreq) {
      tab[j].freq = tab[j - 1].freq;
      tab[j].temps = tab[j - 1].temps;
      j = j - 1;
    }
    tab[j].freq = vFreq;
    tab[j].temps = vTemps;
  }

}
