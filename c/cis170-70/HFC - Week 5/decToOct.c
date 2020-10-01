//
//  main.c
//  decToOct
//
//  Created by Vincent, Gary on 9/28/20.
//  Copyright © 2020 hfc. All rights reserved.
//

/*C program to convert number from decimal to octal*/
 
#include <stdio.h>
 
int main()
{
    int     number,cnt,i;
    int     oct[32];
 
    printf("Enter decimal number: ");
    scanf("%d",&number);
 
     
    cnt=0;              /*initialize index to zero*/
    while(number>0)
    {
        oct[cnt]=number%8;
        number=number/8;
        cnt++;
    }
 
    /*print value in reverse order*/
    printf("Octal value is: ");
    for(i=(cnt-1); i>=0;i--)
        printf("%d",oct[i]);
 
    return 0;
}
