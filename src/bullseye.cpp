#include <iostream>

using namespace std;

long double r;
long double t;

long long getMaximumNumberOfBlackRings() {
    long long i = 0;
    long long j = t;
    long long best = 0;

    while (i <= j) {
        long double m = (i + j) / 2;
        long double p = m * m * 2 + (2 * r - 1) * m;
        if (p > t) {
            j = m - 1;
        } else {
            i = m + 1;
            best = m;
        }
    }

    return best;
}

int main() {
    int T;

    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> r >> t;
        cout << "Case #" << i << ": "
             << getMaximumNumberOfBlackRings() << endl;
    }

    return 0;
}
