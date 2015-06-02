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

int n,m,a,x;
int counter[100001][10];
int seq[100001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> n >> m;
    cin >> s;
    for (int i=0;i<n;++i) {
        if (i >= 1)
            for (int j=0;j<10;++j)
                counter[i][j] = counter[i-1][j];
        a = s[i] - '0';
        ++counter[i][a];
        seq[i] = a;
    }
    for (int i=0;i<m;++i) {
        cin >> x;
        int t = 0;
        lli res = 0;
        int tmp = seq[x-1];
        while (t < tmp) {
            res += (lli)counter[x-1][t] * (lli)(tmp-t);
            ++t;
        }
        ++t;
        while (t <= 9) {
            res += (lli)counter[x-1][t] * (lli)(t-tmp);
            ++t;
        }
        cout << res << '\n';
    }
    return 0;
}
