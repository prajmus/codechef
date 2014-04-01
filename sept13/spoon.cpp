#include <iostream>
#include <cmath>

#define DEBUG(x) do { cout << "[D ]" << #x << ' ' << x << '\n'; } while(0)

using namespace std;

unsigned long long int limits[64];

void gen_limits()
{
  unsigned long long int C[32];
  C[0] = 1;
  for(int i=0;i<64;i++) {
    for(int j=0;j<=i/2;j++)
      C[j+1]=(C[j] * (i-j)) / (j+1);
    limits[i] = C[i/2];
  }
}

int main () 
{
  ios_base::sync_with_stdio(0);
  int T;
  unsigned long long int N;
  gen_limits();
  limits[63] = 916312070471295267ll;
  cin >> T;
  while(T--) {
    cin >> N;
    int i=0;
    for(i=1;i<64;i++) {
      //DEBUG(limits[i]);
      if (limits[i]>=N)
        break;
    }
    cout << i << '\n';
  }
  return 0;
}
