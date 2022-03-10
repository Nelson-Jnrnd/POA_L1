//
// Created by André on 10.03.2022.
//

#ifndef POA_L1_ADD_H
#define POA_L1_ADD_H


#include "Operation.h"

class Add : public Operation{
public:

   int calculate(int a, int b) override;
};


#endif //POA_L1_ADD_H
