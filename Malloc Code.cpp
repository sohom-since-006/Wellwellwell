#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *ptr;
    int n, i;
    printf("Enter The Number Of Elements :");
    scanf("%d", &n);
    
    // Dynamically allocate memory for n integers
    ptr = (int*)malloc(n * sizeof(int));

    if (ptr == NULL){
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Memory successfully allocated using Malloc:\n");

    // Taking input from user
    printf("Enter %d Elements:\n", n);
    for (i = 0; i < n; i++){
        scanf("%d", &ptr[i]);
    }

    // Displaying the items
    printf("You Entered : ");
    for (i = 0; i < n; i++){
        printf("%d\t", ptr[i]);
    }

    // Freeing the allocated Memory
    free(ptr);

    printf("\nMemory Successfully Freed\n");

    return 0;
}

