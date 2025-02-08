#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void afficherInterface(int taille, int *matrice[taille][taille]){

    printf("\n");
    // creer l interface graphique dans console
    for(int k=0; k<taille; k++){
        printf("  %d  ", k+1);
    }

    printf("\n");

    for(int j=0; j<taille; j++){
        printf("%d", j+1);
        for(int i=0; i<taille; i++){
            printf("|");
            printf("___");
            printf("|");
        }
        printf("\n");
    }

    // initialise toute la matrice à -1
    for(int i=0; i<taille; i++){
        for(int j=0; j<taille; j++){
            matrice[i][j] = -1;
        }
    }
}




void modifierInterface(int taille, int matrice[taille][taille]){
    for(int k=0; k<taille; k++){
        printf("  %d  ", k+1);
    }

    printf("\n");

    for(int j=0; j<taille; j++){
        printf("%d", j+1);
        for(int i=0; i<taille; i++){
            printf("|");
            switch(matrice[j][i]){
                // pour joueur 1 on met des O et pour joueur 2 on met des X
                case 1:
                    printf(" O ");
                    break;
                case 2:
                    printf(" X ");
                    break;
                default:
                    printf("___");
                    break;
            }

            printf("|");
        }
        printf("\n");
    }

    printf("\n\n");
}



// demande au joueur de remplir la case de son choix
void demanderCase(int taille, int *matrice[taille][taille], int joueur, int *x, int *y){  // on met un pointeur pour modif direct la matrice => pas a mettre de return matrice

    int nombre = 0;
    printf("Entrer les coordonnees de la case a remplir (Ex: 12) : ");
    scanf("%d", &nombre);

    *x = nombre%10;
    *y = nombre/10;


    // choix du joueur
    while((choixCaseJoueur(taille, *x, *y, *matrice, joueur)) != 100){
        printf("Entrer les coordonnees de la case a remplir (Ex: 12) : ");
        scanf("%d", &nombre);

        *x = nombre%10;
        *y = nombre/10;
    }
}





// quand le joueur a rentrer les coordonnées d une case
int choixCaseJoueur(int taille, int x, int y, int matrice[taille][taille], int joueur){
    // on teste si les nombres sont bons
    if(x>0 && x<=taille && y>0 && y<=taille){
       // on regarde d'abord dans la matrice si c pas occupé
       if(matrice[x-1][y-1] == -1){
            // on change la valeur dans la matrice par un 1 pour joueur 1 et par 2 pour joueur 2
            switch(joueur){
                case 1:
                    matrice[x-1][y-1] = 1;
                    break;
                case 2:
                    matrice[x-1][y-1] = 2;
                    break;
            }


            // on change l'affichage graphique
            modifierInterface(taille, *matrice);
            return 100; // permet de dire que l'operation a reussie
       }
       else{
            printf("la case que vous avez rentree est deja remplie \n \n");
            return -100; // permet de dire que l'operation a echouee
       }
    }
    else{
        printf("la case que vous avez rentree n'existe pas \n \n");
        return -100; // permet de dire que l'operation a echouee
    }
}





int choixCaseOrdi(int taille, int x, int y, int matrice[taille][taille], int joueur){
    // on teste si les nombres sont bons
    if(x>=0 && x<taille && y>=0 && y<taille){
       // on regarde d'abord dans la matrice si c pas occupé
       if(matrice[x][y] == -1){
            // on change la valeur dans la matrice par un 1 pour joueur 1 et par 2 pour joueur 2
            switch(joueur){
                case 1:
                    matrice[x][y] = 1;
                    break;
                case 2:
                    matrice[x][y] = 2;
                    break;
            }

            // on change l'affichage graphique
            modifierInterface(taille, *matrice);
            return 100; // permet de dire que l'operation a reussie
       }
       else{
            return -100; // permet de dire que l'operation a echouee
       }
    }
    else{
        return -100; // permet de dire que l'operation a echouee
    }
}




