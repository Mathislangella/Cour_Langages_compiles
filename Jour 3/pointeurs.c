#include <string.h>
#include <stdio.h>

void min_max(int tab[], int n, int *pmin, int *pmax) {
    *pmin = tab[0];
    *pmax = tab[0];
    for (int i = 1; i < n; i++) {
        if (tab[i] < *pmin) {
            *pmin = tab[i];
        }
        if (tab[i] > *pmax) {
            *pmax = tab[i];
        }
    }
}

double moyenne(int tab[], int n) {
    int rep = 0;
    for (int i = 0; i < n; i++) {
        rep += tab[i];
    }
    return  (double)rep / n;
}

int main(void) {
    int notes[6] = {14, 17, 9, 12, 18, 4};
    double a = moyenne(notes, 6);
    printf("Notes   : ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", notes[i]);
    }
    printf("\n");
    printf("Moyenne : %f \n",a);

    int min, max;
    min_max(notes, 6, &min, &max);
    printf("Minimum : %d\n", min);
    printf("Maximum : %d\n", max);
    
    return 0;
}