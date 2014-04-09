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

#define lli long long int

using namespace std;

bool primes[10010];

void sieve()
{
    for (int i = 2; i < 10010; ++i)
        primes[i] = true;
    primes[0] = primes[1] = false;
    for (int i = 2; i <= 10010; ++i) {
        if (primes[i] == true) {
            for (int j = i*i; j <= 10010; j+=i) {
                primes[j] = false;
            }
        }
    }
}

bool isPrime(int n)
{
    if (n < 10010)
        return primes[n];
    else {
        for (int i = 2; i < 10010 ; ++i) {
            if (primes[i] && n%i == 0)
                return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        if (N==2 || N==17)
            cout << "Mike\n";
        else if (N==1 || N==16 || N==34 || N==289)
            cout << "Tom\n";
        else if (isPrime(N))
            cout << "Tom\n";
        else
            cout << "Mike\n";
    }
    return 0;
}