int conditionVictoire(int taille, int *matrice[taille][taille]){
    int cpt1 = 0;
    int cpt2 = 0;

    if(parcourirMatrice(taille, *matrice, cpt1, 1) == 1) return 1;
    if(parcourirMatrice(taille, *matrice, cpt2, 2) == 1) return 2;

    cpt1 = 0;
    cpt2 = 0;

    return 0;
}




int parcourirMatrice(int taille, int matrice[taille][taille], int cpt, int joueur){
    int nombre = 0; // nombre qu il faut trouver aligner ds la grille (soit 1, soit 2)

    switch(joueur){
        case 1:
            nombre = 1;
            break;
        case 2:
            nombre = 2;
            break;
        default:
            printf("probleme de compteur ds Parcourir Matrice");
            break;
    }


    // si 3 sont alignés en --
    for(int i=0; i<taille; i++){
        for(int j=0; j<taille; j++){
            if(matrice[i][j] == nombre) cpt++;
        }
        if(cpt == 3){
            return 1;
        }
        cpt = 0;
    }

    // si 3 sont alignés en |
    for(int i=0; i<taille; i++){
        for(int j=0; j<taille; j++){
            if(matrice[j][i] == nombre) cpt++;
        }
        if(cpt == 3){
            return 1;
        }
        cpt = 0;
    }


    // si 3 sont alignés en \

    for(int i=0; i<taille; i++){
        if(matrice[i][i] == nombre) cpt++;
    }
    if(cpt == 3){
        return 1;
    }
    cpt = 0;


    // si 3 sont alignés en /
    for(int i=0; i<taille; i++){
        if(matrice[i][taille-1-i] == nombre) cpt++;
    }
    if(cpt == 3){
        return 1;
    }
    cpt = 0;

    return 0;
}


int matchNull(int taille, int matrice[taille][taille]){
    int cpt = 0;

    for(int i=0; i<taille; i++){
        for(int j=0; j<taille; j++){
            if(matrice[i][j] == -1){
                cpt++;
            }
        }
    }

    if(cpt == 0){
        printf("\nPersonne ne gagne, dommage !!!\n \n");
        return 1;
    }

    return 0;
}



int afficherMenu(int *choix){
    printf("Entrer votre choix : \n");
    printf("Jouer : 1\n");
    printf("Satistiques : 2\n");
    printf("Quitter : 0\n");
    scanf("%d", choix);


    while(*choix < 0 || *choix > 2){
        printf("\nEntrer votre choix : \n");
        printf("Jouer : 1\n");
        printf("Satistiques : 2\n");
        printf("Quitter : 0\n");
        scanf("%d", choix);
    }

    switch(*choix){
        case 0:
            return 0;
            break;
        case 1:
            system("cls"); // permet d'effacer la console
            return 1;
            break;
        case 2:
            return 2;
            break;
    }
}


void afficherStats(int *cptPartie1, int *cptVict1, int *cptDef1, int *cptPartie2, int *cptVict2, int *cptDef2, int *heures, int *minutes, int *secondes){
    int choix = 0;
    // permet d'effacer la console
    system("cls");

    printf("                          Temps total jouer : %dh %dmin %ds\n\n", *heures, *minutes, *secondes);

    printf("Parties jouees avec joueur 1 : %d             Parties jouees avec joueur 2 : %d  \n\n", *cptPartie1, *cptPartie2);
    printf("Nombre de victoires avec joueur 1 : %d        Nombre de victoires avec joueur 2 : %d \n", *cptVict1, *cptVict2);
    printf("Nombre de defaites avec joueur 1 : %d         Nombre de defaites avec joueur 2 : %d \n", *cptDef1, *cptDef2);

    printf("\n\nRevenir au Menu : 1\n");
    scanf("%d", &choix);

    while(choix != 1){
        printf("\nRevenir au Menu : 1\n");
        scanf("%d", &choix);
    }

    // permet d'effacer la console
    system("cls");
}




void verifierExistenceFichier(char nom[]){
    FILE* fichier = NULL;

    fichier = fopen(nom, "r");

    if(fichier == NULL){
        creerFichier(nom);
    }

    fclose(fichier);
}



