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

  int n; cin >> n;
  string s; cin >> s;
  int cntL = 0;
  for (char ch : s) cntL++;

  int i = 0;
  int j = 0;
  vector<pair<char,int>> tmp;
  while (i < n) {
    while(s[i] == s[j] && j < n) j++;
    tmp.push_back({s[i], j-i});
    i = j;
  }

  int l = 1;
  int r = cntL+1;
  for (auto p : tmp) {
    auto [ch, x] = p;
    if (ch == 'L') {

    }
  }

  vector<int> res;
  
  
  for (int v : res) {
    cout << v << endl;
  }
  return 0;
}
