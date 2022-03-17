#ifndef POA_L1_MULTIPLY_H
#define POA_L1_MULTIPLY_H

#include "Operation.h"

/**
 * Multiplication operation.
 *
 * @author Nelson Jeanrenaud
 * @author André Marques Nora
 * @version 1.0
 */
class Multiply : public Operation{
public:

   /**
    * Multiply the two unsigned integers
    * 
    * @param a The first number to multiply.
    * @param b The number of times to multiply a by b.
    * @return The result of the multiplication.
    */
   int calculate(unsigned a, unsigned b) const override;
};


#endif //POA_L1_MULTIPLY_H
