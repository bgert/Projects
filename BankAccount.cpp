//
//  BankAccount.cpp
//  Cpluspluslab
//
//  Created by Benjamin Gertz on 4/3/18.
//  Copyright © 2018 Benjamin Gertz. All rights reserved.
//

#include "BankAccount.hpp"
//look into why he uses .h and why this wants .hpp. keep in mind that this file is correct in using .cpp because he also made this a cpp
#include <cstring>

BankAccount::BankAccount(){
    
    strcpy(this->name, "");
    this->balance = 0.0;
}

BankAccount::BankAccount(char *n, double b){
    strcpy(this->name,n);
    this-> balance = b;
}

char* BankAccount::getName(){
    return this-> name;
}

double BankAccount::getBalance(){
    return this-> balance;
}

void BankAccount::deposit(double amount){
    this-> balance += amount;
}

bool BankAccount::withdraw(double amount){
    if(this->balance> amount){
        this->balance = this-> balance - amount;
        return 1;
    }
    return 0;
}

bool BankAccount::transfer(BankAccount *account, double amount){
    if(withdraw(amount)){
        account-> deposit(amount);
        return 1;
    }
    return 0;
}

