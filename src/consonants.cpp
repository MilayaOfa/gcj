#include <iostream>
#include <string>

using namespace std;

#define MAX 1000000

int T, N;
string s;
long long cc[MAX];
long long ss[MAX];

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

long long getNValue() {
    int S = s.size();

    int c = 0;
    cc[0] = 0;
    ss[0] = 0;
    for (int i = 1; i <= S; i++) {
        if (isVowel(s[i - 1]))
            c = 0;
        else
            c++;

        if (c >= N)
            ss[i] = (i - N + 1);
        else
            ss[i] = ss[i - 1];

        cc[i] = cc[i - 1] + ss[i];
    }

    return cc[S];
}

int main() {
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> s >> N;
        cout << "Case #" << i << ": " << getNValue() << endl;
    }
}
