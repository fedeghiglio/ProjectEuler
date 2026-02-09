#include <iostream>

using namespace std;

int main() {

    long long k = 526000 / 2;  // number of odd squares

    long long sum = k * (2*k - 1) * (2*k + 1) / 3;

    cout << '\n' << "Result: " << sum << endl;

    return 0;
}
