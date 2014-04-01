#include <iostream>

using namespace std;

int factorial[200];

void fact(int n)
{
  int sum, tmp;
  int j;
  for (int i=0;i<200;++i) {
    factorial[i] = 0;
  }
  factorial[0] = 1;
  int length = 1;
  for (int i=2;i<=n;++i) {
    j = tmp = 0;
    while (j<length) {
      sum = tmp+factorial[j]*i;
      factorial[j] = sum %10;
      j++;
      tmp = sum/10;
    }
    while (tmp >0) {
      factorial[j++]=tmp%10;
      tmp/=10;
      length++;
    }
  }
  for (int i=length-1;i>=0;--i) {
    cout << factorial[i];
  }
  cout << '\n';
}

int main()
{
  ios_base::sync_with_stdio(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    fact(n);
  }
  return 0;
}
