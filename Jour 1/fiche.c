#include <stdio.h>
int main(void) {
    char prenom[] = "Mathis";
    int age = 18;
    float taille = 1.70f;
    char initiale = 'M';
    // Completez l'affichage formate ici
    // %s pour les chaines, %d pour les entiers
    // %c pour un caractere, %.2f pour les flottants
    printf("+-------------------------------+\n");
    printf("|     FICHE D'IDENTITE          |\n");
    printf("+-------------------------------+\n");
    printf("| Prenom   : %s\n", prenom);
    printf("| Age      : %d\n", age);
    printf("| Taille   : %.2f\n", taille);
    printf("| Initiale : %c\n", initiale);
    printf("+-------------------------------+\n");
    printf("| Code de sortie : 0 (succes)   |\n");
    printf("+-------------------------------+\n");

    return 0;
}