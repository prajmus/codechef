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

int T, n, i, s;
int id, sum;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--)
    {
        cin >> n;
        id = 0;
        sum = 0;
        while (n--)
        {
            cin >> i >> s;
            id += i;
            sum += s;
        }
        cout << id-sum << '\n';
    }
    return 0;
}
