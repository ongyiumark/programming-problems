#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  set<int> myset;
  int color[3];
  for (int i = 0; i < 3; i++){
    cin >> color[i];
    myset.insert(color[i]);
  }

  cout << myset.size() << endl;
  return 0;
}
