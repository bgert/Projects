//
//  SavingsAccount.hpp
//  Cpluspluslab
//
//  Created by Benjamin Gertz on 4/3/18.
//  Copyright © 2018 Benjamin Gertz. All rights reserved.
//

#ifndef SavingsAccount_hpp
#define SavingsAccount_hpp

#ifndef SAVINGSACCOUNT_H_
#define SAVINGSACCOUNT_H_

#include "BankAccount.h"

class SavingsAccount : public BankAccount{
    
public:
    SavingsAccount(char *n, double b, double i);
    
    void addInterest();
private:
    double interest;
};


#endif /* SavingsAccount_hpp */
