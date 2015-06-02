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
    int N, K, n;
    string in;
    cin >> N >> K;
    vector<bool> tweets(N, false);
    int counter = 0;
    for (int i = 0; i < K; ++i)
    {
        cin >> in;
        if (in == "CLICK")
        {
            cin >> n;
            --n;
            if (tweets[n] == false)
                ++counter;
            else
                --counter;
            tweets[n] = !tweets[n];
        }
        else
        {
            std::fill(tweets.begin(), tweets.end(), false);
            counter = 0;
        }
        cout << counter << '\n';
    }
    return 0;
}
