//
//  CheckingAccount.hpp
//  Cpluspluslab
//
//  Created by Benjamin Gertz on 4/3/18.
//  Copyright © 2018 Benjamin Gertz. All rights reserved.
//

#ifndef CheckingAccount_H_
//#define CheckingAccount_hpp
#define CHECKINGACCOUNT_H_
#include "BankAccount.h"

class CheckingAccount : public BankAccount {
public:
    CheckingAccount(char *n, double b);
    
    bool withdraw(double a);
    
    void deposit(double a);
    
    bool deductFees();
    
private:
    int transactionCount;
    const double TRANSACTION_FEE = 1.00;
    
};

#endif /* CheckingAccount_hpp */
