#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//decimal to binary--------------------------------------------------------------------------------
char* decbi(int n)
{
    static char final[100];

    int index=0;
    while(n!=0)
    {
        final[index]=n%2+'0';
        n=n/2;
        index++;
    }

    final[index]='\0';
    strrev(final);
    return(final);
}

//binary to decimal-------------------------------------------------------------------------------

int bidec(char b[])
{
    int num=0;
    strrev(b);
    for(int i=0;i<strlen(b);i++)
    {
        if(b[i]=='1')
        {
            num=num+pow(2,i);
        }
    }

    return(num);
}

//BINARY ADDITION--------------------------------------------------------------------------------

char* biadd(char a[],char b[])
{
    strrev(a);
    strrev(b);
    int size1=strlen(a);
    int size2=strlen(b);
    static char final[100];
    int index=0;
    int carry=0;

    if(size1>size2)
    {
        for(int i=0;i<size1;i++)
        {
            int n;

            if(i<size2)
            {
                n=(a[i]-'0')+(b[i]-'0');
            }
            else
            {
                n=(a[i]-'0');
            }

            if(n==1)
            {
                if(carry==0)
                {
                    final[index]=n+'0';
                }
                else
                {
                    final[index]='0';
                    carry=1;
                }
            }
            else if(n==0)
            {
                final[index]=carry+'0';
                carry=0;
            }
            else
            {
                final[index]=carry+'0';
                carry=1;
            }

            index++;
        }

    }
    else
    {
        for(int i=0;i<size2;i++)
        {
            int n;

            if(i<size1)
            {
                n=(a[i]-'0')+(b[i]-'0');
            }
            else
            {
                n=(b[i]-'0');
            }

            if(n==1)
            {
                if(carry==0)
                {
                    final[index]=n+'0';
                }
                else
                {
                    final[index]='0';
                    carry=1;
                }
            }
            else if(n==0)
            {
                final[index]=carry+'0';
                carry=0;
            }
            else
            {
                final[index]=carry+'0';
                carry=1;
            }

            index++;
        }
    }

    final[index]=carry+'0';
    final[index+1]='\0';

    strrev(final);

    return(final);
}
//----------------------------------------------------------------------------------------------

//BINARY MULTIPLICATON -------------------------------------------------------------------------

void bimul(char a[], char b[])
{
     strrev(a);
    strrev(b);

    int size1=strlen(a);
    int size2=strlen(b);
    static char final[100];
    int size=0;

    for(int i=0;i<size1+size2;i++)
    {
        final[i]='0';
    }
    
    for(int i=0;i<size1;i++)
    {
        if(a[i]=='1')
        {
            for(int j=0;j<size2;j++)
            {
                if(b[j]=='1')
                {
                    int c=1;
                    int k=0;

                    while(c!=0)
                    {
                        if(final[i+j+k]=='1')
                        {
                            final[i+j+k]='0';
                            c=1;
                        }
                        else
                        {
                            final[i+j+k]='1';
                            c=0;
                        }

                        k++;
                    }

                    size=i+j+k;
                }
            }
        }

    } 

    final[size]='\0';
    strrev(final);
    printf("product of the given binary numbers is:%s \n",final);
}

//----------------------------------------------------------------------------------------------

int main()
{
    char a[100];
    char b[100];

    printf("enter 1st number: ");
    scanf("%s",&a);

    printf("enter 2nd number: ");
    scanf("%s",&b);


    //BINARY----------------------
    //addition
     printf("binary addition of the given binary elements gives %s\n",biadd(a,b));

     //multiplication.
     bimul(a,b);

    
    //----------------------------
    
    return(0);
}