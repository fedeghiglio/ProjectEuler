# Sum of Odd Squares

A **perfect square** (or square number) is a number that is the square of a positive integer. For example: `1, 4, 9, 16, 25, ...` are square numbers. Odd squares are those squares which are odd numbers themselves: `1, 9, 25, ...`. The first 5 square numbers are `1, 4, 9, 16, 25` and the odd squares among them are `1, 9, 25`, with a sum of `1 + 9 + 25 = 35`.

---

## Problem Statement

> Among the first 526,000 square numbers, what is the sum of all the **odd squares**?

---

## Mathematical Solution

Every odd number can be written as `2i - 1` for `i = 1, 2, 3, ..., k`. 
The sum of the squares of the first `k` odd numbers is `sum_{i=1}^{k} (2i - 1)^2`. Expanding the square gives `(2i - 1)^2 = 4i^2 - 4i + 1`, so the sum becomes

 `sum_{i=1}^{k} (2i - 1)^2 = 4*sum_{i=1}^{k} i^2 - 4*sum_{i=1}^{k} i + sum_{i=1}^{k} 1`.
 
Using the formulas
 `sum_{i=1}^{k} i = k*(k+1)/2`, 
 `sum_{i=1}^{k} i^2 = k*(k+1)*(2k+1)/6`, 
 and `sum_{i=1}^{k} 1 = k`, 

 we get `sum_{i=1}^{k} (2i - 1)^2 = 4*(k*(k+1)*(2k+1)/6) - 4*(k*(k+1)/2) + k`. 
 Simplifying this yields the final formula 
 `sum_{i=1}^{k} (2i - 1)^2 = k*(2k-1)*(2k+1)/3`,
  which allows computing the sum in **O(1)** time.

For the first 526,000 square numbers, the number of odd squares is `k = 526000 / 2 = 263000`, and the sum of odd squares is `Sum = k * (2*k - 1) * (2*k + 1) / 3`.

---

## Efficient C++ Implementation

```cpp
#include <iostream>
using namespace std;

int main() {
    long long n = 526000;
    long long k = n / 2; // number of odd squares
    long long sum = k * (2*k - 1) * (2*k + 1) / 3;
    cout << "Sum of odd squares: " << sum << endl;
    return 0;
}
