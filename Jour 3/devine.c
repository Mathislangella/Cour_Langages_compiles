#include <stdio.h>
#include <stdlib.h> 

// importe sa pour un clear console
void clearConsole() {
    #ifdef _WIN32
        system("cls");   
    #else
        system("clear"); 
    #endif
}

int main(void) {
    int max = 0;
    int choix = 0;
    do {
        clearConsole();
        if (choix != 0) {
            printf("Choix invalide, essayez à nouveau.\n");
        }
        printf("Choisissez un niveau de dificulté (1, 2 ou 3) : \n");
        printf("1 : Facile (1 à 10)\n");
        printf("2 : Moyen (1 à 100)\n");
        printf("3 : Difficile (1 à 1000)\n");
        printf("0 : Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                max = 10;
                break;
            case 2:
                max = 100;
                break;
            case 3:
                max = 1000;
                break;
            case 0:
                printf("Merci d'avoir joué !\n");
                return 0;
        }
    } while (choix < 1 || choix > 3);

    int rep = rand() % max + 1;
    int guess = 0;
    int count = 0;

    while (guess != rep) {
        printf("Choisissez un nombre entre 1 et %d : ", max);
        scanf("%d", &guess);
        count++;
        if (guess < rep) {
            printf("Trop petit !\n");
        } else if (guess > rep) {
            printf("Trop grand !\n");
        } else {
            printf("Le nombre était %d.\n", rep);
            printf("Bravo ! Vous avez trouvé en %d essais.\n", count);
        }
    }

    return 0;
}