#include <iostream>
#include <iomanip>
#include <set>

using namespace std;
typedef long double ld;

int main(int argc, char *argv[])
{

  int n;
  cin >> n;
  set<int> s;

  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    s.insert(x);
  }

  cout << (s.size() == n ? "Yes" : "No");
}