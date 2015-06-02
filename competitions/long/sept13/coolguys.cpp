#include <iostream>

#define DEBUG(x) do { cout << "[DEBUG] " << #x << ' ' << x << '\n'; } while(0)
using namespace std;

long long int GCD(long long int u, long long int v) {
    while ( v != 0) {
        long long int r = u % v;
        u = v;
        v = r;
    }
    return u;
}

long long int GCD2(long long int u, long long int v)
{
  long long int shift;
 
  if (u == 0) return v;
  if (v == 0) return u;
 
  for (shift = 0; ((u | v) & 1) == 0; ++shift) {
         u >>= 1;
         v >>= 1;
  }
 
  while ((u & 1) == 0)
    u >>= 1;
 
  do {
       while ((v & 1) == 0)  
           v >>= 1;
 
       if (u > v) {
         long long int t = v; v = u; u = t;}  
       v = v - u;                       
     } while (v != 0);
 
  return u << shift;
}

int main()
{
  ios_base::sync_with_stdio(0);
  int T;
  long long int N;
  long long int result = 0;
  cin >> T;
  while (T--) {
    cin >> N;
    result = 0;
    for(long long int i=1;i*i<=N;i++) {
      result += N/i;
      if(N/i != i)
        result += i*((N/i) - (N/(i+1)));
    }
    //DEBUG(result);
    long long int gcd = GCD2(result, N*N);
    cout << result/gcd << '/' << N*N/gcd << '\n';
  }
    return 0;
}
