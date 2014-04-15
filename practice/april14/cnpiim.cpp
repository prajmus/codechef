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
#define MAX 1250*1250+1

using namespace std;
int T, N;
int multi[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int i=1;i<MAX;++i) {
        for (int j=1;j<MAX;++j) {
            if (i*j < MAX)
                ++multi[i*j];
            else
                break;
        }
    }
    for (int i=1;i<MAX;++i) {
        multi[i] += multi[i-1];
    }
    while (T--) {
        cin >> N;
        lli result = 0;
        for (int i=1;i<N;i++) {
            result +=  multi[i*(N-i) - 1];
        }
        cout << result << '\n';
    }
    return 0;
}
