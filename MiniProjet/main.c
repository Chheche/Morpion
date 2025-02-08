#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[])
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[debug] %s", SDL_GetError());
        return -1;
    }
    SDL_Quit();

    char fichier[] = "stats.txt"; // nom du fichier ou on stocke les stats du joueur

    int partie = 0; // permet de savoir le choix du joueur au menu

    int cptPartie1 = 0; // compte le nombre de partie que le joueur a faite avec le joueur 1
    int cptVictoire1 = 0; // compte le nombre de victoire du joueur faite avec le joueur 1
    int cptDefaite1 = 0; // compte le nombre de defaite du joueur faite avec le joueur 1

    int cptPartie2 = 0; // compte le nombre de partie que le joueur a faite avec le joueur 2
    int cptVictoire2 = 0; // compte le nombre de victoire du joueur faite avec le joueur 2
    int cptDefaite2 = 0; // compte le nombre de defaite du joueur faite avec le joueur 2

    int tempsTotalHeures = 0;
    int tempsTotalMinutes = 0;
    int tempsTotalSecondes = 0;

    long debutPartie = 0; // permet de calculer le debut de la partie
    long finPartie = 0; // permet de calculer la fin de la partie

    int taille = 3;  // taille de la matrice



    while(1){  // permet de tourner en boucle
        partie = afficherMenu(&partie);

        // statisiques
        if(partie == 2){
                verifierExistenceFichier(fichier);
                lireFichier(fichier, &cptPartie1, &cptVictoire1, &cptDefaite1, &cptPartie2, &cptVictoire2, &cptDefaite2, &tempsTotalHeures, &tempsTotalMinutes, &tempsTotalSecondes);
                afficherStats(&cptPartie1, &cptVictoire1, &cptDefaite1, &cptPartie2, &cptVictoire2, &cptDefaite2, &tempsTotalHeures, &tempsTotalMinutes, &tempsTotalSecondes);
        }



        // !!!!!!!!!!!!!!!!! debut de la partie !!!!!!!!!!!!!!!!!!!!!!

        while(partie == 1){
            int choix = 0;
            printf("Voulez vous jouer contre : \n");
            printf("1 : Un bot \n");
            printf("2 : Un humain (sur ce PC) \n");
            scanf("%d", &choix);

            while(choix<1 || choix>2){
                printf("Il n'y a que 2 choix !!!! \n\n");
                printf("Voulez vous jouer contre : \n");
                printf("1 : Un bot \n");
                printf("2 : Un humain (sur ce PC) \n");
                scanf("%d", &choix);
            }

            // permet d'effacer la console
            system("cls");

            if(choix==1){
                jouerBot(debutPartie, finPartie, taille, &tempsTotalHeures, &tempsTotalMinutes, &tempsTotalSecondes, &cptPartie1, &cptPartie2, &cptVictoire1, &cptVictoire2, &cptDefaite1, &cptDefaite2, &partie, fichier);
            }
            else{
                jouerHumain(debutPartie, finPartie, taille, &tempsTotalHeures, &tempsTotalMinutes, &tempsTotalSecondes, &cptPartie1, &cptPartie2, &cptVictoire1, &cptVictoire2, &cptDefaite1, &cptDefaite2, &partie, fichier);
            }

        }

        // fin de la partie
        if(partie == 0) break;

    }


    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Fin du jeu !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // permet d'effacer la console
    system("cls");

    printf("Merci d'avoir jouer !!!\n\n");


    return 0;
}
