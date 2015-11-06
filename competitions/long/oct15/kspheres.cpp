#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map> // hash map
#include <utility>
#include <vector>

#define DEBUG(x) do { cout << #x << " = " << x << '\n';}while(0)

#define lli long long int
const int MOD = 1000000007;

using namespace std;

long long int Ns[1002];
long long int Ms[1002];
long long int coeffs[1003];

void vienn (int m, int c) {
    coeffs[0] = -Ns[1];
    coeffs[1] = 1;
    for (int i = 2; i <= c; i++) {
        coeffs[i] = 1;

        for (int j = i-2; j >= 0; j--) {
            coeffs[j+1] = ((coeffs[j] % MOD) - (((Ns[i] % MOD) * (coeffs[j+1] % MOD)) % MOD)) % MOD;
        }
        coeffs[0] = ((coeffs[0]  % MOD) * ((-Ns[i]) % MOD)) % MOD;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M, C;

    cin >> N >> M >> C;
    for (int i=0; i<N; i++) {
        int c;
        cin >> c;
        Ns[c]++;
    }

    for (int i=0; i<M; i++) {
        int c;
        cin >> c;
        Ms[c]++;
    }

    for (int i=C; i>0; i--) {
        Ns[i] = Ns[i] * Ms[i];
    }

    vienn(2, C);
    for (int i = C-2; i >= 0; i--) {
        cout << abs(coeffs[i]) << ' ';
    }
    cout << '0';

    return 0;
}
