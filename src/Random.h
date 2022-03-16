#ifndef POA_L1_RANDOM_H
#define POA_L1_RANDOM_H

#include <cstdlib>

class Random {

   Random();

public:

    /**
     * If there is no instance of Random, create one
     *
     * @return The Random class is a singleton.  The getInstance() method returns the single instance of
     * the class.
     */
   static Random* getInstance();
    /**
      * Generate a random number between 1 and n
      *
      * @param n The upper bound of the number generated.
      * @return A random number between 1 and n.
      */
   unsigned int getRandom(unsigned n) ;
};


#endif //POA_L1_RANDOM_H
