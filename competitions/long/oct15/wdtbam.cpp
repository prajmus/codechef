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

    int T, N;
    int W[1002];
    string que, ans;

    cin >> T;
    while (T--) {
        cin >> N;
        cin >> que;
        cin >> ans;
        int good = 0;
        for (int i = 0; i <= N; i++) {
            cin >> W[i];
            if (i < N && que[i] == ans[i])
                good++;
        }
        if (good == 0)
            cout << W[0] << '\n';
        else if (good == N)
            cout << W[N] << '\n';
        else {
            int max = 0;
            for (int i = 0; i <= good; i++)
                if (W[i] > max)
                    max = W[i];
            cout << max << '\n';
        }
    }

    return 0;
}
