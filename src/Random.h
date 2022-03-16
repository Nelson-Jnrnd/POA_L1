#ifndef POA_L1_RANDOM_H
#define POA_L1_RANDOM_H

#include <cstdlib>

class Random {

   static Random* instance;

   Random();

public:

   static Random* getInstance();
   unsigned int getRandom(unsigned n) ;
};


#endif //POA_L1_RANDOM_H
