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
            return 0;
    }

    int combinaison[4];
    for (int i = 0; i < 4; i++) {
        combinaison[i] = rand() % 6 + 1;
    }

    int restant = tentatives;
    char messagee[100] = "\n\n";
    char liste[tentatives][10];
    memset(liste, 0, sizeof(liste));

    while (restant > 0) {
        printf("%s", messagee);

        printf("Tentatives restantes : %d / %d\n", restant, tentatives);
        printf("Symbole : \n");
        printf(" - O = Bon     chiffre bien place\n");
        printf(" - T = Bon     chiffre mal  place\n");
        printf(" - X = Mauvais chiffre\n");
        printf("\n");

        // Historique
        printf("╔═════════╦═════════╗\n");
        for (int i = 0; i < tentatives - restant; i++) {
            printf("║ ");
            for (int j = 0; j < 4; j++) {
                printf("%c ", liste[i][j]);
            }
            printf("║ ");
            for (int j = 4; j < 8; j++) {
                printf("%c ", liste[i][j]);
            }
            printf("║\n");
            if (i < tentatives - restant - 1) {
                printf("╠═════════╬═════════╣\n");
            }
        }
        printf("╚═════════╩═════════╝\n");

        // Saisie
        printf("Entrez votre combinaison (4 chiffres entre 1 et 6) : ");
        char input[5];
        scanf("%4s", input);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        // Validation
        bool valid = true;
        if (input[0] == '\0' || strlen(input) != 4) {
            valid = false;
        }
        for (int i = 0; i < 4 && valid; i++) {
            if (input[i] < '1' || input[i] > '6') {
                valid = false;
            }
        }

        if (!valid) {
            snprintf(
                messagee,
                sizeof(messagee),
                "\nEntree invalide. Veuillez entrer exactement 4 chiffres entre 1 et 6.\n"
            );
            ClearConsole();
            continue;
        }
        restant--;
        char symbols[5] = "XXXX";
        bool combUsed[4] = {false, false, false, false};

        for (int i = 0; i < 4; i++) {
            if ((input[i] - '0') == combinaison[i]) {
                symbols[i] = 'O';
                combUsed[i] = true;
            }
        }

        // Recherche des T
        for (int i = 0; i < 4; i++) {
            if (symbols[i] == 'O') {
                continue;
            }
            for (int j = 0; j < 4; j++) {
                if (combUsed[j]) {
                    continue;
                }
                if ((input[i] - '0') == combinaison[j]) {
                    symbols[i] = 'T';
                    combUsed[j] = true;
                    break;
                }
            }
        }
        int index = tentatives - restant - 1;
        snprintf(liste[index],sizeof(liste[index]),"%s%s",input,symbols);
        if (strcmp(symbols, "OOOO") == 0) {
            ClearConsole();
            printf("Bravo ! Vous avez trouve la combinaison !\n");
            printf("La combinaison etait : %d %d %d %d\n",combinaison[0],combinaison[1],combinaison[2],combinaison[3]);

            return tentatives * 5 + restant * 10;;
        }
        strcpy(messagee, "\n\n");
        ClearConsole();
    }
    printf("\nPerdu ! La combinaison etait : %d %d %d %d\n",combinaison[0],combinaison[1],combinaison[2],combinaison[3]);
    return 0;
}

int Mastermind(int *score) {
    ClearConsole();

    printf("Bienvenue dans le jeu du Mastermind\n");
    printf("Vous devez deviner une combinaison de 4 chiffres choisie par l'ordinateur.\n");
    printf("Votre score actuel est de %d points.\n", *score);

    char choix[100];
    bool Leave = false;
    char message[100] = "\n\n";

    while (!Leave) {
        int GainScore = 0;
        printf("%s", message);

        printf("Veuillez choisir le niveau de difficulte (1, 2 ou 3)\n");
        printf(" - Facile    (1) (10 essais)\n");
        printf(" - Normal    (2) (7 essais)\n");
        printf(" - Difficile (3) (5 essais)\n");
        printf("Quitter ce jeu (10)\n\n");
        printf("Votre choix : ");

        scanf("%99s", choix);
        int choixInt = atoi(choix);
        switch (choixInt) {
            case 10:
                Leave = true;
                break;
            case 1:
                GainScore = PlayMastermind(1);
                break;
            case 2:
                GainScore = PlayMastermind(2);
                break;
            case 3:
                GainScore = PlayMastermind(3);
                break;
            default:
                snprintf(
                    message,
                    sizeof(message),
                    "\nChoix invalide. Veuillez choisir entre 1, 2 ou 3.\n"
                );
                break;
        }

        if (!Leave) {
            printf("\nAppuyez sur Entree(Parfois plusieur fois) pour continuer...");
            getchar();
            getchar();
            *score += GainScore;
            
        }

        ClearConsole();
    }

    return 0 ;
}