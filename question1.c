/*
CSC362 - Assignment 1
Michael Ramcharitar
Question 1: Dynamic Memory Allocation and Common Bugs

What this program does:
1) Asks user how many integers they will enter
2) Allocates that many integers (malloc)
3) Reads in the integers
4) Prints the integers in REVERSE order
5) Frees memory (prevents memory leaks)
*/

// for printf, scanf
#include <stdio.h>

// for malloc, free
#include <stdlib.h>

int main(void)
{
       // 1. Ask for number of elements

    // ALWAYS initialize variables (avoid uninitialized variable bugs)
    int n = 0;

    printf("Enter the number of integers: ");

    /*
    scanf returns number of items successfully read.
    If it does NOT read 1 integer, we treat it as invalid input.
    */
    if (scanf("%d", &n) != 1)
    {
        printf("Invalid input. Expected an integer.\n");
        // exit program with an error code
        return 1;
    }

    /*
    Edge case: user enters 0 (or negative).
    The assignment hint mentions this, and that we should consider
    the case of zero elements.
    If n <= 0, there is nothing to allocate / read.
    */
    if (n <= 0)
    {
        printf("No elements to store.\n");
        // not an error; just nothing to do
        return 0;
    }

       //2) Dynamically allocate memory (malloc)

    /*
    I need to allocate memory for n integers.
    sizeof(int) will tell us the number of bytes for one int.
    The total number of bytes needed is n * sizeof(int).

    It is important to note that malloc will return
    a pointer to the alloacted space or Null if it fails.
    or NULL if it fails.
    */
    int *arr = (int *)malloc((size_t)n * sizeof(int));

    /*
    THis part will always check to see if 
    malloc succeeded. If arr is NULL, we have to make sure
    we do NOT use it.
    */
    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        // exit program with an error code
        return 1;
    }

       // 3) Read integers into the array

    /*
    I will fill arr[0] .. arr[n-1].
    Using a basic for-loop.
    */
    printf("Enter %d integers:\n", n);

    for (int i = 0; i < n; i++)
    {
        /*
        Read one integer at a time.
        Check scanf return value to avoid using garbage.
        */
        printf("Integer %d: ", i + 1);

        if (scanf("%d", &arr[i]) != 1)
        {
            /*
            If I fail to read input here, I should FREE memory before leaving
            to avoid a memory leak.
            */
            printf("Invalid input.\n");

            // prevent memory leak
            free(arr);

            // (optional safety: avoid dangling pointer)
            arr = NULL;

            return 1;
        }
    }

       // 4) Print the integers in reverse order

    /*
    Last index is n-1.
    We will COUNT DOWN to 0.
    */
    printf("Integers in reverse order:\n");
    for (int i = n - 1; i >= 0; i--)
    {
        printf("%d\n", arr[i]);
    }

       // 5) Free the dynamically allocated memory

    /*
    This is REQUIRED to prevent memory leaks.
    After free, arr points to invalid memory, so I can set it to NULL.
    */
    free(arr);
    arr = NULL;

    /*
    Program finished successfully.
    */
    return 0;
}
