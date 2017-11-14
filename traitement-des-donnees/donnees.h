#include <stdio.h>
#include <stdlib.h>
#define NBR_MAX_VALEURS 250

typedef struct {
  int temps;
  int freq;
} Bpm;

int lectureEcritureCSV(Bpm *tab);
