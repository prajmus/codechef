#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(x) do { cout << "[DEBUG] " << #x << ' '  << x << '\n'; } while(0)

using namespace std;

int Test, Row, Col;
long long int result;
char c;
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19,
                23, 29, 31, 37, 41, 43, 47, 53,
                59, 61, 67, 71, 73, 79, 83, 89,
                97, 101, 103, 107, 109, 113, 127, 131,
                137, 139, 149, 151, 157, 163, 167, 173,
                179, 181, 191, 193, 197, 199, 211, 223,
                227, 229, 233, 239, 241, 251, 257, 263,
                269, 271, 277, 281, 283, 293, 307, 311,
                313, 317, 331, 337, 347, 349, 353, 359,
                367, 373, 379, 383, 389, 397, 401, 409,
                419, 421, 431, 433, 439, 443, 449, 457,
                461, 463, 467, 479, 487, 491, 499};
int lower[501]; // = {0, 0, 1, 2, 2, 3, 3, 4, 4, 4, 4, 5, 5, 6, 6, 6, 6, 7, 7, 8,
                //  8, 8, 8, 9, 9, 9, 9, 9, 9, 10, 10, 11, 11, 11, 11, 11, 11, 12}

int main()
{
  ios_base::sync_with_stdio(0); 
  int j=0;
  for(int i=0;i<501;i++) {
    if(i == primes[j])
      j++;
      lower[i] = j;
  }
  cin >> Test;
  while (Test--) {
    cin >> Col >> Row;
    vector<vector<bool> > t(Col);
    result = 0;
    for (int i=0;i<Col;++i) {
      for (int j=0;j<Row;++j) {
        cin >> c;
        if (c == '#') 
          t[i].push_back(true);
        else
          t[i].push_back(false);
      }
    }
    int L,R,T,B;
    for(int i=2;i<Col-2;++i) { 
      for(int j=2;j<Row-2;++j) {
        if(t[i][j] == false) {
          int tmp = i;
          while(tmp>=0 && !t[tmp][j])
            --tmp;
          T = i-tmp-1;
          tmp = i;
          while(tmp<Col && !t[tmp][j])
            ++tmp;
          B = tmp-i-1;
          tmp = j;
          while(tmp>=0 && !t[i][tmp])
            --tmp;
          L = j-tmp-1;
          tmp = j;
          while(tmp<Row && !t[i][tmp])
            ++tmp;
          R = tmp-j-1;
          int min = std::min( {R, L, T, B} );
          if(min>=2)
            result+=lower[min];
        }
      }
    }
    cout << result << '\n';
  }
  return 0;
}
