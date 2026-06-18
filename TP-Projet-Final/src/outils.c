#include "Outils.h"
#include <stdlib.h>

void ClearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}