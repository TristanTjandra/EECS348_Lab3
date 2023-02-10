/*
 * Program1.c
 *
 *  Created on: 9 Feb 2023
 *      Author: tristan
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int average(float arr[], int length)
{
    float total;
    float average;
    for(int i = 0; i<length;i++)
    {
        total = total + arr[i];
    }
    return average = total/length;
}

int main()
{
    char* movingM[7] =
    {
        "January\t  -  June\t",
        "February  -  July\t",
        "March\t  -  August\t",
        "April\t  -  September\t",
        "May\t  -  October\t",
        "June\t  -  November\t",
        "July\t  -  December\t",
    };

    float ave = 0;
    float sales[12];
    char* months[12] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };

    FILE* in_file = fopen("input.txt", "r");

    if(!in_file){
        printf("Error opening file!");
        exit(1);
    }

    for (int i = 0; i<12; i++) //reading from input file
    {
        fscanf(in_file, "%f", &sales[i]);
    }
    fclose(in_file); //closing input file

    printf("Month \t \tSales\n"); //print "Month        Sales"

    for (int i = 0; i<12; i++) //print the month and respective sale
    {
        printf("%s\t\t%.2f\n", months[i], sales[i]);

    }

    int indexMin = 0;
    for(int i = 1; i <12; i++)
    {
        if(sales[i] < sales[indexMin])
        {
            indexMin = i;
        }
    }

    int indexMax = 0;
    for(int i = 1; i <12; i++)
    {
        if(sales[i] > sales[indexMax])
        {
            indexMax = i;
        }
    }

    ave = average(sales, 12);

    printf("\nSales summary:\n");
    printf("Minimum sales:\t%.2f\t(%s)\n", sales[indexMin], months[indexMin]);
    printf("Maximum sales:\t%.2f\t(%s)\n", sales[indexMax], months[indexMax]);
    printf("Average sales:\t%.2f\n", ave);

    printf("\nSix-Month Moving Average Report:\n");


    for(int i = 0; i <7; i++)
    {
        float sum;
        float curAve;
        for(int j = i; j<i+6; j++)
        {
            sum = sum + sales[j];
        }
        curAve = sum/6;
        printf("%s\t%.2f\n", movingM[i], curAve);
        sum = 0;
        curAve = 0;
    }


    int temp;
    char* temp1;

    for(int i=0; i<12;i++)
    {
        for(int j = 0; j < 11; j++)
        {
            if(sales[j]<sales[j+1])
            {
                temp = sales[j];
                temp1 = months[j];
                sales[j] = sales[j+1];
                months[j] = months[j+1];
                sales[j+1] = temp;
                months[j+1] = temp1;
            }
        }
    }


    printf("\nSales Report (Highest to Lowest):\n");
    printf("Month \t \tSales\n");
    for(int i = 0; i<12; i++)
    {
        printf("%s\t\t%.2f\n", months[i], sales[i]);
    }
}
