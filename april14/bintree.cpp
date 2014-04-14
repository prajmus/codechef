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

int N, a, b, result;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    while (N--) {
        cin >> a >> b;
        result = 0;
        while (a != b) {
            if (a > b)
                a/=2;
            else if (b > a)
                b/=2;
            ++result;
        }
        cout << result << '\n';
    }
    return 0;
}
