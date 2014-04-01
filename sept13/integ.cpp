#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

#define DEBUG(x) do { cout << "[DEBUG] " << #x << ' '  << x << '\n'; } while(0)

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  vector<long long int> numbers;
  long long int N, x, T;
  cin >> N;
  for (int i=0;i<N;i++) {
    cin >> x;
    numbers.push_back(x);
  }
  cin >> T;
  sort(numbers.begin(), numbers.end(), greater<long long int>());
  long long int added=0;
  long long int cost=0;
  int NC = N;
  for (int i=0;i<NC;i++) {
    if (numbers[i] >= 0) {
//      DEBUG(*(numbers.begin()));
      --N;
    }
    else {
      if (T<=N) {
        int tmp = 0 - numbers[i]-added;
 //       DEBUG(tmp);
        cost += tmp*T;
        added +=tmp;
      }
      else {
        cost += 0 - numbers[i]-added;
  //      DEBUG(cost);
      }
      --N;
    }
  }
  cout << cost <<'\n';
  return 0;
}
