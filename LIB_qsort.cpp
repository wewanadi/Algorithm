#include <stdio.h>
#include <stdlib.h>

struct element{
    int key;
    int data;
};

int cmp (const void * a, const void * b)
{
    struct element **pa=(struct element**) a;
    struct element **pb=(struct element**) b;
    return ( (*pa)->key > (*pb)->key );
}


struct element *node[200];
int amount=0;

int main()
{
    //example
    int i;
    int n;
    struct element *link;

    int arr[10]={10,10,10,7,5,9,1,1,1,1};

    for (i=0;i<10;i++) {
        node[amount]=(element*)malloc(sizeof(element));
        node[amount]->key=arr[i];
        node[amount]->data=i;
        amount++;
    }

    qsort(node,amount,sizeof(element*),cmp);

    for (i=0;i<10;i++)
    printf ("  !%d %d!\n",node[i]->key,node[i]->data);
    //example

    return 0;
}

