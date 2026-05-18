#include <stdio.h>
#include <string.h>

int main(void) {
    int notes[5] = {14, 17, 9, 12, 18};
    
    int somme = 0;
    int min = notes[0];
    int max = notes[0];

    for (int i = 0; i < 5; i++) {
        somme += notes[i];
        if (notes[i] < min) {
            min = notes[i];
        }
        if (notes[i] > max) {
            max = notes[i];
        }
    }

    printf("Somme : %d\n", somme);
    printf("Moyenne : %f\n", (float)somme / 5);
    printf("Minimum : %d\n", min);
    printf("Maximum : %d\n", max);
    return 0;
}