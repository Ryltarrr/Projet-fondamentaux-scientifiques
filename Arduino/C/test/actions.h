#include "donnees.h"
#include <string.h>
#include <math.h>

void afficherDonneesOrdreCSV(Bpm *tab, int compteur);
void afficherDonneesTempsCrois(Bpm *tab, int compteur);
void afficherDonneesTempsDecrois(Bpm *tab, int compteur);
void afficherDonneesPoulsCrois(Bpm *tab, int compteur);
void afficherDonneesPoulsDecrois(Bpm *tab, int compteur);
void afficherPoulsTempsDonne(Bpm *tab, int compteur);
void afficherMoyPoulsPlageTemps(Bpm *tab, int compteur);
void afficherNbrLignes(int compteur);
void afficherMaxMin(Bpm *tab, int compteur);
void insertionsort(Bpm *tab, int compteur);