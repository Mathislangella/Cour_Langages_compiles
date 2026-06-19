#include "pendu.h"
#include "outils.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

char *MotsFacile[] = {"chat","chien","pomme","livre","table","porte","stylo","arbre"};
char *MotsMoyen[] = {"voiture","montagne","ordinateur","bouteille","programme","musique","escalier","telephone","pierre"};
char *MotsDifficile[] = {"developpement","informatique","cybersecurite","interoperabilite","electromecanique","telecommunication","administration","algorithmique"};

int PlayPendu(int difficulty) {
    char *mot;
    int tailleListe;

    switch (difficulty) {
        case 1:
            tailleListe = sizeof(MotsFacile) / sizeof(MotsFacile[0]);
            mot = MotsFacile[rand() % tailleListe];
            break;

        case 2:
            tailleListe = sizeof(MotsMoyen) / sizeof(MotsMoyen[0]);
            mot = MotsMoyen[rand() % tailleListe];
            break;

        case 3:
            tailleListe = sizeof(MotsDifficile) / sizeof(MotsDifficile[0]);
            mot = MotsDifficile[rand() % tailleListe];
            break;

        default:
            return 0;
    }

    int longueur = strlen(mot);
    char motCache[100];
    bool lettresTrouvees[100];

    for (int i = 0; i < longueur; i++) {
        motCache[i] = '_';
        lettresTrouvees[i] = false;
    }
    motCache[longueur] = '\0';

    int erreurs = 0;

    while (erreurs < 7) {
        ClearConsole();

        printf("===== PENDU =====\n\n");
        printf("Mot : ");

        for (int i = 0; i < longueur; i++) {
            printf("%c ", motCache[i]);
        }

        printf("\n");
        printf("Erreurs restantes : %d\n\n", 7 - erreurs);

        char lettre;
        bool trouve = false;

        printf("Entrez une lettre : ");
        scanf(" %c", &lettre);

        for (int i = 0; i < longueur; i++) {
            if (mot[i] == lettre && !lettresTrouvees[i]) {
                motCache[i] = lettre;
                lettresTrouvees[i] = true;
                trouve = true;
            }
        }

        if (!trouve) {
            erreurs++;
        }

        if (strcmp(motCache, mot) == 0) {
            ClearConsole();

            printf("===== PENDU =====\n\n");
            printf("Bravo ! Vous avez trouvé le mot : %s\n", mot);

            
            printf("\nAppuyez sur Entrée pour continuer...");
            getchar();
            getchar();

            int score = (50 + ((int)strlen(motCache) - erreurs)) * 10  * difficulty;
            return 1; 
        }
    }

    ClearConsole();

    printf("===== PENDU =====\n\n");
    printf("Vous avez perdu !\n");
    printf("Le mot était : %s\n", mot);

    return 0; // perdu
}

int Pendu(int *score) {
    ClearConsole();

    printf("Bienvenue dans le jeu du Pendu.\n");
    printf("Vous devez deviner le mot caché par l'ordinateur.\n");
    printf("Votre score actuel est de %d point(s).\n", *score);

    char choix[100];
    bool Leave = false;
    char message[100] = "\n\n";

    while (!Leave) {
        int GainScore = 0;

        printf("%s", message);

        printf("La difficulté change la taille du mot à trouver.\n");
        printf("Veuillez choisir le niveau de difficulté.\n");
        printf(" - Facile    (1) ( 4 -  5  letres)\n");
        printf(" - Normal    (2) ( 7 - 10  letres)\n");
        printf(" - Difficile (3) (13 - 17  letres)\n");
        printf("Quitter ce jeu (10)\n\n");
        printf("Votre choix : ");

        scanf("%99s", choix);
        int choixInt = atoi(choix);
        switch (choixInt) {
            case 10:
                Leave = true;
                break;
            case 1:
                GainScore = PlayPendu(1);
                break;
            case 2:
                GainScore = PlayPendu(2);
                break;
            case 3:
                GainScore = PlayPendu(3);
                break;
            default:
                snprintf(message,sizeof(message),"\nChoix invalide. Veuillez choisir entre 1, 2 et 3.\n");
                break;
        }
        if (!Leave) {
            *score += GainScore;
            printf("\nAppuyez sur Entrée pour continuer...");
            getchar();
            getchar();
        }
        ClearConsole();
    }
    return 0;
}