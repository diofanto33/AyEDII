#include <stdio.h>    /* printf()...          */
#include <stdbool.h>  /* bool, true, false... */
#include <stdlib.h>   /* EXIT_SUCCESS... */

int main(void) {
    bool b1, b2;
    b1 = true;
    b2 = false;
    printf("b1: %d\n", b1);
    printf("b2: %d\n", b2);
    printf("b1 || b2: %d\n", b1 || b2);
    printf("b1 && b2: %d\n", b1 && b2);

    return EXIT_SUCCESS;
}
