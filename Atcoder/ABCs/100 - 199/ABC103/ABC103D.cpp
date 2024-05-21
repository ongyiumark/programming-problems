/*
  We can solve this by moving from west to east.
  Let a_i be the opening dispute and b_i be the closing dispute.
  We remove a bridge every time we encounter a closing dispute that has not been settled yet.
  By removing this bridge, we settle all the opened disputes.

  We can implement this be maintaining a queue of opened disputes and a boolean array of settled disputes.
  Everytime we encounter an unsettled closing dispute, we empty the queue into the array.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<pair<int,int>,int> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5;
vector<piii> dispute; // {place,type}, id
bool settled[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    dispute.push_back({{a,1}, i});
    dispute.push_back({{b,-1}, i});
  }
  sort(dispute.begin(), dispute.end());
  memset(settled, 0, sizeof settled);
  int cnt = 0;
  
  queue<int> q;
  for (int i = 0; i < 2*m; i++){
    int type = dispute[i].first.second;
    int id = dispute[i].second;
    if (type == 1) q.push(id);
    else {
      if (settled[id]) continue;
      while(!q.empty()){
        settled[q.front()] = 1;
        q.pop();
      }
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}
