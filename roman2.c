#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


//DECIMAL TO ROMAN---------------------------------------------------------------------------------
char* toroman(int n)
{
    char symbol[]={'I','V','X','L','C','D','M'};
    int value[]={1,5,10,50,100,500,1000};
    static char final[100];
    int i=0;
    int index=0;
    char x,y,z;

    while(n!=0)
    {
        x=symbol[i];
        y=symbol[i+1];
        z=symbol[i+2];
        int t=n%10;

        if(t<=3)
        {
            while(t!=0)
            {
                final[index]=x;
                index++;
                t--;
            }
        }
        else if(t==5)
        {
            final[index]=y;
            index++;
        }
        else if(t==9)
        {
            final[index]=z;
            index++;
            final[index]=x;
            index++;
        }
        else if(t==4)
        {
            final[index]=y;
            index++;
            final[index]=x;
            index++;
        }
        else
        {
            int extra=t-5;

            while(extra!=0)
            {
                final[index]=x;
                index++;
                extra--;
            }
            final[index]=y;
            index++;
        }

        n=n/10;
        i=i+2;
    }

    final[index]='\0';
    strrev(final);
    return(final);
}

//ROMAN TO DECIMAL---------------------------------------------------------------------------
int romdec(char r[])
{
    char symbol[]={'I','V','X','L','C','D','M'};
    int value[]={1,5,10,50,100,500,1000};

    int num=0;
    int high=0;
    int low=0;
    int size=strlen(r);
    
    for(int i=0;i<size;i++)
    {
        int index=0;

        while(high==0 || low==0 && i+1<size)
        {
            //printf("here\n");
            if(r[i]==symbol[index] && high==0)
            {
                high=value[index];
            }
            else if(r[i+1]==symbol[index] && low==0)
            {
                low=value[index];
            }

            index++;
        }
        

        if(high<low)
        {
            num=num+low-high;
            low=0;
            high=0;
            i++;
        }
        else if(low==0)
        {
            num=num+high;
        }
        else
        {
            num=num+high;
            high=low;
            low=0;
        }  
    }

    return(num);
}

int main()
{
    char a[100];
    char b[100];

    printf("enter 1st number: ");
    scanf("%s",&a);

    printf("enter 2nd number: ");
    scanf("%s",&b);


    int x=romdec(a);
    int y=romdec(b);
    printf("addition of the given numbers %s and %s is: %s\n",a,b,toroman(x+y));
    printf("multiplication product of given numbers %s and %s is: %s",a,b,toroman(x*y));
    
    return(0);
}