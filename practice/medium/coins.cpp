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

int N;
unordered_map<int, unsigned> arr;

unsigned calculate(int n)
{
    if (n == 0)
        return 0;
    if (arr.count(n) > 0)
        return arr[n];

    arr[n] = max(static_cast<unsigned>(n), calculate(n/2)+calculate(n/3)+calculate(n/4));

    return arr[n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> N)
    {
        cout << calculate(N) << '\n';
    }

    return 0;
}
