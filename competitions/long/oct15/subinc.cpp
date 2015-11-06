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

    int T, N, p, a;
    cin >> T;
    while (T--) {
        cin >> N;
        cin >> p;
        N--;
        long long int nondec = 1;
        long long int subinc = 0;
        while (N--) {
            cin >> a;
            if (a >= p) {
                nondec++;
                p = a;
            }
            else {
                subinc += nondec * (nondec+1) / 2;
                nondec = 1;
                p = a;
            }
        }
        subinc += nondec * (nondec+1) / 2;
        cout << subinc << '\n';
    }

    return 0;
}
