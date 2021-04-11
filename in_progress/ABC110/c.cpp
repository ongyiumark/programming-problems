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

string s, t;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> s >> t;
  int n = s.size();
  map<char,char> partner;
  bool valid = 1;
  for (int i = 0; i < n; i++){
    if (s[i] == t[i]) continue;
    if (partner.find(s[i]) != partner.end() && partner[s[i]] != t[i]) {
      valid = 0;
      break;
    }
    if (partner.find(t[i]) != partner.end() && partner[t[i]] != s[i]){
      valid = 0;
      break;
    }

    partner[s[i]] = t[i];
    partner[t[i]] = s[i];
  }

  cout << (valid ? "Yes" : "No") << endl;
  return 0;
}
