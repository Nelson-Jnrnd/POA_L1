//
// Created by André on 10.03.2022.
//

#ifndef POA_L1_ADD_H
#define POA_L1_ADD_H


#include "Operation.h"

/**
 * Add operation.
 *
 * @author Nelson Jeanrenaud
 * @author André Marques Nora
 * @version 1.0
 */
class Add : public Operation{
public:


   /**
    * Add two numbers together
    * 
    * @param a The first number to add.
    * @param b The second operand.
    * @return The result of the addition.
    */
   int calculate(unsigned a, unsigned b) const override;
};


#endif //POA_L1_ADD_H