void creerFichier(char nom[]){
    FILE* fichier = NULL;
    int nombre = 0;

    fichier = fopen(nom, "w");

    if (fichier != NULL)
    {
        for(int i=0; i<3; i++){
            fprintf(fichier, "%d  %d\n", nombre, nombre);
        }
        fprintf(fichier, "%d %d %d", nombre, nombre, nombre);
        fclose(fichier);
    }
    else
    {
        printf("Impossible de creer le fichier %s.txt", nom);
    }
}




void lireFichier(char nom[], int *cptPartie1, int *cptVictoire1, int *cptDefaite1, int *cptPartie2, int *cptVictoire2, int *cptDefaite2, int *heures, int *minutes, int *secondes){
    FILE * statistiques = NULL; // nom du fichier dans lequel on va stocker les statistiques
    int nombres[9] = {0};

    statistiques = fopen(nom, "r");

    if (statistiques != NULL)
    {
        int i = 0;
        fscanf(statistiques, "%d  %d\n", &nombres[i], &nombres[i+1]);
        *cptPartie1 = nombres[i];
        *cptPartie2 = nombres[i+1];
        i+=2;
        fscanf(statistiques, "%d  %d\n", &nombres[i], &nombres[i+1]);
        *cptVictoire1 = nombres[i];
        *cptVictoire2 = nombres[i+1];
        i+=2;
        fscanf(statistiques, "%d  %d\n", &nombres[i], &nombres[i+1]);
        *cptDefaite1 = nombres[i];
        *cptDefaite2 = nombres[i+1];
        i+=2;
        fscanf(statistiques, "%d %d %d", &nombres[i], &nombres[i+1], &nombres[i+2]);
        *heures = nombres[i];
        *minutes = nombres[i+1];
        *secondes = nombres[i+2];

        fclose(statistiques);
    }
    else
    {
        printf("Impossible d'ouvrir le fichier %s.txt", nom);
    }
}




void ecrireFichier(char nom[], int *cptPartie1, int *cptVictoire1, int *cptDefaite1, int *cptPartie2, int *cptVictoire2, int *cptDefaite2, int *heures, int *minutes, int *secondes){
    FILE* fichier = NULL;

    fichier = fopen(nom, "w+");

    if(fichier != NULL){
        fprintf(fichier, "%d  %d\n", *cptPartie1, *cptPartie2);
        fprintf(fichier, "%d  %d\n", *cptVictoire1, *cptVictoire2);
        fprintf(fichier, "%d  %d\n", *cptDefaite1, *cptDefaite2);
        fprintf(fichier, "%d %d %d", *heures, *minutes, *secondes);
        fclose(fichier);
    }
    else
        printf("impossible d'ecrire ds le fichier %s.txt", nom);
}



long calculerTempsActuel(){
    time_t t = time(NULL);
    return t;
}


void afficherTempsPartie(long debut, long fin, int *tempsTotalH, int *tempsTotalM, int *tempsTotalS){
    int heures = 0;
    int minutes = 0;
    int secondes = 0;
    long total = 0;

    total = fin - debut;
    heures = (int)(total/3600);
    minutes = (int)((total - heures*60)/60);
    secondes = total - minutes*60;

    printf("                  Temps partie : %dh %dmin %ds\n\n", heures, minutes, secondes);

    *tempsTotalH += heures;
    *tempsTotalM += minutes;
    *tempsTotalS += secondes;
}


