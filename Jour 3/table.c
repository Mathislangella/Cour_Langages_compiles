#include <stdio.h>

int main(void) {
    int choix;
    do {
        printf("Quelles table de multiplication voulez-vous voir ?\n");
        printf("0 : Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        if (choix != 0) {
            for (int i = 1; i <= 10; i++) {
                printf("%d x %d = %d\n", choix, i, choix * i);
            }
        }
    } while (choix != 0);
    printf("bye")
    return 0;
}