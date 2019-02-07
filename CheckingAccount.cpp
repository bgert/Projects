//
//  CheckingAccount.cpp
//  Cpluspluslab
//
//  Created by Benjamin Gertz on 4/3/18.
//  Copyright © 2018 Benjamin Gertz. All rights reserved.
//

#include "CheckingAccount.hpp"
//He will want #include "CheckingAccount.h"
#include "BankAccount.h"

#include <iostream>
#include <cstream>

using namespace std;

CheckingAccount:: CheckingAccount(char *n, double b): BankAccount(n, b){
    transactionCount = 0;
}

bool CheckingAccount::deductFees(){
    double fees = transactionCount * TRANSACTION_FEE;
    
    if (BankAccount::withdraw(fees)){
        transactionCount = 0;
        return 1;
    }
    cout<< "Not enough to pay the fee." <<endl;
    return 0;
}

void CheckingAccount::deposit(double amount){
    
    transactionCount++;
    BankAccount::deposit(amount);
}

bool CheckingAccount::withdraw(double amount){
    transactionCount++;
    if(BankAccount::withdraw(amount)){
        return 1;
    }
    return 0;
}
