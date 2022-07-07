//
//  budgets.h
//  Fin2
//
//  Created by Rodrigo on 5/21/21.
//

#ifndef budgets_h
#define budgets_h

#include <stdio.h>

struct budgets
{
    char name[32];
    char type[16];
    char start_date[8];
    double principal;
    double balance;
};

void createBudget(void);

#endif /* budgets_h */
