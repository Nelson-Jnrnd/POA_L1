#ifndef POA_L1_OPERATION_H
#define POA_L1_OPERATION_H

/**
 * Operation abstract class.
 * Extended to calculate an operation between two unsigned int.
 *
 * @author Nelson Jeanrenaud
 * @author André Marques Nora
 * @version 1.0
 */
class Operation {
public:

    /**
     * Calculate the operation between two unsigned int.
     * @param a first operand.
     * @param b second operand..
     * @return result of the operation
     */
   virtual int calculate(unsigned a, unsigned b) const = 0;
};


#endif //POA_L1_OPERATION_H
