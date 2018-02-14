#include <iostream>

using namespace std;

void findPrimes(int multiplyer, string &primes)
{
    int pos;
    int traverser = 1;
    if (primes.at(multiplyer) == 'P')
    {
        while (traverser * multiplyer < 201)
        {
            pos = multiplyer * ++traverser;
            if (pos < 201)
                primes.replace(pos, 1, "C");
        }
    }
    if (multiplyer > 201)
        return;
    findPrimes(multiplyer + 1, primes);
}

int findLargestUpTo(int n){
    for (int i = 2; i < n; i++){
        if(!(n % i)){
            return findLargestUpTo(n-1);
        }
    }
    return n;
}

int main()
{
    string primes;
    primes.append("CC");
    primes.append(string(201, 'P'));
    findPrimes(2, primes);
    cout << primes.substr(0, 201) << endl;
    cout << "Enter up to what integer you would like to find a prime number: ";
    int x;
    cin >> x;
    cout << "The prime number closest below " << x << " is: " << findLargestUpTo(x) << endl;

}
