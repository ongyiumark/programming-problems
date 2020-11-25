#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m; cin >> n >> m;
  int l; cin >> l;

  bitset<1000> ans;
  for (int i = 0; i < l; i++){
    int x; cin >> x;
    x--;
    ans[x] = 1;
  }

  vector<bitset<1000>> switches(n);

  for (int i = 0; i < n; i++){
    int k; cin >> k;
    for (int j = 0; j < k; j++){
      int x; cin >> x;
      x--;
      switches[i][x] = 1;
    }
  }

  int i = 0;

  for (i = 0; i < 2*n; i++){
    ans ^= switches[i%n];
    if (ans.none())
      break;
  }

  cout << (i == 2*n ? -1 : i+1) << endl;
  
  return 0;
}
