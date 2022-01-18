/*
  We can greedily assign all 1's at first and check if it satisfies the constraints.
  Then, greedily try to change an element to -1 from left to right.

  We only need to keep track of the contraint with the lowest difference 
    between C[i] and the actual range sum from A[i] to B[i].
  We can do this with a priority queue. We'll implement lazy deletion with a set.
*/
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

const int N = 1e5+5;
int n, k;

int prefill[N];

piii C[N];
vector<pii> constraints[N];
int curr[N];

int ans[N];
int prefix[N];

int range_sum(int a, int b){
  if (a == 0) return prefix[b];
  return prefix[b] - prefix[a-1];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> prefill[i];
  for (int i = 0; i < k; i++) {
    int a, b, c; cin >> a >> b >> c;
    a--; b--;
    constraints[a].push_back({1,i});
    constraints[b+1].push_back({-1,i});
    C[i] = {c, {a,b}};
  }
  
  for (int i = 0; i < n; i++) {
    if (prefill[i] != 0) ans[i] = prefill[i];
    else ans[i] = 1;
  }

  prefix[0] = ans[0];
  for (int i = 1; i < n; i++) prefix[i] = prefix[i-1] + ans[i];
  for (int i = 0; i < k; i++){
    int c = C[i].first;
    int a = C[i].second.first;
    int b = C[i].second.second;
    curr[i] = range_sum(a,b);
    if (curr[i] < c) {
      cout << "Impossible" << endl;
      return 0;
    }
  }

  priority_queue<pii, vector<pii>, greater<pii>> pq;
  set<int> track;
  for (int i = 0; i < n; i++){
    // add constraints to priority queue
    for (pii p : constraints[i]) {
      int idx = p.second;
      if (p.first == 1){
        pq.push({curr[idx]-C[idx].first, idx});
        track.insert(idx);
      }
      if (p.first == -1){
        track.erase(track.find(idx));
      }
    }

    if (prefill[i] != 0) continue;

    // delete trash from queue
    while(!pq.empty()){
      pii tmp = pq.top();
      int idx = tmp.second;
      if (track.find(idx) == track.end()){
        pq.pop();
        continue;
      }
      if (curr[idx]-C[idx].first != tmp.first) {
        pq.pop();
        continue;
      }
      break;
    }

    // check constraints
    bool change = true;
    if (!pq.empty()){
      pii tmp = pq.top();
      if (tmp.first < 2) {
        change = false;
      }
    }

    // update constraints
    vector<int> to_remove;
    if (change){
      ans[i] = -1;
      for (int idx : track){
        curr[idx] -= 2;
        pq.push({curr[idx]-C[idx].first, idx});
      }
    }
  }

  for (int i = 0; i < n; i++){
    cout << ans[i];
    if (i == n-1) cout << endl;
    else cout << " ";
  }
  
  return 0;
}
