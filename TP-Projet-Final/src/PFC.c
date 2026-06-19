#include "outils.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int PlayPFC(int *score) {
    ClearConsole();

    int choixIA;
    int choixJoueur;

    char input[100];

    char message[100] = "Bienvenue dans le jeu du PierreFeuilleCiseaux\n\n";

    printf("\n");
        printf("\n");

    while (1) {
        printf("%s", message);
        
        printf("Votre score actuel est de %d points.\n\n", *score);
        printf("Ordre de Puissance :\n");
        printf("Pierre > Ciseaux > Feuille > Pierre \n\n");
        printf("=== Pierre / Feuille / Ciseaux ===\n");
        printf("1 = Pierre\n");
        printf("2 = Feuille\n");
        printf("3 = Ciseaux\n");
        printf("0 = Quitter\n\n");

        printf("Votre choix : ");
        scanf("%99s", input);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        choixJoueur = atoi(input);
        if (choixJoueur == 0) {
            break;
        }
        if (choixJoueur < 1 || choixJoueur > 3) {
            snprintf(message, sizeof(message),
                     "\nChoix invalide (1, 2, 3 ou 0 pour quitter).\n");
        }

        // IA ramdom
        choixIA = rand() % 3 + 1;
        printf("\nVous : %d | IA : %d\n", choixJoueur, choixIA);

        // Victoire
        if (choixJoueur == choixIA) {
            printf("Egalite !\n");
        }
        else if (
            (choixJoueur == 1 && choixIA == 3) ||
            (choixJoueur == 2 && choixIA == 1) ||
            (choixJoueur == 3 && choixIA == 2)
        ) {
            printf("Vous gagnez ! +50 points\n");
            *score += 50;
        }
        else {
            printf("Vous perdez ! - 15 points\n");
             *score -= 15;
            if (*score < 0) {
                *score = 0;
            }
        }

        strcpy(message, "\n\n");

        
        printf("\nAppuyez sur Entree(Parfois plusieur fois) pour continuer...");
        getchar();
        getchar();

        ClearConsole();
    }

    return 1;
}