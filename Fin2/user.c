//
//  user.c
//  Fin2
//
//  Created by Rodrigo on 4/5/21.
//

#include "user.h"
#include "interface.h"

/*************************************************************************************
 Creates file for new user with username and password
 ************************************************************************************/
void createUser(char mess[], char userName[])
{
    char fileName[128], password[64];
 
    printf("Create password: \n");
    scanf("%s", password);
    printf("\nThank you.\n");

    sprintf(fileName, "/Users/Drigo/Desktop/dataSink/%s_accountInfo.txt", userName);
    printf("%s\n\n",fileName);
    
    FILE *fp;
    fp = fopen (fileName, "w");
  //  fputs("hey suckers\n", fp);
    
    for(int i = 0; mess[i] != '\n'; i++)
    {
        fputc(mess[i], fp);
    }
    
    fputs("\n\n",fp);
    fputs("Username: ", fp);
    
    for(int i = 0; userName[i] != '\0'; i++)
    {
        fputc(userName[i], fp);
    }
    
    fputs("\n\n",fp);
    fputs("Password: ", fp);

    for(int i = 0; password[i] != '\0'; i++)
    {
        fputc(password[i], fp);
    }
    
    fclose(fp);
    
    printf("Peofile has been created.\n");
    printf("Welcome\n");
    menuUser(userName);
}

/*************************************************************************************
 Open previously made file to confirm account username and password
 ************************************************************************************/
void openUser(char userName[])
{
    char fileName[128], password[64], str1[16]; // str2[16];

    printf("Enter password: \n");
    scanf("%s", password);
    printf("password entered: %s\n", password);
    printf("\nThank you.\n\n");

    sprintf(fileName, "/Users/Drigo/Desktop/dataSink/%s_accountInfo.txt", userName);

    FILE *fp;
    fp = fopen (fileName, "r");
    
    if(fp)
    {
        int i = 1;

        while((fscanf(fp, "%s", str1) == 1) && (strcmp(str1, "Password:") != 0))
        {
            printf("Waiting %d...\n", i);
            i++;
        }
        if(strcmp(str1, "Password:") == 0)
        {
            fscanf(fp, "%s", str1);
            printf("%s\n", str1);

            if(strcmp(str1, password) == 0)
            {
                printf("Logging in...\n");
                printf("Welcome back.\n");
                menuUser(userName);
            }
            else
            {
                printf("Error incorrect password.\n");
            }
        }
    }
    else
    {
        printf("Error.\nUsername not found\n");
    }
    
    fclose(fp);
}

/*************************************************************************************
    Updates user account info file with new account
 ************************************************************************************/
void updateUser(char userName[], char accountName[])
{
    char fileName[128], str1[64];
    
    sprintf(fileName, "/Users/Drigo/Desktop/dataSink/%s_accountInfo.txt", userName);

    FILE *fp;
    fp = fopen (fileName, "a");
    
    sprintf(str1,"\nAcctName: %s\n", accountName);
   
    for(int i = 0; str1[i] != '\0'; i++)
    {
        fputc(str1[i], fp);
    }
    
    fclose(fp);
    
}
