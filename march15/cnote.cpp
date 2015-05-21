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

int T,X,Y,K,N;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> X >> Y >> K >> N;
        int target = X-Y;
        bool done = false;
        while (N--)
        {
            int p, c;
            cin >> p >> c;
            if (!done && p >= target && c <= K)
            {
                cout << "LuckyChef\n";
                done = true;
            }
        }
        if (!done)
            cout << "UnluckyChef\n";
    }

    return 0;
}
