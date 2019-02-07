//
//  BankAccount.hpp
//  Cpluspluslab
//
//  Created by Benjamin Gertz on 4/3/18.
//  Copyright © 2018 Benjamin Gertz. All rights reserved.
//


#include <stdio.h>

#ifndef BANKACCOUNT_H_
#define BANKACCOUNT_H_

class BankAccount{
    
public:
    BankAccount();
    BankAccount(char *n, double b);
    
    char *getName();
    double getBalance();
    
    //like override in java
    virtual void deposit(double a);
    virtual bool withdraw(double a);
    
    bool transfer(BankAccount *a, double b);
    
private:
    char name[100];
    double balance;
};

#endif


