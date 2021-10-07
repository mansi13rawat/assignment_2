#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char* decadd(char a[], char b[])
{
    int size1=strlen(a);
    strrev(a);

    int size2=strlen(b);
    strrev(b);
    int carry=0;

    static char final[100];
    int i=0;

    if(size1>size2)
    {
       for(i=0;i<size1;i++)
       {
           int n=0;
           if(i<size2)
           {
               n=(a[i]-'0')+(b[i]-'0');
           }
           else
           {
               n=(a[i]-'0');
           }

           n=n+carry;

           final[i]=(n%10)+'0';
           carry=n/10;
       }

       while(carry!=0)
       {
           final[i]=(carry%10)+'0';
           carry=carry/10;
       }
    }
    else
    {
        for(i=0;i<size2;i++)
       {
           int n=0;
           if(i<size1)
           {
               n=(a[i]-'0')+(b[i]-'0');
           }
           else
           {
               n=(a[i]-'0');
           }

           n=n+carry;

           final[i]=(n%10)+'0';
           carry=n/10;
       }

       while(carry!=0)
       {
           final[i]=(carry%10)+'0';
           carry=carry/10;
       }
    }
    final[i]='\0';

    return(strrev(final));
}

void decmul(char a[],char b[])
{
    int size1=strlen(a);
    strrev(a);

    int size2=strlen(b);
    strrev(b);

    int carry=0;
    char final[100];
    int size=0;

    for(int i=0;i<size1+size2;i++)
    {
        final[i]='0';
    }

    for(int i=0;i<size1;i++)
    {
        int n;

        for(int j=0;j<size2;j++)
        {
            n=(a[i]-'0')*(b[j]-'0');

            n=n+carry;

            if(n<10)
            {
                carry=0;
            }
            else
            {
                carry=n/10;

                n=n%10;
            }
                n=n+(final[i+j]-'0');
                
                final[i+j]=(n%10)+'0';
                
                int c=n/10;
                int k=1;

                while(c!=0)
                {
                    c=c+(final[i+j+k]-'0');
                    final[i+j+k]=(c%10)+'0';
                    c=c/10;
                }

                size=i+j+k;

        }

    }

    final[size]=(carry+'0');

    strrev(final);
    printf("multiplication product of your given numbers is: %s", final);
}


int main()
{
    char a[100];
    char b[100];

   printf("enter numbers: \n");
   printf("a: ");
   scanf("%s",&a);
   printf("b: ");
   scanf("%s",&b);

    //printf("sum of given decimal numbers is:%s", decadd(a,b));

    decmul(a,b);


    return(0);
}