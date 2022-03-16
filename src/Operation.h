#ifndef POA_L1_OPERATION_H
#define POA_L1_OPERATION_H

class Operation {

public:
   virtual int calculate(unsigned a, unsigned b) const = 0;
};


#endif //POA_L1_OPERATION_H
