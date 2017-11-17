#include "donnees.h"
#include <string.h>
#include <math.h>

// prototypes des differentes actions
// possible sur les donnees enregistrees
void afficherDonneesOrdreCSV(Bpm *tab, int compteur);
void afficherDonneesTempsCrois(Bpm *tab, int compteur);
void afficherDonneesTempsDecrois(Bpm *tab, int compteur);
void afficherDonneesPoulsCrois(Bpm *tab, int compteur);
void afficherDonneesPoulsDecrois(Bpm *tab, int compteur);
void afficherPoulsTempsDonne(Bpm *tab, int compteur);
void afficherMoyPoulsPlageTemps(Bpm *tab, int compteur);
void afficherNbrLignes(int compteur);
void afficherMaxMin(Bpm *tab, int compteur);
void afficherMediane(Bpm *tab, int compteur);

void insertionsort(Bpm *tab, int compteur);

void swapF(float *a, float *b);
void swapI(int *a, int *b);
int partition(Bpm *tab, int lo, int hi);
void quicksort0(Bpm *tab, int lo, int hi);
void quicksort(Bpm *tab, int n);
