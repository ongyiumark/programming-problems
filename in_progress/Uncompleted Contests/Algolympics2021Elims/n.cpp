/*
  Use bitsets for set intersection.
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

vector<string> cremates, rooms;
const int N = 1e5;
vector<int> adj[N];
set<int> pos[N];
piii reports[N];
int ans[N];
int n;

bool decide(int i){
  // pos[i].size() >= 2
  bitset<N> bans;
  bans.set();
  for (auto x : pos[i]){
    bitset<N> tmp;
    tmp.set(x, true);
    for (int v : adj[x]){
      tmp.set(v, true);
    }
    bans &= tmp;
    if (bans._Find_first() >= n) return true;
  }
  
  ans[i] = bans._Find_first();
  return false;
}

void solve(){
  unordered_map<string,int> crewmatesid, roomsid;
  int c; cin >> c;
  cremates.resize(c);
  for (int i = 0; i < c; i++){
    cin >> cremates[i];
    crewmatesid[cremates[i]] = i;
  }
  cin >> n;
  rooms.resize(n);
  for (int i = 0; i < n; i++){
    cin >> rooms[i];
    roomsid[rooms[i]] = i;
  }
  int m; cin >> m;
  for (int i = 0; i < n; i++) adj[i].clear();
  for (int i = 0; i < m; i++){
    string U, V; cin >> U >> V;
    int u = roomsid[U];
    int v = roomsid[V];
    adj[u].push_back(v);
    adj[v].push_back(u);
    //cout << u << " " << v << endl;
  }

  //reset ans and pos
  for (int i = 0; i < c; i++) {
    ans[i] = -1;
    pos[i].clear();
  }
  
  int r; cin >> r;
  bool sus = 0;
  for (int i = 0; i < r; i++){
    string A, B, X; cin >> A >> B >> X;
    int a = crewmatesid[A];
    int b = crewmatesid[B];
    int x = roomsid[X];
    //cout << a << " " << b << " " << x << endl;
    reports[i] = {{a,b}, x};

    if (ans[b] == -1) ans[b] = x;
    else if (ans[b] != x) sus = 1;

    pos[a].insert(x);
  }

  for (int i = 0; i < c && !sus; i++){
    if (ans[i] == -1){
      if (pos[i].size() == 0) ans[i] = 0;
      else if (pos[i].size() == 1) ans[i] = *pos[i].begin();
      else sus |= decide(i);
    }
  }

  if (sus) cout << "SUSMARYOSEP!\n";
  else {
    cout << "CONSENSUS!\n";
    for (int i = 0; i < c; i++){
      cout << rooms[ans[i]] << "\n";
    }
  } 
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while(t--){
    solve();
  }
  return 0;
}
