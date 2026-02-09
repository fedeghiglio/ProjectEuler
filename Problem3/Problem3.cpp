#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long n = 600851475143;
    long long largestPrime = 1;

    // Remove factors of 2
    while (n % 2 == 0) {
        largestPrime = 2;
        n /= 2;
    }

    // Check odd factors only
    for (long long i = 3; i*i <= n; i += 2) {
        while (n % i == 0) {
            largestPrime = i;
            n /= i;
        }
    }

    // If n is still > 2, it is a prime
    if (n > 2) largestPrime = n;

    cout << "Largest prime factor: " << largestPrime << endl;
    return 0;
}
