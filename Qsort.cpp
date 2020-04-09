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

    read=fopen("input.txt","rb");  	//開啟INPUT檔
    fgets(ch,N,read);
    fclose(read);			//關閉INPUT檔


    tok=strtok (ch," \n");
    for (i=0;tok!=NULL;i++) {
        data[i]=atoi(tok);
        tok=strtok(NULL," \n");
    }
    n=i;

    quicksort(data,n);		//排序 陣列位置 和排序的值有幾個

    write=fopen("output.txt","wb");	//開啟OUTPUT檔
    for (int a=0;a<n;a++)
        fprintf (write,"%d ",*(data+a));
    fclose(write);			//關閉output檔

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

    if (i>=2)				//選取點以前的區域
        quicksort(data,i-1);
    if (k-i>=2)				//選取點以後的區域
        quicksort(data+i,k-i);
}

void sswap(int *a,int *b) {		//變換指標裡面的值的函數
    int t=*a;
    *a=*b;
    *b=t;
}

