#include <stdio.h>

int main() {
    int movie = 1;

    switch ((movie << 2) + movie) {
        case 4:
            printf("Ghajini\n");

        case 5:
            printf("Krish\n");

        case 6:
            printf("Race\n");

        default:
            printf("3 Idiots\n");
    }

    return 0;
}

