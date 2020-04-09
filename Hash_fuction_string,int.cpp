#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

unsigned int SDBM_Hash(char *str)
{
    unsigned int a = 0;

    while (*str)
        a = (*str++) + (a << 6) + (a << 16) - a;

    return (a & 0x7FFFFFFF);
}

unsigned int RS_Hash(char *str)
{
    unsigned int b = 378551;
    unsigned int a = 63689;
    unsigned int c = 0;

    while (*str)
    {
        c = c * a + (*str++);
        a *= b;
    }

    return (c & 0x7FFFFFFF);
}

unsigned int JS_Hash(char *str)
{
    unsigned int a = 1315423911;

    while (*str)
        a ^= ((a << 5) + (*str++) + (a >> 2));

    return (a & 0x7FFFFFFF);
}

int main () {
    string b;
    cin >> b;

    //SDBM_Hash 將 string 轉成 key
    SDBM_Hash (&b[0]);
    printf ("%o\n",SDBM_Hash (&b[0]));
    printf ("%o\n",SDBM_Hash ("apple"));

    //RS_Hash 將 string 轉成 key
    RS_Hash (&b[0]);
    printf ("%o\n",RS_Hash (&b[0]));
    printf ("%o\n",RS_Hash ("apple"));

    //JS_Hash 將 string 轉成 key
    JS_Hash (&b[0]);
    printf ("%o\n",JS_Hash (&b[0]));
    printf ("%o\n",JS_Hash ("apple"));

    return 0;
}
