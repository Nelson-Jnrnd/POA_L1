//
// Created by André on 10.03.2022.
//

#ifndef POA_L1_MULTIPLY_H
#define POA_L1_MULTIPLY_H


#include "Operation.h"

class Multiply : public Operation{
public:

   int calculate(int a, int b) const override;
};


#endif //POA_L1_MULTIPLY_H
