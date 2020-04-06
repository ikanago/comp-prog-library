#include "../../math/factorize.hpp"
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    auto factorized = factorize<int>(n);

    cout << n << ":";
    for (const auto& p : factorized) {
        for (size_t i = 0; i < p.second; i++) {
            cout << p.first << " ";
        }
    }
}