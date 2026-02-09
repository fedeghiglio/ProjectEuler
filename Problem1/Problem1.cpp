#include <iostream>
using namespace std;

long long sumMultiples(int x, int limit) {
    int n = (limit - 1) / x; // number of multiples below limit
    return (long long)x * n * (n + 1) / 2;
}

int main() {
    int limit = 1000;
    long long sum = sumMultiples(3, limit) + sumMultiples(5, limit) - sumMultiples(15, limit);
    cout << "Result: " << sum << endl;
    return 0;
}
