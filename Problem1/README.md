# Sum of Multiples of 3 or 5

We want to find the sum of all numbers below 1000 that are multiples of **3 or 5**.  
For example, the multiples of 3 or 5 below 10 are 3, 5, 6, 9, and their sum is 3 + 5 + 6 + 9 = 23.

---

## Problem Statement

> Find the sum of all the multiples of 3 or 5 below 1000.

---

## Mathematical Solution

Let \(x\) be any number and \(L\) the limit (here 1000). The sum of all multiples of \(x\) below \(L\) is an arithmetic series:

$$
x + 2x + 3x + \dots + nx = x \sum_{i=1}^{n} i = x \cdot \frac{n(n+1)}{2}
$$

where

$$
n = \left\lfloor \frac{L-1}{x} \right\rfloor
$$

---

The multiples of 3 below 1000:

$$
3 + 6 + 9 + \dots + 999
$$

The multiples of 5 below 1000:

$$
5 + 10 + 15 + \dots + 995
$$

Some numbers are multiples of both 3 and 5 (i.e., multiples of 15). To avoid double-counting, we subtract their sum:

$$
15 + 30 + 45 + \dots + 990
$$

---

### Step 1: Sum formulas

Sum of multiples of 3 below 1000:

$$
\text{sum\_3} = 3 \cdot \frac{333 \cdot 334}{2}
$$

Sum of multiples of 5 below 1000:

$$
\text{sum\_5} = 5 \cdot \frac{199 \cdot 200}{2}
$$

Sum of multiples of 15 below 1000:

$$
\text{sum\_15} = 15 \cdot \frac{66 \cdot 67}{2}
$$

---

### Step 2: Total sum

$$
\text{Sum of multiples of 3 or 5 below 1000} = \text{sum\_3} + \text{sum\_5} - \text{sum\_15}
$$

---

## Efficient C++ Implementation

```cpp
#include <iostream>
using namespace std;

// Function to compute sum of multiples of x below limit
long long sumMultiples(int x, int limit) {
    int n = (limit - 1) / x;
    return (long long)x * n * (n + 1) / 2;
}

int main() {
    int limit = 1000;
    long long sum = sumMultiples(3, limit) + sumMultiples(5, limit) - sumMultiples(15, limit);
    cout << "Sum of multiples of 3 or 5 below 1000: " << sum << endl;
    return 0;
}
