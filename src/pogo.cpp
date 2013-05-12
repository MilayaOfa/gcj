#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#define MAX 1000000

int T, X, Y;

string getDirections() {
    int r = 0;
    long long s = 0;
    long long m = abs(X) + abs(Y);

    while (s < m || s % 2 != m % 2) {
        r++;
        s += r;
    }

    string res = "";

    for (int i = r; i >= 1; i--) {
        if (abs(X) > abs(Y)) {
            if (X > 0) {
                res += 'E';
                X -= i;
            } else {
                res += 'W';
                X += i;
            }
        } else {
            if (Y > 0) {
                res += 'N';
                Y -= i;
            } else {
                res += 'S';
                Y += i;
            }
        }
    }

    reverse(res.begin(), res.end());
    return res;
}

int main() {
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> X >> Y;
        cout << "Case #" << i << ": " << getDirections() << endl;
    }
    return 0;
}
