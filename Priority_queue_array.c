#include <stdio.h>

//�ŧi�n�Q�ƧǪ���ƫ��O priority queue �|�̷� key ���j�p�ƦC
typedef struct element{
    int key;
};

//�ŧi�@�ӥi�H�e�Ǫ��U�̤j�ϥζq���}�C �M �@�Ӭ����ثe queue ���ϥΤj�p
struct element heap[200];
int amount=1;

struct element pop();
void push(struct element item);

int main () {

    //example
    int i;
    struct element a;
    a.key=20;
    push(a);
    for (i=1;i<10;i++) {
        a.key=i;
        push(a);

    }

    a.key=30;
    push(a);
printf ("!!%d %d %d %d\n",heap[0],heap[1],heap[2],heap[3]);
    while (amount>0) {
        a=pop();
        printf ("%d\n",a.key);
                printf ("!!%d %d %d %d\n",heap[0],heap[1],heap[2],heap[3]);
    }

    //example

}

void push(struct element item) {
    int i=amount;
    for (;i!=1&&item.key < heap[i/2].key;i/=2)
        heap[i]=heap[i/2];
    heap[i]=item;
    amount++;
}

struct element pop() {
    struct element root=heap[1];
    struct element temp=heap[amount--];
    int parent=1,child=2;

    while (child <= amount) {
        if (child<amount && heap[child].key>heap[child+1].key)
            child++;
        if (temp.key < heap[child].key) break;
            heap[parent]=heap[child];
            parent=child;
            child*=2;
    }
    heap[parent]=temp;

    return root;
}
