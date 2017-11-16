#include <stdio.h>
#include <stdlib.h>
// constante de preprocesseur
#define NBR_MAX_VALEURS 250

// Creation d'une structure de donnee
// compatible avec les informations
// recu dans le fichier CSV
typedef struct {
  int temps;
  float freq;
} Bpm;

// prototype de la fonction de lecture
// et d'ecriture du fichier CSV dans
// un tableau de structure Bpm
int lectureEcritureCSV(Bpm *tab);
