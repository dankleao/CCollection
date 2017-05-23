//
// Created by Daniel Cardoso on 22/05/17.
//

#include <stdio.h>
#include "Queue.h"

typedef struct vertex{
    long id;
    double weight;
}Vertex;

int main(void)
{
    /* Test */

    printf("\nCreate Queue 1:\n\n");

    /* Creating queue */
    Queue* q = Qcreate();

    /* Create array of Vertex */
    Vertex vextex[20];

    /* init array */
    int i;
    for( i = 0 ; i < 20 ; ++i )
    {
        vextex[i].id = i % 3 == 0 ? 100 : i ;
        vextex[i].weight = i % 3 == 0 ? i*100 : i*5;

        /* Adding in queue */
        Qadd(q,&vextex[i]);
    }

    /* show Vertexs */
    for( i = 0 ; i < q->size ; ++i )
        printf("V%d: { id: %lu weight: %2.0f }\n",i,vextex[i].id,vextex[i].weight);

    /* Get Vertex in queue  */
    printf("\nGet V[5]: ");
    int pos = Qsearch(q,&vextex[5]);
    printf("{ id: %lu weight: %2.0f }\n",vextex[pos].id,vextex[pos].weight);


    /* Other queue */

    printf("\nCreate Queue 2:\n\n");

    /* Creating queue */
    Queue * q2 = Qcreate();

    /* Adding in queue */
    char* helloC = "Hello C!";
    Qadd(q2,"Queue Testing...");
    Qadd(q2,&helloC[0]);
    Qadd(q2,"It\'me, Test!");
    Qadd(q2,"Finish!");

    /* show elems in queue */
    for( i = 0 ; i < q2->size ; ++i )
        printf("%s!\n", ((char*) Qget(q2,i)));


    /* Removing elems in queue - step-by-step */
    while ( q2->size > 0 ) {

        printf("\nSize Queue2: %d\n",q2->size);

        char *str = Qremove(q2);
        printf("\nRemoved: %s\n\n", str);

        for (i = 0; i < q2->size; ++i) {
            printf("%s!\n", ((char *) Qget(q2, i)));
        }
    }

    printf("Index of String: \"Hello C!\" = %d\n", Qsearch(q2,&helloC[0]));

    return 0;
}
