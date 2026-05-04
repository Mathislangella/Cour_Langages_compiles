#include <stdio.h>

int main(void) {
    int choix;
    double valeur;

    printf("=== Convertisseur universel ===\n");
    printf("1. Kilometres  -> Miles\n");
    printf("2. Kilogrammes -> Livres\n");
    printf("3. Celsius     -> Fahrenheit\n");
    printf("4. Quitter\n");
    printf("Votre choix : ");
    scanf("%d", &choix);


    if (choix == 4) {
        printf("Au revoir !\n");
        return 0;
    }

    printf("Valeur a convertir : ");
    scanf("%lf", &valeur);

    switch (choix) {
        case 1:
            printf("%.2f km = %.2f miles\n", valeur, valeur * 0.621371);
            break;
        case 2:
            printf("%.2f kg = %.2f livres\n", valeur, valeur * 2.20462);
            break;
        case 3:
            printf("%.2f C= %.2f F\n", valeur, valeur * 9/5 + 32);
            break;
        default:
            printf("Choix invalide !\n");
    }
    return 0;
}