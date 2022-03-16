#include "Random.h"
#include <ctime>

Random::Random() {
   srand(time(nullptr));
}

Random* Random::getInstance() {
   if(!instance)
      instance = new Random;
   return instance;
}

unsigned Random::getRandom(unsigned n){
   return (unsigned) (1 + rand() / (RAND_MAX + 1.0) * n);
}
