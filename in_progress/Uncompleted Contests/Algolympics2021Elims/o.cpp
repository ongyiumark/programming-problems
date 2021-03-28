/*
  Try to remove each reporter smartly.
  Keep track of a the crewmates with problems and when you remove a report, check if that problem is resolved.
  If all problems are resolved, then that reporter is the impostor.
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
vector<pii> report[N];
map<int,int> pos_ans[N];
int ans[N];
int n;

bool check(int i){
  bitset<N> reported_rooms;
  for (auto p : pos[i]){
    reported_rooms.set(p, true);
  }
  bitset<N> adj_rooms;
  adj_rooms.set(ans[i], true);
  for (auto v : adj[ans[i]]){
    adj_rooms.set(v, true);
  }

  return (adj_rooms|reported_rooms) != adj_rooms;
}

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

bool validate(int i){
  if (pos_ans[i].size() == 0){
    if (pos[i].size() == 0) ans[i] = 0;
    else if (pos[i].size() == 1) ans[i] = *pos[i].begin();
    else if (decide(i)) return true;
  }
  else if (pos_ans[i].size() == 1){
    ans[i] = pos_ans[i].begin()->first;
    if (check(i)) return true;
  }
  else return true;
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
  }

  //reset ans and pos
  for (int i = 0; i < c; i++) {
    ans[i] = -1;
    pos[i].clear();
    report[i].clear();
    pos_ans[i].clear();
  }

  int r; cin >> r;
  for (int i = 0; i < r; i++){
    string A, B, X; cin >> A >> B >> X;
    int a = crewmatesid[A];
    int b = crewmatesid[B];
    int x = roomsid[X];
    report[a].push_back({b,x});
    pos_ans[b][x]++;
    pos[a].insert(x);
  }

  bool sus = 0;
  set<int> problems;
  for (int i = 0; i < c; i++){
    if (validate(i)){
      sus = 1;
      problems.insert(i);
    }
  }

  if (!sus){
    cout << "CONSENSUS!\n";
    cout << "NO IMPOSTOR\n";
    for (int i = 0; i < c; i++){
      cout << rooms[ans[i]] << "\n";
    }
    return;
  }

  for (int i = 0; i < c; i++){
    if (report[i].size() == 0) continue;
    // remove reports
    bool inconsistent = 0;
    set<int> solved_problems;
    for (auto p : report[i]){
      int x = p.second;
      int b = p.first;
      pos_ans[b][x]--;
      if (pos_ans[b][x] == 0) pos_ans[b].erase(x);
      bool valb = validate(b);
      if (valb) inconsistent = 1;
      if (problems.find(b) != problems.end() && !valb) solved_problems.insert(b);
    }
    pos[i].clear();
    bool vali = validate(i);
    if (vali) inconsistent = 1;
    if (problems.find(i) != problems.end() && !vali) solved_problems.insert(i);

    if (inconsistent || solved_problems.size() != problems.size()){
      // add back reports
      for (auto p : report[i]){
        int x = p.second;
        int b = p.first;
        pos_ans[b][x]++;
        pos[i].insert(x);
      }
    }
    else{
      for (int j = 0; j < c; j++) validate(j);
      cout << "CONSENSUS!\n";
      cout << cremates[i] << "\n";
      for (int j = 0; j < c; j++){
        cout << rooms[ans[j]] << "\n";
      }
      return;
    }
  }

  cout << "SUSMARYOSEP!\n";
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
