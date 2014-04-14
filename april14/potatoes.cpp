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

bool prime[3010];

void sieve()
{
    fill_n(prime, 3010, true);
    prime[0] = prime[1] = false;
    for(int i=2;i<=3000;++i) {
        if (prime[i] == true) {
            for (int j=i*i;j<=3000;j+=i) {
                prime[j] = false;
            }
        }
    }
}

int T, x, y;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    sieve();
    while (T--)
    {
        cin >> x >> y;
        int c = 1;
        while (prime[x+y+c] != true)
            c++;
        cout << c << '\n';
    }
    return 0;
}
