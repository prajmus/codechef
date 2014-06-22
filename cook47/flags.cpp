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
int T, N;
lli result;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--)
    {
        cin >> N;
        if (N == 1)
            cout << 0 << '\n';
        else if (N == 2)
            cout << 4 << '\n';
        else
        {
            result = 0;
            result += (lli)2*N*(N-1)*(N-1);
            result += (lli)3*N*(N-1)*(N-2);
            if (N >= 4) {
                result += (lli)2*N*(N-1)*(N-2)*(N-3);
            }
            cout << result << '\n';
        }
    }

    return 0;
}
