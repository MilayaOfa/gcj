#include <algorithm>
#include <iostream>

using namespace std;

#define MAXN 1000000

int T, A, N;
int m[MAXN];

int getMinOperations() {
    sort(&m[0], &m[N]);
    int a = 0, b = N;
    if (A != 1) {
        for (int i = 0; i < N; i++) {
            while (A <= m[i]) {
                A += A - 1;
                a++;
            }
            A += m[i];
            b = min(b, a + N - (i + 1));
        }
    }
    return b;
}

int main() {
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> A >> N;
        for (int j = 0; j < N; j++) {
            cin >> m[j];
        }
        cout << "Case #" << i << ": " << getMinOperations() << endl;
    }
    return 0;
}
