#ifndef POA_L1_SUB_H
#define POA_L1_SUB_H

#include "Operation.h"

/**
 * Substraction operation.
 *
 * @author Nelson Jeanrenaud
 * @author André Marques Nora
 * @version 1.0
 */
class Sub : public Operation{
public:

   /**
    * "Subtract b from a and return the result."
    * 
    * @param a The first number to be subtracted.
    * @param b The number of times to run the test.
    * @return The result of the substraction
    */
   int calculate(unsigned a, unsigned b) const override;
};


#endif //POA_L1_SUB_H
