#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

string to_bin(int x) {
  string res = "";
  while (x > 0) {
    if (x&1) res.append(1,'*');
    else res.append(1, '.');
    x /= 2;
  } 

  while(res.size() < 4) res.append(1,'.');
  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int clock; cin >> clock;
  string htens = to_bin(clock/1000);
  string hones = to_bin(clock/100%10);
  string mtens = to_bin(clock/10%10);
  string mones = to_bin(clock%10);

  vector<string> ans;
  for (int i = 3; i >= 0; i--) {
    string tmp = "";
    tmp.append(1, htens[i]); tmp.append(1, ' '); tmp.append(1,hones[i]);
    tmp.append(1, ' '); tmp.append(1, ' '); tmp.append(1, ' ');
    tmp.append(1, mtens[i]); tmp.append(1, ' '); tmp.append(1,mones[i]);
    ans.push_back(tmp);
  }

  for (int i = 0; i < 4; i++) {
    cout << ans[i] << endl;
  }
  
  return 0;
}
