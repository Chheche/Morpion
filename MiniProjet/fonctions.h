
void afficherInterface(int taille, int *matrice[taille][taille]);
// permet d'afficher la première fois ds la console la grille de jeu et de creer une matrice en 2 dimensions équivalente à cette grille
// prends en param la taille de la grille rentree par le joueur et un pointeur vers la matrice à initialiser => met toutes les cases à -1
// retourne la grille dans la console


void modifierInterface(int taille, int matrice[taille][taille]);
// permet de modifier la grille qui apparait ds la console en lisant la matrice
// prends en param la taille de la grille, la matrice qu'il faut lire pour adapter la grille ds console
// retourne la grille modifiee dans la console


void demanderCase(int taille, int *matrice[taille][taille], int joueur, int *x, int *y);
// demande au joueur humain les coordonees de la case à remplir
// prends en param la taille de la matrice, un pointeur vers la matrice à modifier, le numero du joueur, un pointeur vers les coordonnées x et y qui serviront ds tout le programme
// appelle la fonction choixCaseJoueur tant que cette dernière n'est pas correcte


int choixCaseJoueur(int taille, int x, int y, int matrice[taille][taille], int joueur);
// vérifie si les coordonnes rentree par le joueur sont correcte
// prends en param la taille de la matrice, les coordonnees x et y, la matrice , le numéro du joueur
// appelle la fct modifierInterface et retourne 100 si correcte , sinon retourne -100

int choixCaseOrdi(int taille, int x, int y, int matrice[taille][taille], int joueur);
// verifie que les nombres random générés par l'ordi soit corrects
// prends en param la taille de la matrice, les coordonnees x et y, la matrice , le numéro du joueur
// appelle la fct modifierInterface et retourne 100 si correcte , sinon retourne -100


int conditionVictoire(int taille, int *matrice[taille][taille], int joueur);
// permet de déterminer si un des joueurs a gagner (aligner 3 points)
// prends en param la taille de la matrice, un pointeur vers la matrice, le numero du joueur
// retourne 1 si qqu a gagner, 0 sinon


int parcourirMatrice(int taille, int matrice[taille][taille], int cpt, int numeroJoueur);
// permet de parcourir la matrice pour voir si 3 point sont aligés
// prends en param la taille de la matrice, la matrice a analyser, un compteur pour voir si les points sont alignés, le numéro qui doit être aligné 3 fois ds la matrice
// retourne 1 si 3 points sont alignés, 0 sinon


int matchNull(int taille, int *matrice[taille][taille]);
// permet de dire si toute les cases sont remplis
// prends en param la taille de la matrice, un pointeur vers la matrice a inspecter
// retourne 1 si toute les cases sont remplies, 0 sinon


int afficherMenu(int *choix);
// permet d'afficher le menu au debut et a la fin dune partie
// prends en param un pointeur vers le choix de l'utilisateur
// retourne 0 si le joueur veux quitter, 1 si le joueur veux rejouer


void afficherStats(int *cptPartie1, int *cptVict1, int *cptDef1, int *cptPartie2, int *cptVict2, int *cptDef2, int *heures, int *minutes, int *secondes);
// permet d'afficher les stats du joueur
// prends en param un pointeur vers le nombre de partie totale avec joueur 1 et 2, un pointeur vers le nombre de victoire avec joueur 1 et 2, un pointeur vers le nombre de défaite avec joueur 1 et 2 et des pointeurs vers le nombres d'heures de min et de s jouer en tout
// affiche les stats ds la console


void verifierExistenceFichier(char nom[]);
// vérifie si le fichier demandé existe
// prends en param le nom du fichier
// appelle creerFichier si le fichier n'existe pas, fait rien sinon


void creerFichier(char nom[]);
// creer le fichier si pas déja creer
// prends en param le nom du fichier
// retourne rien


void lireFichier(char nom[], int *cptPartie1, int *cptVictoire1, int *cptDefaite1, int *cptPartie2, int *cptVictoire2, int *cptDefaite2, int *heures, int *minutes, int *secondes);
// lis les stats du joueur stocker dans un fichier
// prends en param le nom du fichier, un pointeur vers les meme stats que afficherStats
// ne retourne rien


void ecrireFichier(char nom[], int *cptPartie1, int *cptVictoire1, int *cptDefaite1, int *cptPartie2, int *cptVictoire2, int *cptDefaite2, int *heures, int *minutes, int *secondes);
// mets a jours les stats ds le dossier
// prends en param la meme chose que lireFichier
// retourne rien


long calculerTempsActuel();
// permet de retourner le temps actuel
// prends pas de param
// retourne un long


void afficherTempsPartie(long debut, long fin, int *tempsTotalH, int *tempsTotalM, int *tempsTotalS);
// permet d afficher la duree de la partie et le temps total jouer
// prends en param la date de debut en secondes, la date de fin en secondes et un pointeur vers le temps en heures, minutes et secondes totales jouees
// affiche ds la console, ne retourne rien


void jouerBot(long debutPartie, long finPartie, int taille, int *tempsTotalHeures, int *tempsTotalMinutes, int *tempsTotalSecondes, int *cptPartie1, int *cptPartie2, int *cptVictoire1, int *cptVictoire2, int *cptDefaite1, int *cptDefaite2, int *partie, char fichier[]);
// permet de jouer la partie contre un bot en regroupant toutes les fonctionnalités
// prends en param tous les paramètres du main
// retourne rien


void jouerHumain(long debutPartie, long finPartie, int taille, int *tempsTotalHeures, int *tempsTotalMinutes, int *tempsTotalSecondes, int *cptPartie1, int *cptPartie2, int *cptVictoire1, int *cptVictoire2, int *cptDefaite1, int *cptDefaite2, int *partie, char fichier[]);
// permet de jouer la partie contre un humain sur ce meme PC en regroupant toutes les fonctionnalités
// prends en param tous les paramètres du main
// retourne rien
