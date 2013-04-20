#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

/** Constant definition **/

/* Maximum array size */
#define N           100
#define TESTS       1000
//#define DEBUG 0
#define TIMES_FILE  "times.dat"
#define FOUND_FILE  "found.dat"


/** Data type definition **/

/* Element */
struct E {
    int el_int;
    double el_double;
};

/* Array */
struct Array {
    struct E elem[N];
    struct E (*indexing)(const struct Array* a, const int i);
    int (*search)(const struct Array* a, const struct E e);
};

/** Functions **/

struct E array_index(const struct Array* a, const int i){
    return a->elem[i];
}

int compare(const struct E a, const struct E b){
#ifdef DEBUG
    printf("%d %d %f %f\n", a.el_int, b.el_int, a.el_double, b.el_double);
#endif /* DEBUG */
    return (a.el_int == b.el_int && a.el_double == b.el_double);
}

int array_search(const struct Array* a, const struct E e){
    int i = 0, found = 0;
    do {
        if (compare(a->elem[i], e))
            found = i;
        i++;
    } while (!found && i < N);
    return found;
}

void main(){
    struct Array my_array[TESTS];
    int i = 0, j = 0;
    struct E temp;
    struct timeval t1, t2;
    double elapsedTime;
    double times[TESTS];
    FILE *file1, *file2;

    t1.tv_sec = 0;
    t1.tv_usec = 0;
    t2.tv_sec = 0;
    t2.tv_usec = 0;
    srand(time(NULL));
    /* Element to search */
    temp.el_int = rand();
    temp.el_double = rand() * 0.1;
    /* Generating random array */
    for (j = 0; j < TESTS; j++){
        my_array[j].indexing = array_index;
        my_array[j].search = array_search;
        for (i = 0; i < N; i++){
            my_array[j].elem[i].el_int = rand();
            my_array[j].elem[i].el_double = rand() * 0.1;
#ifdef DEBUG
            printf("Element %d: el_int = %d el_double = %f\n", i, my_array[j].elem[i].el_int, my_array[j].elem[i].el_double);
#endif /* DEBUG */
        }
    }
    file1 = fopen(TIMES_FILE, "w");
    file2 = fopen(FOUND_FILE, "w");
    /* Run search operations */
    for (j = 0; j < TESTS; j++){
        gettimeofday(&t1, NULL);
        i = my_array[j].search(&my_array[j], temp);
        gettimeofday(&t2, NULL);
        elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
        elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
        times[j] = elapsedTime;
        /* Write on file */
        fprintf(file1, "%d %f\n", j, times[j]);
        fprintf(file2, "%d %i\n", j, i);
    }
    fflush(file1);
    fclose(file1);
    fflush(file2);
    fclose(file2);
}
