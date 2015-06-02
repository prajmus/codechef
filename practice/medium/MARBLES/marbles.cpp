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

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, N, K;

    cin >> T;
    while (T--)
    {
        cin >> N >> K;
        lli n = K;
        lli r = N - K;

        n = n+r-1;

        if (r > n/2)
                r = n-r;

        lli result = 1;
        for (lli i = 0; i < r; ++i)
        {
            result *= n;
            result /= (i+1);
            n--;
        }
        cout << result << '\n';
    }
    return 0;
}
