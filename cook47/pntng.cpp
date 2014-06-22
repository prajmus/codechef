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

lli N, M, H, T, C;
vector<pair<lli, lli>> data;
lli sum;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> H;
    for (int h=0;h<H;h++)
    {
        cin >> T >> C;
        data.push_back(make_pair(T, C));
        sum += T;
    }
    if (sum < N*M)
        cout << "Impossible\n";
    else
    {
        sort(data.begin(), data.end(), [](const pair<lli, lli> &a, const pair<lli,lli> &b) -> bool
                {
                    return a.second < b.second;
                });
        lli result = 0;
        sum = N*M;
        int i=0;
        while (sum != 0)
        {
            if (sum >= data[i].first)
            {
                result += data[i].first * data[i].second;
                sum -= data[i].first;
            }
            else
            {
                result += sum * data[i].second;
                sum = 0;
            }
            i++;
        }
        cout << result << '\n';
    }
    return 0;
}
