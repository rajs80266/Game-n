#include <stdio.h>
#include <stdlib.h>

int main()
{
    int start,n,temp,user,comp;

    printf("Start by you(1)\n");
    printf("Start by computer(2)\n");
    scanf("%d",&start);
    system ("cls");

    printf("Enter number n:");
    scanf("%d",&n);

    temp=n;
    temp--;
    while(temp>0)
        temp=temp-4;
    temp=temp+4;

    if(start==2)
    {
        printf("1\n");
        comp=1;
    }
    else
        comp=0;

    if(n==1 && start==2)
        printf("Congratulations....\nYou Won.");
    else
    {
        printf("Enter a number:");
        while(1)
        {
            scanf("%d",&user);
            if(user<=n && user<comp+4 && user>comp)
            {
                if(user==n)
                {
                    printf("You Lost by Computer...\n");
                    break;
                }

                while(temp<user)
                    temp=temp+4;

                comp=temp;
                if(temp==user)
                    comp++;

                system ("cls");
                printf("%d\n",temp,comp);
                if(comp==n)
                {
                    printf("Congratulations....\nYou Won.");
                    break;
                }
            }
            else
            {
                system ("cls");
                printf("Dont try to cheat!!!\n");
                if(comp!=0)
                    printf("%d\n",comp);
                printf("Enter a number again:");
            }
        }
    }
    return 0;
}
