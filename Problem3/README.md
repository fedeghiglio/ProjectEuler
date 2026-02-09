# Largest Prime Factor

A **prime factor** of a number \(n\) is a prime number that divides \(n\) exactly.  
For example, the prime factors of 13195 are 5, 7, 13, and 29, and the largest prime factor is 29.

---

## Problem Statement

> What is the largest prime factor of the number 600,851,475,143?

---

## Mathematical Solution

Let \(n = 600{,}851{,}475{,}143\).  
We want the largest prime \(p\) such that \(p \mid n\).

### Step 1: Prime factorization

A number can be expressed as the product of its prime factors:

$$
n = p_1^{a_1} \cdot p_2^{a_2} \cdot \dots \cdot p_k^{a_k}
$$

where \(p_i\) are prime numbers. The largest \(p_i\) is what we are looking for.

---

### Step 2: Algorithm

1. Start with the smallest prime \(i = 2\).  
2. While \(n\) is divisible by \(i\), divide \(n\) by \(i\) and store \(i\) as a prime factor.  
3. Increment \(i\) and repeat until \(n = 1\).  
4. The last prime factor obtained is the largest prime factor.  

#### Observation:

- After removing all factors of 2, only **odd numbers** need to be checked.  
- Only check \(i\) up to \(\sqrt{n}\), because any factor larger than \(\sqrt{n}\) must be prime if \(n > 1\) after the loop.

---

## Efficient C++ Implementation

```cpp
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

    // If n is still > 2, it is prime
    if (n > 2) largestPrime = n;

    cout << "Largest prime factor: " << largestPrime << endl;
    return 0;
}