void jouerBot(long debutPartie, long finPartie, int taille, int *tempsTotalHeures, int *tempsTotalMinutes, int *tempsTotalSecondes, int *cptPartie1, int *cptPartie2, int *cptVictoire1, int *cptVictoire2, int *cptDefaite1, int *cptDefaite2, int *partie, char fichier[]){

    int fin = 0; // permet de definir si la partie est finie ou pas: 0 = en cours, 1 = finie

    // on commence à lancer le chrono
    debutPartie = calculerTempsActuel();


    // creer matrice pour mettre les points (pas graphique)
    int matrice[taille][taille];

    afficherInterface(taille, &matrice);


     // dit quel joueur vous jouez
    int joueur = 0;
    printf("Voulez-vous etre le joueur 1 ou le joueur 2 : ");
    scanf("%d", &joueur);
    // regarde si joueur est correct
    while(joueur<1 || joueur>2){
        printf("\n Il ne peut y avoir que 2 joueur \n");
        printf("Voulez-vous etre le joueur 1 ou le joueur 2 : ");
        scanf("%d", &joueur);
    }




    int x=0, y=0;


    while(fin == 0){
        // joueur 1 joues tjs en 1er et joueur 2 tjs en 2eme
            switch(joueur){
                case 1:
                    // on verifie si le joueur 1 ou 2 a gagner
                    if(conditionVictoire(taille, &matrice) != 1 && conditionVictoire(taille, &matrice) != 2 && matchNull(taille, &matrice) != 1){
                        // demande au joueur de remplir la case de son choix
                        demanderCase(taille, &matrice, joueur, &x, &y);
                    }
                    // si qqu a gagner on arrete partie
                    else{
                        fin = 1;
                    }

                    if(conditionVictoire(taille, &matrice) != 1 && conditionVictoire(taille, &matrice) != 2 && matchNull(taille, &matrice) != 1){
                        // puis l ordi joue => choix de l'ordi faut mettre un random
                        x = rand() % taille; // entre 0 et taille-1
                        y = rand() % taille; // entre 0 et taille-1

                        while(choixCaseOrdi(taille, x, y, &matrice, 2) != 100){
                            x = rand() % taille;
                            y = rand() % taille;
                        }
                    }
                    // si qqu a gagner on arrete partie
                    else{
                        fin = 1;
                    }

                    break;
                case 2:
                    if(conditionVictoire(taille, &matrice) != 1 && conditionVictoire(taille, &matrice) != 2 && matchNull(taille, &matrice) != 1){
                        // puis l ordi joue => choix de l'ordi faut mettre un random
                        x = rand() % taille; // entre 0 et taille-1
                        y = rand() % taille; // entre 0 et taille-1

                        while(choixCaseOrdi(taille, x, y, &matrice, 1) != 100){
                            x = rand() % taille;
                            y = rand() % taille;
                        }
                    }
                    // si qqu a gagner on arrete partie
                    else{
                        fin = 1;
                    }

                    if(conditionVictoire(taille, &matrice) != 1 && conditionVictoire(taille, &matrice) != 2 && matchNull(taille, &matrice) != 1){
                        // demande au joueur de remplir la case de son choix
                        demanderCase(taille, &matrice, joueur, &x, &y);
                    }
                    // si qqu a gagner on arrete partie
                    else{
                        fin = 1;
                    }

                    break;
            }

    }



    // on arrete le chrono de la partie et on calcule le temps passer entre les 2 temps
    finPartie = calculerTempsActuel();
    afficherTempsPartie(debutPartie, finPartie, tempsTotalHeures, tempsTotalMinutes, tempsTotalSecondes);  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!





    // rajoute le nombre de partie totale faite en fct des joueurs choisis
    switch(joueur){
        case 1:
            (*cptPartie1)++;
            break;
        case 2:
            (*cptPartie2)++;
            break;
    }

    // !!!!!!!!!!!!!!!!! fin de la partie !!!!!!!!!!!!!!!!!!!!!!


    // dire qui a win
    switch(conditionVictoire(taille, &matrice)){
        case 1:
            if(joueur == 1) (*cptVictoire1)++;
            else (*cptDefaite1)++;

            printf("Joueur 1 a gagne !!!\n\n");
            break;
        case 2:
            if(joueur == 2) (*cptVictoire2)++;
            else (*cptDefaite2)++;

            printf("Joueur 2 a gagne !!!\n\n");
            break;
    }


    *partie = afficherMenu(partie);


    if(*partie == 2){
        ecrireFichier(fichier, cptPartie1, cptVictoire1, cptDefaite1, cptPartie2, cptVictoire2, cptDefaite2, tempsTotalHeures, tempsTotalMinutes, tempsTotalSecondes);
        lireFichier(fichier, cptPartie1, cptVictoire1, cptDefaite1, cptPartie2, cptVictoire2, cptDefaite2, tempsTotalHeures, tempsTotalMinutes, tempsTotalSecondes);
        afficherStats(cptPartie1, cptVictoire1, cptDefaite1, cptPartie2, cptVictoire2, cptDefaite2, tempsTotalHeures, tempsTotalMinutes, tempsTotalSecondes);
    }

}


