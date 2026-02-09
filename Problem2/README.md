# Sum of Even Fibonacci Numbers

The Fibonacci sequence is defined as:

$$
F_1 = 1, \quad F_2 = 2, \quad F_n = F_{n-1} + F_{n-2} \text{ for } n \ge 3
$$

The first few terms are: 1, 2, 3, 5, 8, 13, 21, 34, ... Among these, the even-valued terms are 2, 8, 34, ... and their sum up to 34 is 2 + 8 + 34 = 44.

---

## Problem Statement

> By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.

---

## Mathematical Solution

Let \(E_k\) denote the \(k\)-th even Fibonacci number.  
Observe that **every third Fibonacci number is even**:

# Sum of Even Fibonacci Numbers

The Fibonacci sequence is defined as:

$$
F_1 = 1, \quad F_2 = 2, \quad F_n = F_{n-1} + F_{n-2} \text{ for } n \ge 3
$$

The first few terms are: 1, 2, 3, 5, 8, 13, 21, 34, ... Among these, the even-valued terms are 2, 8, 34, ... and their sum up to 34 is 2 + 8 + 34 = 44.

---

## Problem Statement

> By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.

---

## Mathematical Solution

Let \(E_k\) denote the \(k\)-th even Fibonacci number.  
Observe that **every third Fibonacci number is even**:


Hence, the even Fibonacci numbers form a subsequence of the original sequence.

---

### Step 1: Recurrence for even Fibonacci numbers

It can be shown analytically (using Binet's formula or the standard Fibonacci recurrence) that the even Fibonacci numbers satisfy the following recurrence:

$$
E_1 = 2, \quad E_2 = 8, \quad E_k = 4 E_{k-1} + E_{k-2} \text{ for } k \ge 3
$$

- Here, \(E_1 = F_3 = 2\) and \(E_2 = F_6 = 8\).  
- Using this formula, each even Fibonacci number can be generated directly from the previous two even numbers.

---

### Step 2: Sum the even Fibonacci numbers

We repeatedly apply the recurrence to generate all even Fibonacci numbers \(E_k \le 4{,}000{,}000\) and sum them:

$$
\text{Sum} = \sum_{k=1}^{N} E_k \quad \text{where } E_k \le 4{,}000{,}000
$$

---

## Efficient C++ Implementation

```cpp
#include <iostream>
using namespace std;

int main() {
    long long sum = 0;
    long long a = 2; // E1
    long long b = 8; // E2

    sum = a + b;

    while (true) {
        long long c = 4 * b + a; // next even Fibonacci number
        if (c > 4000000) break;
        sum += c;
        a = b;
        b = c;
    }

    cout << "Sum of even Fibonacci numbers <= 4,000,000: " << sum << endl;
    return 0;
}
