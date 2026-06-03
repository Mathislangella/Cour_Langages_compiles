#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    int *tableau = NULL;
    int somme = 0;
    double moyenne = 0.0;

    printf("Combien d'entiers voulez-vous stocker ? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Nombre invalide.\n");
        return 1;
    }

    tableau = malloc((size_t)n * sizeof(int));
    if (tableau == NULL) {
        printf("Erreur d'allocation memoire.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Valeur %d : ", i + 1);
        if (scanf("%d", &tableau[i]) != 1) {
            printf("Saisie invalide.\n");
            free(tableau);
            return 1;
        }
    }

    printf("\nValeurs saisies :\n");
    for (int i = 0; i < n; i++) {
        printf("tableau[%d] = %d\n", i, tableau[i]);
        somme += tableau[i];
    }

    moyenne = (double)somme / n;

    printf("\nSomme : %d\n", somme);
    printf("Moyenne : %.2f\n", moyenne);

    free(tableau);
    tableau = NULL;

    return 0;
}