void jouerHumain(long debutPartie, long finPartie, int taille, int *tempsTotalHeures, int *tempsTotalMinutes, int *tempsTotalSecondes, int *cptPartie1, int *cptPartie2, int *cptVictoire1, int *cptVictoire2, int *cptDefaite1, int *cptDefaite2, int *partie, char fichier[]){

    int fin = 0; // permet de definir si la partie est finie ou pas: 0 = en cours, 1 = finie

    // on commence à lancer le chrono
    debutPartie = calculerTempsActuel();


    // creer matrice pour mettre les points (pas graphique)
    int matrice[taille][taille];

    afficherInterface(taille, &matrice);


     // Premier à jouer est obligatoirement joueur 1
    int joueur = 1;


    int x=0, y=0;


    while(fin == 0){
        // Joueur 1 joues
        if(conditionVictoire(taille, &matrice) != 1 && conditionVictoire(taille, &matrice) != 2 && matchNull(taille, &matrice) != 1){
            // demande au joueur de remplir la case de son choix
            demanderCase(taille, &matrice, joueur, &x, &y);
        }
        // si qqu a gagner on arrete partie
        else{
            fin = 1;
        }

        // Joueur 2 joues
        if(conditionVictoire(taille, &matrice) != 1 && conditionVictoire(taille, &matrice) != 2 && matchNull(taille, &matrice) != 1){
            // demande au joueur de remplir la case de son choix
            demanderCase(taille, &matrice, joueur+1, &x, &y);
        }
        // si qqu a gagner on arrete partie
        else{
            fin = 1;
        }

    }



    // on arrete le chrono de la partie et on calcule le temps passer entre les 2 temps
    finPartie = calculerTempsActuel();
    afficherTempsPartie(debutPartie, finPartie, tempsTotalHeures, tempsTotalMinutes, tempsTotalSecondes);  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!




    // Rajoute une partie jouer pour les 2 joueurs
    (*cptPartie1)++;
    (*cptPartie2)++;

    printf("Partie 1 : %d\n", *cptPartie1);


    // !!!!!!!!!!!!!!!!! fin de la partie !!!!!!!!!!!!!!!!!!!!!!


    // dire qui a win
    switch(conditionVictoire(taille, &matrice)){
        case 1:
            (*cptVictoire1)++;
            (*cptDefaite2)++;

            printf("Victoire 1 : %d\n", *cptVictoire1);

            printf("Joueur 1 a gagne !!!\n\n");
            break;
        case 2:
            (*cptVictoire2)++;
            (*cptDefaite1)++;

            printf("Joueur 2 a gagne !!!\n\n");
            break;

    }


    *partie = afficherMenu(partie);


    if(*partie == 2){
        ecrireFichier(fichier, cptPartie1, cptVictoire1, cptDefaite1, cptPartie2, cptVictoire2, cptDefaite2, tempsTotalHeures, tempsTotalMinutes, tempsTotalSecondes);
        lireFichier(fichier, cptPartie1, cptVictoire1, cptDefaite1, cptPartie2, cptVictoire2, cptDefaite2, tempsTotalHeures, tempsTotalMinutes, tempsTotalSecondes);
        afficherStats(cptPartie1, cptVictoire1, cptDefaite1, cptPartie2, cptVictoire2, cptDefaite2, tempsTotalHeures, tempsTotalMinutes, tempsTotalSecondes);
    }

}
