#include <stdio.h>
#include <stdbool.h>

int minimum(int a, int b) {
    if (a < b) {
        return a;
    } 
    return b;
}

int maximum(int a, int b) {
     if (a > b) {
        return a;
    } 
    return b;
}

int valeur_absolue(int x) {
    if (x > 0) {
        return x;
    }
    return x * -1;
}

int est_pair(int x) {
    return (x % 2 == 0);
}

long factorielle(int n) {
    int rep = 1;
    for (int i = 1; i <= n; i++) {
        rep *= i;
    }
    return rep;
}

int main(void) {
    printf("Minimum de 5 et 10 : %d\n", minimum(5, 10));
    printf("Maximum de 5 et 10 : %d\n", maximum(5, 10));
    printf("Valeur absolue de 5 : %d\n", valeur_absolue(5));
    printf("Valeur absolue de -5 : %d\n", valeur_absolue(-5));
    printf("Est-ce que 4 est pair ? %d\n", est_pair(4));
    printf("Est-ce que 3 est pair ? %d\n", est_pair(3));
    printf("Factorielle de 5 : %ld\n", factorielle(5));
    return 0;
}
