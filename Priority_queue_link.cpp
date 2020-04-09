#include <stdio.h>
#include <stdlib.h>

//�ŧi�n�Q�ƧǪ���ƫ��O priority queue �|�̷� key ���j�p�ƦC
typedef struct element{
    int key;
};

//�ŧi�@�ӥi�H�e�Ǫ��U�̤j�ϥζq���}�C �M �@�Ӭ����ثe queue ���ϥΤj�p
struct element *heap[200];
int amount=1;

struct element* pop();
void push(struct element *link);

int main () {

    //example
    int i;
    struct element *link;

    for (i=1;i<10;i++) {
        link=(element*)malloc(sizeof(element));
        link->key=i;
        push(link);
    }
    while (amount>1) {
        link=pop();
        printf ("%d\n",link->key);
    }
    //example

}

void push(struct element *link) {
    int i=amount;

    for (;i!=1&&link->key < heap[i/2]->key;i/=2)
        heap[i]=heap[i/2];
    heap[i]=link;
    amount++;
}

struct element* pop() {
    struct element *root=heap[1];
    struct element *temp;
    int parent=1,child=2;

    if (amount<=1)
        return NULL;

    amount--;
    temp=heap[amount];

    while (child <= amount) {
        if (child<amount && heap[child]->key>heap[child+1]->key)
            child++;
        if (temp->key < heap[child]->key)
            break;
        heap[parent]=heap[child];
        parent=child;
        child*=2;
    }
    heap[parent]=temp;
    return root;
}
