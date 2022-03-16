#include "Random.h"
#include <ctime>

/**
 * The constructor initializes the random number generator with the current time
 */
Random::Random() {
    srand(time(nullptr));
}

Random* Random::getInstance() {
    static Random* instance;
    if(!instance)
        instance = new Random;
    return instance;
}

unsigned Random::getRandom(unsigned n) {
    return (unsigned) (1 + rand() / (RAND_MAX + 1.0) * n);
}
