#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map> // hash map
#include <unordered_set>
#include <utility>
#include <vector>

#define DEBUG(x) do { cout << #x << " = " << x << '\n';}while(0)

#define lli long long int

using namespace std;
int n,k,p,T;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> k >> p;
        unordered_set<int> chefs;
        for (int i=0;i<k;++i) {
            int a,b;
            cin >> a >> b;
            chefs.insert(a);
        }
        bool result = true;
        for (int i=0;i<p;++i) {
            int a,b;
            cin >> a >> b;
            if (chefs.count(a) == 0)
                result = false;
        }
        cout << (result == true ? "Yes\n" : "No\n");
    }
    return 0;
}
