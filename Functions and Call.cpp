#include <stdio.h>
void welcome();
void inputFirst(int *a);
void inputSecond(int *b);
int sum(int a, int b);
void displayResult(int a, int b, int c);
void endMsg();

	int main() {
	    int a, b, c;
	
	    welcome();
	    inputFirst(&a);
	    inputSecond(&b);
	
	    c = sum(a, b);
	
	    displayResult(a, b, c);
	    endMsg();
	
	    return 0;
}
		void welcome() {
		    printf("...Welcome to the World of C programing...");
		}

			void inputFirst(int *a) {
			    printf("\n\n\tEnter the 1st No:");
			    scanf("%d", a);
	}
	
		void inputSecond(int *b) {
		    printf("\n\n\tEnter the 2nd No:");
		    scanf("%d", b);
	}

		int sum(int a, int b) {
		    return a + b;
}

		void displayResult(int a, int b, int c) {
		    printf("\n\n\tThe Sum Of %d and %d is %d.", a, b, c);
}

void endMsg() {
    printf("\n\n\t...End Of Program...");
}

