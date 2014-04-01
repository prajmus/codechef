#include <cstdio>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int T, n, m, p, t;
    vector<multiset<int, std::greater<int> > > data;
    vector<int> path;
    scanf("%d", &T);
    while (T--) {
        data.clear();
        path.clear();
        scanf("%d %d", &n, &m);
        for (int i = 0;i<m;++i) {
            scanf("%d", &p);
            path.push_back(p);
        }
        data.resize(n);
        for (int i=0;i<n;++i) {
            scanf("%d", &p);
            for (int j=0;j<p;++j) {
                scanf("%d", &t);
                data[i].insert(t);
            }
        }
        long long int sum = 0;
        for (int i=0;i<path.size();++i) {
            if (data[path[i]].size() != 0) {
                sum += *data[path[i]].begin();
                data[path[i]].erase(data[path[i]].begin());
            }
            else
                sum += 0;
        }
        printf("%lld\n", sum);
    }
}
