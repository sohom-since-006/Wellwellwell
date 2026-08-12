#include <stdio.h>

int main() {
    int m;

    printf("Enter Your Marks: ");
    scanf("%d", &m);

    if (m >= 90) {
        printf("Grade is O");
    }
    else if (m >= 80) {
        printf("Grade is E");
    }
    else if (m >= 70) {
        printf("Grade is A");
    }
    else if (m >= 60) {
        printf("Grade is B");
    }
    else if (m >= 50) {
        printf("Grade is C");
    }
    else if (m >= 40) {
        printf("Grade is D");
    }
    else {
        printf("Fail");
    }

    return 0;
}

