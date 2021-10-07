#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void add(int a,int b)
{
    for(int i=0;i<(a+b);i++)
    {
        printf("|");
    }
    printf("\n");
}

void mul(int a, int b)
{
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            printf("|");
        }
    }
    printf("\n");
}

int main()
{
    char a[100];
    char b[100];
    printf("enter your numbers:\n");
    printf("a: ");
    scanf("%s",&a);
    printf("b: ");
    scanf("%s",&b);

    int size1=strlen(a);
    int size2=strlen(b);

    //addition---------------------
    printf("addition sum of the given unary numbers is: ");
    add(size1,size2);
    //multiplication---------------
    printf("multiplication product of the given unary numbers is: ");
    mul(size1,size2);
}