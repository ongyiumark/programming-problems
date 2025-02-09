#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int>> iii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k; cin >> n >> k;
  int r, s, p; cin >> r >> s >> p;
  string t; cin >> t;
  string res = "";
  map<char, char> win = {{'r', 'p'}, {'p', 's'}, {'s', 'r'}};
  map<char, int> score = {{'r', r}, {'p', p}, {'s', s}};

  ll total = 0;
  for (char &c : t) {
    res += win[c];
  }

  int sz = res.size();
  for (int i = 0; i < sz; i++) {
    if (i-k >= 0 && res[i-k] == res[i]) {
      res[i] = '#';
      continue;
    }
    total += score[res[i]];
  }

  cout << total << "\n";


  
  return 0;
}
