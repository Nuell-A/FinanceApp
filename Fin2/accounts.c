//
//  accounts.c
//  Fin2
//
//  Created by Rodrigo on 4/5/21.
//

#include "accounts.h"
#include "user.h"

/*************************************************************************************
    Creates account for user
 ************************************************************************************/
void createAccount(char userName[])
{
    struct Accounts account1;
    
    char fileName[128], str1[128], str2[128];
    char *str3;// str4[8], str5[8], str6[8];

    printf("Create account name: \n");
    scanf("%s", account1.name);

    printf("Account type:  \n");
    scanf("%s", account1.type);
    
    printf("Starting balance: \n");
    scanf("%s", str2);
    account1.principal = strtod(str2, &str3);
    
    sprintf(fileName, "/Users/Drigo/Desktop/dataSink/%s_%s.txt", userName, account1.name);
    printf("%s\n\n",fileName);
    
    FILE *fp;
    fp = fopen (fileName, "w");
    
    sprintf(str1,"AcctName: %s\n", account1.name);
    for(int i = 0; str1[i] != '\0'; i++)
    {
        fputc(str1[i], fp);
    }
 
    sprintf(str1,"AcctType: %s\n", account1.type);
    for(int i = 0; str1[i] != '\0'; i++)
    {
        fputc(str1[i], fp);
    }
    
    sprintf(str1,"AcctPrincipal: %.2f\n", account1.principal);
    for(int i = 0; str1[i] != '\0'; i++)
    {
        fputc(str1[i], fp);
    }
    
    fclose(fp);
    
    updateUser(userName, account1.name);
    
    printf("Account created.\n");
}

/*************************************************************************************
    Shows all user accounts
 ************************************************************************************/
void viewAccounts(char userName[])
{
    struct Accounts account1;
    
    char fileName[128], str1[64];
    int i = 1;
    
    printf("\n%s's Accounts:\n", userName);

    sprintf(fileName, "/Users/Drigo/Desktop/dataSink/%s_accountInfo.txt", userName);
    
    FILE *fp;
    fp = fopen (fileName, "r");
    
    while((fscanf(fp, "%s", str1) == 1))
    {
        if(strcmp(str1, "AcctName:") == 0)
        {
            fscanf(fp, "%s", account1.name);
            printf("Account%d - %s\n", i, account1.name);
            i++;
        }
    }

    if (feof(fp))
    {
        fclose(fp);
        printf("\nGood shit happened.\n");
   //     printf("Account name: %s\n", account1.name);
   //     printf("Start date: %s\n\n", account1.start_date);
   //     printf("Starting balance: %.2f\n\n", account1.principal);
   //     printf("End balance: %.2f.\n", account1.balance);
    }
    else
    {
        fclose(fp);
        printf("\nBad shit happened.\n\n");
    }
}

