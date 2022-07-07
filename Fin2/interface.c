//
//  interface.c
//  Fin2
//  Created by Rodrigo on 2/27/21.
//

#include "interface.h"
#include "user.h"
#include "accounts.h"

/*************************************************************************************
    User  menu
 ************************************************************************************/
void menuUser(char userName[])
{
    printf("Welcome to the user menu %s.\n\n", userName);
    printf("[1] - Accounts\n");
    printf("[2] - Budgets\n");
    printf("[3] - Networth\n");
    
    scanf("%d", &option);
    
    if(option == 1)
    {
        menuAccount(userName);
    }
    else printf("bad shit happened.");
    
}

/*************************************************************************************
    Accounts menu
 ************************************************************************************/
void menuAccount(char userName[])
{
    printf("Welcome to accounts Menu %s.\n\n", userName);
    printf("[1] - Create Account\n");
    printf("[2] - View Accounts\n");
    printf("[3] - Update Accounts\n");
    
    scanf("%d", &option);
    
    if(option == 1)
    {
        createAccount(userName);
    }
    else if(option == 2)
    {
       // printf("Not quite yet.");
        viewAccounts(userName);
    }
    else printf("bad shit happened.");

}

/*************************************************************************************
    Main menu
 ************************************************************************************/
void menuMain(void)
{
    char userName[64];
    printf("Welcome. Please sign in or create a new profile.\n\n");
    
    printf("[1] - Sign in\n");
    printf("[2] - Create profile\n");
    
    scanf("%d", &option);
    
    printf("You chose: %d\n", option);
    if(option == 1)
    {
        printf("Enter username: \n");
        scanf("%s", userName);
        
        openUser(userName);
    }
    else if(option == 2 )
    {
        printf("Create username: \n");
        scanf("%s", userName);
        
        char stim[120] = "New profile setup.\n)";
        
        createUser(stim, userName);
    }
    else printf("idk\n\n");    
}
