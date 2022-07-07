//
//  utility.c
//  Fin2
//
//  Created by Rodrigo on 4/10/21.
//

#include "utility.h"
#include "accounts.h"
#include <time.h>

/************************************************************************************
 Creates new file and writes a message
 ************************************************************************************/
void f_write(char mess[])
{
    FILE *fp;
    fp = fopen ("/Users/Drigo/Desktop/dataSink/data2.xls", "w");
        
    for(int i = 0; mess[i] != '\n'; i++)
    {
        fputc(mess[i], fp);
    }
        
    fclose(fp);
}

/************************************************************************************
 Reads data in from .txt file with specified structure
 Statrts with "Name", ends with "total"
 Prints account balance and item description, left to right
 ************************************************************************************/
int f_read(void)
{
    char str1[32], item[32]; //fileName[256]; str2[8];
    char *str3;// str4[8], str5[8], str6[8];
    double amount;
  //  double out = 0, in = 0;
    struct Accounts account1;
    int i = 0;
    
    FILE *fp;
    fp = fopen("/Users/Drigo/Desktop/dataSink/data03.txt", "r"); //reset the file pointer

 //   fscanf(fp, "%s", str1);
    while((fscanf(fp, "%s", str1) == 1))
    {
       if(strcmp(str1, "Name") == 0)
       {
            fscanf(fp, "%s", account1.name);
            fscanf(fp, "%s", str1);
            account1.principal = strtod(str1, &str3);
            fscanf(fp, "%s", account1.start_date);
        }
        else
        {
            printf("Try again.");
        }
        
        account1.balance = account1.principal;
        while((fscanf(fp, "%s", str1) == 1) && (strcmp(str1, "total") != 0))
        {
            amount = strtod(str1, &str3);
 //           if(amount < 0)
 //           {
 //               out = out + amount;
//            }
//          else in = in + amount;
            
            account1.balance = account1.balance + amount;
            fscanf(fp, "%s", item);
            // itemize(amount, item);
  //          printf("Charge amount: %.2f\n", amount);
  //          printf("Charge description: %s\n", item);
 //           printf("Current balance: %.2f\n\n", account1.balance);
        }
        
        if(strcmp(str1, "total") == 0)
        {
            printf("Account name: %s\n", account1.name);
            printf("Start date: %s\n", account1.start_date);
            printf("Starting balance: %.2f\n\n", account1.principal);
     //       printf("Cashflow\n In: %.2f\n Out: %.2f\n", in, out);
     //       printf("Net: %.2f\n\n", in+out);
            printf("End balance: %.2f.\n\n", account1.balance);
        }
        
        i++;
    }
          
    if (feof(fp))
    {
        fclose(fp);
        printf("Good shit happened.\n");
        printf("No. of Accts: %d", i);
    }
    else
    {
        fclose(fp);
        printf("Bad shit happened.\n\n");
    }
    
    return 0;
}

/************************************************************************************
 // Get current date and time - modified from unknown friendly internet user
 ************************************************************************************/
void getTime(char option[])
{
    int hours, minutes, seconds, day, month, year;
    time_t now;
    
    struct tm *local = localtime(&now);

    hours = local->tm_hour;          // get hours since midnight (0-23)
    minutes = local->tm_min;         // get minutes passed after the hour (0-59)
    seconds = local->tm_sec;         // get seconds passed after minute (0-59)

    day = local->tm_mday;            // get day of month (1 to 31)
    month = local->tm_mon + 1;       // get month of year (0 to 11)
    year = local->tm_year + 1900;    // get year since 1900

    time(&now);
    ctime(&now);
    
    if (strcmp(option, "now") == 0)
    {
        // Convert to local time format and print to stdout
        printf("Formal: %s", ctime(&now));
    }
    else if(strcmp(option, "mytime") == 0)
    {
        // print local time
        printf("Time: %02d:%02d:%02d\n", hours, minutes, seconds); // modified for 24 hour time
    }
    else if(strcmp(option, "day") == 0)
    {
        // print current date
        printf("Date: %02d/%02d/%d\n", month, day, year);
    }
    else
    {
        printf("idk");
    }
    
    printf("\n");
}

/*************************************************************************************
    Need to do
 ************************************************************************************/
void itemize(double amount, char item[])
{
 //   if(strcmp(item,"SAV") == 0)
   // {
        
   // }
}

void startList(void)
{
    int i;
    char item[10][11];

    for(i=0; i<2; i++)
    {
        printf(" Enter item%d\n", i+1);
        scanf("%s",item[i]);
    }
    
    printf("%s\n", item[0]);
    printf("%s\n", item[1]);
    printf("Hey we fucking did it.");
}
