#include <stdio.h>
#include <stdlib.h>

struct votes {
    int men;
    int women;
};


void add_votes(struct votes* v1, struct votes* v2) {
    v1->men += v2->men;
    v1->women += v2->women;
}

int main() {

    struct votes* michigan = (struct votes*) malloc (sizeof (struct votes));
    struct votes* illinois = (struct votes*) malloc (sizeof (struct votes));
    struct votes* california = (struct votes*) malloc (sizeof (struct votes));
    struct votes* all = (struct votes*) malloc (sizeof (struct votes));

    michigan->men = 100;
    illinois->men = 100;
    california->men = 100;

    all->men = 0;
    all->women = 0;

    michigan->women = 100;
    illinois->women = 100;
    california->women = 100;

    add_votes(all, michigan);
    add_votes(all, illinois);
    add_votes(all, california);

    printf("all->men: %d\n", all->men);
    
    free(michigan);
    free(illinois);
    free(california);
    free(all);
    return 0;
}
