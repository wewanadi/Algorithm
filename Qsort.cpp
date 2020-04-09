#include <bits/stdc++.h>
#include <algorithm>
#define N 100000

using namespace std;
void sswap(int *a,int *b);
void quicksort(int* data,int sz);

int main () {
    char ch[N],*tok;
    int data[N],n,i,j,k;
    FILE *read,*write;

    read=fopen("input.txt","rb");  	//�}��INPUT��
    fgets(ch,N,read);
    fclose(read);			//����INPUT��


    tok=strtok (ch," \n");
    for (i=0;tok!=NULL;i++) {
        data[i]=atoi(tok);
        tok=strtok(NULL," \n");
    }
    n=i;

    quicksort(data,n);		//�Ƨ� �}�C��m �M�ƧǪ��Ȧ��X��

    write=fopen("output.txt","wb");	//�}��OUTPUT��
    for (int a=0;a<n;a++)
        fprintf (write,"%d ",*(data+a));
    fclose(write);			//����output��

return 0;
}

void quicksort(int* data,int sz){
#define last data+sz-1
    int i,j,k;
    srand(time(NULL));
        sswap(data+rand()%sz,data+sz-1);

    for (i=j=k=0;i<sz;i++)
        if (*(data+i)>*(data+sz-1)) {
            for (k=max(i+1,k);k<sz;k++)
            if (*(data+k)<=*(data+sz-1))   {
                sswap(data+i,data+k);
                break;
            }
            if (k==sz) {
                sswap(data+i,last);
                break;
            }
    }

    /*for (int a=0;a<sz;a++)
        printf ("%d ",*(data+a));
    printf ("!!%d %d %d\n",i,j,k);  */

    if (i>=2)				//����I�H�e���ϰ�
        quicksort(data,i-1);
    if (k-i>=2)				//����I�H�᪺�ϰ�
        quicksort(data+i,k-i);
}

void sswap(int *a,int *b) {		//�ܴ����и̭����Ȫ����
    int t=*a;
    *a=*b;
    *b=t;
}

