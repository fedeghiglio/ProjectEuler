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
