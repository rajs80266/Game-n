#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int level,start,n,temp,user,comp,gap;

    //Initializing The game accoring to User
    printf("1-Easy\n2-Medium\n3-Hard\nEnter Level:");
    scanf("%d",&level);

    printf("\n\nStart by you(1)\nStart by computer(2)\nEnter your option:");
    scanf("%d",&start);

    printf("\n\nEnter number n:");
    scanf("%d",&n);
    printf("Enter maximum number that can be increased:");
    scanf("%d",&gap);
    system("cls");
    gap++;

    //temp leading to win
    temp=n-1;
    while(temp>0)
        temp=temp-gap;
    temp=temp+gap;

    if(start==2)
    {
        if(temp<gap && temp<n && level==3)
            comp=temp;
        else
            comp=1;
        printf("%d\n",comp);
    }
    else
        comp=0;

    if(n==1 && start==2)
        printf("Congratulations....\nYou Won.");
    else
    {
        while(1)
        {
            printf("Enter a number:");
            scanf("%d",&user);
            if(user<=n && user<comp+gap && user>comp)
            {
                if(user==n)
                {
                    printf("You Lost by Computer...\n");
                    break;
                }

                //depending on level leading to a game
                if(level==3 ||( level==2 && user>(n-(gap*2)) ) || user>(n-gap) )
                {
                    while(temp<user)
                        temp=temp+gap;

                    comp=temp;
                    if(temp==user)
                        comp++;
                }
                //if level is low let computer play randomly
                else
                {
                    srand(time(0));
                    comp = ( rand()%(gap-1) ) + (user+1);
                    if(comp>=n)
                    {
                        if(user<n-1)
                            comp=n-1;
                        else
                            comp=n;
                    }
                }

                system("cls");
                printf("%d\n",comp);
                if(comp==n)
                {
                    printf("Congratulations....\nYou Won.");
                    break;
                }
            }
            //when user plays beyond rules!!!!
            else
            {
                system("cls");
                printf("Dont try to cheat!!!\n");
                if(comp!=0)
                    printf("%d\n",comp);
            }
        }
    }

    return 0;
}
