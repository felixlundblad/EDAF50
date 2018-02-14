#ifndef PRIMENUMBERS_H
#define PRIMENUMBERS_H

#include <string>

class PrimeNumbers{
private:
    void findPrimes(int multiplyer, std::string &primes);
    int findLargestUpTo(int n);
};
#endif