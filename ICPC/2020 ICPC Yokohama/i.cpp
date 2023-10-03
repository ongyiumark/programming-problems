#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9+7;

vector<pair<char,int>> simple;
vector<bool> in, out;
vector<int> cnt_missing;
int n;

ll solve(int i, int missing_out) {

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  vector<bool>(n, 0).swap(in);
  vector<bool>(n, 0).swap(out);
  vector<pair<char,int>>(2*n).swap(ar);
  vector<int>(2*n+1).swap(cnt_missing);
  for (int i = 0; i < 2*n; i++) {
    char ch; cin >> ch;
    int id; cin >> id;
    ar[i] = {ch, id};

    if (id > 0) {
      if (ch == 'I') in[id-1] = true;
      else out[id-1] = true; 
    }
  }

  for (int i = 0; i < 2*n; i++) {
    auto [ch, id] = ar[i];
    if (ch == 'I') {
      if (id == 0 || (id > 0 && !out[id])) {
        cnt_missing[i+1] = 1;
      }
    }
    else {
      
    }
    if (id == 0 && !in[id] && !out[id]) {
      cnt_missing[i+1] = 1;
    }
    else if (id > 0 && !out[id])
    
    cnt_missing[i+1] += cnt_missing[i] 
  }
  cout << solve(0, 0) << "\n";


  
  return 0;
}