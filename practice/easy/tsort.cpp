#include <iostream>
#include <set>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  multiset<int> set;
  int t, tmp;
  cin >> t;
  while (t--) {
    cin >> tmp;
    set.insert(tmp);
  }
  multiset<int>::iterator it = set.begin();
  for(;it!=set.end();++it)
    cout << *it << '\n';
  return 0;
}
