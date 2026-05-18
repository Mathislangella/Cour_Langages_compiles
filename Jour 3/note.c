#include <stdio.h>
int main(void) {
    int note;
    printf("Note (0-20) : ");
    scanf("%d", &note);
    if (note < 0 || note > 20) {
        printf("Note invalide\n");
    } else if (note >= 16) {
        printf("Tres bien\n");
    } else if (note >= 12) {
        printf("Bien\n");
    } else if (note >= 10) {
        printf("Passable\n");
    } else {
        printf("Insuffisant\n");
    }

    if (note >= 10) {
        printf("Admis\n");
    } else {
        printf("Refuse\n");
    }
    return 0;
}