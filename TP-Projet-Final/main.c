#include "Outils.h"
#include "mastermind.h"


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {
    ClearConsole();

    int score = 0;
    char choix[100];
    bool Leave = false;
    char message[100] = "\n\n";

    printf("Bienvenue dans le monde incroyable des minijeux du projet de cours de langages compiles\n");
    printf("Vous allez pouvoir jouer a 3 minijeux differents.\n");
    printf("Votre score est commun a tout les jeux ,actuel vous avez %d points.\n", score);
    while (!Leave) {

        printf("%s", message);
        char message[100] = "\n\n";
        printf("Veuillez choisir un minijeux (1, 2 ou 3)\n");
        printf(" - Le premier   est un jeu de devinette de nombre.\n");
        printf(" - Le deuxieme  est un jeu du Pendu.\n");
        printf(" - Le troisieme est un jeu de Pierre/Feuille/Ciseau.\n");
        printf("Quitter (10)\n\n");

        printf("Votre choix : ");
        scanf(" %s", choix);
        int choixInt = atoi(choix);
        switch (choixInt) {
            case 10:
                Leave = true;
                break;
                
            case 1:
                Mastermind(&score);
                break;

            case 2:
                // jeuPendu();
                break;

            case 3:
                // jeuPierreFeuilleCiseau();
                break;

            default:
                snprintf(message, sizeof(message),
                         "\nChoix invalide. Veuillez choisir entre (1, 2 ou 3).\n");
                printf("Choix invalide.\n");
                break;
        }
        ClearConsole();
    }

    return 0;
}