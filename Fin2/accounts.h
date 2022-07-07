//
//  accounts.h
//  Fin2
//
//  Created by Rodrigo on 4/5/21.
//

#ifndef accounts_h
#define accounts_h

#include <stdio.h>
#include <string.h>

struct Accounts
{
    char name[32];
    char type[16];
    char start_date[8];
    double principal;
    double balance;
};

void createAccount(char userName[]);
void viewAccounts(char userName[]);

#endif /* accounts_h */
