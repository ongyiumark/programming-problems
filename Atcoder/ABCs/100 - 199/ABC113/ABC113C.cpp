/*
  Implementation problem. Store the city details in a pair and sort.
  Keep track of the original indices.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<pair<int,int>, int> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

string fill6(int x){
  string tmp = to_string(x);
  string res;
  res.append(6-(int)tmp.size(),'0');
  res += tmp;
  return res;
}

const int N = 1e5+5;
vector<pii> city[N];
string ans[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++){
    int p, y; cin >> p >> y;
    city[p].push_back({y,i});
  }

  for (int i = 0; i <= n; i++){
    sort(city[i].begin(), city[i].end());
    string pref = fill6(i);
    for (int j = 0; j < city[i].size(); j++){
      int idx = city[i][j].second;
      string id = pref + fill6(j+1);
      ans[idx] = id;
    }
  }

  for (int i = 0; i < m; i++){
    cout << ans[i] << endl;
  }
  return 0;
}
