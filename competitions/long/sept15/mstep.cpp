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
unordered_map<int, pair<int, int> > m;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> N;
        int a;
        for (int i=0;i<N;i++) {
            for (int j=0;j<N;j++) {
                cin >> a;
                m[a] = make_pair(i, j);
            }
        }
        int answer = 0;
        for (int i = 1; i < N*N; i++) {
            answer += abs(m[i].first-m[i+1].first) + abs(m[i].second - m[i+1].second);
        }
        cout << answer << '\n';
    }

    return 0;
}
