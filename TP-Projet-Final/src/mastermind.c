#include "mastermind.h"
#include "outils.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int PlayMastermind(int difficulty) {
    ClearConsole();

    int tentatives;
    switch (difficulty) {
        case 1: tentatives = 10; break;
        case 2: tentatives = 7; break;
        case 3: tentatives = 5; break;
        default:
            printf("Niveau de difficulté invalide.\n");
            return -1;
    }

    int combinaison[4];
    for (int i = 0; i < 4; i++) {
        combinaison[i] = rand() % 6 + 1; 
    }

    int restant = tentatives;
    bool Leave = false;
    char messagee[100] = "\n\n";
    while (restant > 0 && !Leave) {
        printf("%s", messagee);

        printf("Tentatives restantes : %d / %d\n", restant, tentatives);
        printf("Symbole : \n");
        printf(" - O = Bon     chifre bien place\n");
        printf(" - T = Bon     chifre mal  place\n");
        printf(" - X = Mauvais chifre mal  place\n");

        for (int i = 0; i < 4; i++) {
            printf(" %d", combinaison[i]);
        }
        printf("\n");
        printf("╔═════════╦═════════╗\n");
        printf("║ 9 9 9 9 ║ X X X X ║\n");
        printf("╠═════════╬═════════╣\n");
        printf("║ 9 9 9 9 ║ X X X X ║\n");
        printf("╚═════════╩═════════╝\n");
        
        printf("Entrez votre combinaison (4 chiffres entre 1 et 6) : ");
        char input[4];
        scanf(" %s", input);
        
        bool valid = true;
        if (strlen(input) != 4) {
            valid = false;
            break;
        }
        for (int i =  0; i < 4; i++) {
            if (input[i] < '1' || input[i] > '6') {
                valid = false;
                break;
            }
        }
        if (!valid) {
            snprintf(messagee, sizeof(messagee),
                        "\nEntrée invalide. Veuillez entrer exactement 4 chiffres entre 1 et 6.\n");
            printf("Entrée invalide.\n");
            break;
        }else {
            restant--;
        }
        
        ClearConsole();
    }
    printf("\nPerdu ! La combinaison était : %d %d %d %d\n",combinaison[0], combinaison[1], combinaison[2], combinaison[3]);
    return 0;
}

int Mastermind(int *score) {
    ClearConsole();
    printf("Bienvenue dans le jeu du Mastermind\n");
    printf("Vous devez deviner une combinaison de 4 chiffres choisie par l'ordinateur.\n");
    printf("Vous avez 10 essais pour trouver la bonne combinaison.\n");
    printf("Votre score actuel est de %d points.\n", *score);

    char choix[100];
    bool Leave = false;
    char message[100] = "\n\n";
    while (!Leave) {
        printf("%s", message);

        printf("Veuillez choisir le niveau de difficulté (1, 2 ou 3)\n");
        printf(" - Facile    (1) (10 essais)\n");
        printf(" - Normal    (2) (7 essais)\n");
        printf(" - Difficile (3) (5 essais)\n");
        printf("Quitter ce jeu (10)\n\n");

        printf("Votre choix : ");
        scanf(" %s", choix);
        int choixInt = atoi(choix);
        switch (choixInt) {
            case 10:
                Leave = true;
                break;
            case 1:
                PlayMastermind(1);
                break;
            case 2:
                PlayMastermind(2);
                break;
            case 3:
                PlayMastermind(3);
                break;

            default:
                snprintf(message, sizeof(message),
                         "\nChoix invalide. Veuillez choisir entre 1, 2 ou 3.\n");
                printf("Choix invalide.\n");
                break;
        }
        ClearConsole();
    }
    return 0;
}

