#include <iostream>

#define DEBUG(x) do { cout << "D " << #x << ' ' << x << endl;} while(0)

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  char c;
  int t;
  cin >> t;
  cin.get();
  while (t--) {
    cin.clear();
    c = cin.get();
    int result = 0;
    while (c>40 && c<91) {
      //DEBUG(c);
      if (c == 'A' || c == 'Q' || c == 'D' || c == 'R' || c == 'O' || c == 'P')
        ++result;
      else if(c == 'B')
        result += 2;
      c = cin.get();
    }
    cout << result << '\n';
  }
  return 0;
}
