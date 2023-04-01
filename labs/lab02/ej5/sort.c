#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"
#include "fixstring.h"


static unsigned int partition(fixstring a[], unsigned int izq, unsigned int der) {
    /* copiá acá la implementación que hiciste en el ejercicio 3 */
}

static void quick_sort_rec(fixstring a[], unsigned int izq, unsigned int der) {
    /* copiá acá la implementación que hiciste en el ejercicio 3 */
}

void quick_sort(fixstring a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}


