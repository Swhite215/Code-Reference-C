//
//  main.c
//  binToDec
//
//  Created by Vincent, Gary on 9/28/20.
//  Copyright © 2020 hfc. All rights reserved.
//
/*C program to convert number from binary to decimal*/
 
#include <stdio.h>
#include <string.h>
#include <math.h>
 
int main()
{
    char bin[32]={0};
    int  dec,i;
    int  cnt;   /*for power index*/
 
    printf("Enter binary value: ");
    scanf("%s", bin);
 
    cnt=0;
    dec=0;
    for(i=(strlen(bin)-1);i>=0;i--)
    {
        dec=dec+(bin[i]-0x30)*pow((double)2,(double)cnt);
        cnt++;
    }
 
    printf("DECIMAL value is: %d",dec);
 
    return 0;
}
