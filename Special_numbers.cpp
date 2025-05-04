/*1. Write a C++ menu-driven program to determine whether a number is a  Palindrome, Armstrong, or Perfect Number.
Normal variable and array declarations are not allowed. Utilize dynamic memory allocation (DMA). Design proper functions,
 maintain boundary conditions, and follow coding best practices. The menu is as follows,

a.  Palindrome
b.  Armstrong Number
c.  Perfect Number
d.  Exi*/


#include <iostream>
#include <cstdlib>
using namespace std;
int Armstrong_number(int *num);
int Perfect_number(int *num);
int Palindrome(int *num);

int main()
{
    int *choice=(int*)malloc(sizeof(int));
    int *num1=(int*)malloc(sizeof(int));
    while(true)
    {
        cout << "Enter your option=\n1.Armstrong number\n2.Perfect number\n3.Palindrome\n4.Exit\n";
        cin >> *choice;
        if (*choice==1)
        {
            cout << "Enter a number=\t";
            cin >> *num1;
            if (Armstrong_number(num1))
            {
                cout << "The number is an armstrong number\n";
            }
            else
            {
                cout << "The number is not an armstrong number\n";
            }
            

        }

        else if (*choice==2)
        {
            cout << "Enter a number=\t";
            cin >> *num1;
        
            if (Perfect_number(num1))
            {
                cout << "The number is a perfect number\n";
            }
            else
            {
                cout << "The number is not a perfect number\n";
            }
            
        }

        else if (*choice==3)
        {
            cout << "Enter a number=\t";
            cin >> *num1;
            if (Palindrome(num1))
            {
                cout << "The number is a palindrome number\n";
            }
            else
            {
                cout << "The number is not a palindrome number\n";
            }
            
        }

        else
        {
            break;
        }
        

    }

}

int Armstrong_number(int *num)
{
    int *Digit=(int*)calloc(1,sizeof(int));
    int *temp=(int*)malloc(sizeof(int));
    int *num2=(int*)calloc(1,sizeof(int));
    *temp=*num;
    while(*temp>0)
    {
        *temp=*temp/10;
        *Digit+=1;
    }
    
    *temp=*num;
    //cout << "\n" << *num2;
    while(*temp>0)
    {
        *num2=*num2+(((*temp)%10)**Digit);
        cout << *num2;
        *temp=*temp/10;
    }
    if (*num2==*num)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Palindrome(int *num)
{
    int *temp=(int*)malloc(sizeof(int));
    int *num2=(int*)calloc(1,sizeof(int));
    int *remainder=(int*)malloc(sizeof(int));
    *temp=*num;
    while(*temp>0)
    {
        *remainder=(*temp)%10;
        *num2 = ((*num2)*10)+*remainder;
        *temp=*temp/10;

    }
    if (*num2==*num)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Perfect_number(int *num)
{
    int *i=(int*)malloc(sizeof(int));
    int *temp=(int*)malloc(sizeof(int));
    int *num2=(int*)malloc(sizeof(int));
    *temp=*num;
    for ((*i)=1;(*i)<(*num);(*i)++)
    {
        if ((*num)%(*i)==0)
        {
            *num2=*num2+(*i);
        }
    }
    if (*num2==*num)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    

}


