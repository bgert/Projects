//
//  SavingsAccount.cpp
//  Cpluspluslab
//
//  Created by Benjamin Gertz on 4/3/18.
//  Copyright © 2018 Benjamin Gertz. All rights reserved.
//

#include "SavingsAccount.hpp"
//above what apple wanted below what avik wanted
#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(char *n, double b, double i): BankAccount(n,b){
    interest = i/100.00;
    
}

void SavingsAccount::addInterest(){
    deposit(getBalance()*interest);
}
