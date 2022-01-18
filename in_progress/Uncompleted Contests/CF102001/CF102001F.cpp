/*
  Count how many you can solve and greedily pop the balloons at times
    where the problem solving time is maximimed.
  We can get this with a range maximum data structure.
  We actually need the index of the maximum, so we can have a value-idx map with a queue of indexes.

  Simulate solving until your enemy reaches the desired index.
  Use binary search on the prefix sum of A to count how many balloons you have.
    You also need to keep track of how many balloons you already popped.
  Greedily pop the balloons at the moment your enemy solves the problem.
    Repeat until you run out of balloons.
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
ll A[N], B[N];
ll prefixA[N], prefixB[N]; 
ll sparse[N][20];
map<ll, queue<int>> idxB;
ll n, m;

vector<ll> ans;

ll range_max(int l, int r){
  int k = r-l+1;
  int j = 0;
  while(k/2 > 0){
    j++;
    k/=2;
  }
  return max(sparse[l][j], sparse[r-(1<<j)+1][j]);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> A[i];
  for (int i = 0; i < n; i++) cin >> B[i];

  // prefix A
  int solvedA = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0) prefixA[i] = A[i];
    else prefixA[i] = prefixA[i-1]+A[i];

    if (prefixA[i] <= m) solvedA = i+1;
    else break;
  }

  // prefix B
  int solvedB = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0) prefixB[i] = B[i];
    else prefixB[i] = prefixB[i-1] + B[i];
    
    if (prefixB[i] <= m) solvedB = i+1;
    else break;
  }

  // compute sparse table
  for (int i = 0; i < n; i++) sparse[i][0] = B[i];
  for (int j = 1; j < 20; j++) {
    for (int i = 0; i < n; i++) {
      if (i + (1 << (j-1)) < n) sparse[i][j] = max(sparse[i][j-1], sparse[i+(1<<(j-1))][j-1]);
      else sparse[i][j] = sparse[i][j-1];
    }
  }

  // map B values to idx
  for (int i = 0; i < n; i++){
    idxB[B[i]].push(i);
  }

  if (solvedB < solvedA){
    cout << 0 << endl;
    return 0;
  }

  ll t = 0;
  int prev = -1;
  int l = 0;
  int used = 0;
  while (t <= m){
    if (l > solvedA-1) {
      cout << -1 << endl;
      return 0;
    }

    // getting idx of max
    ll maxB = range_max(l, solvedA-1);
    int idx = idxB[maxB].front();
    idxB[maxB].pop();
    while(idx < l){
      idx = idxB[maxB].front();
      idxB[maxB].pop();
    }
    

    t += prefixB[idx];
    if (prev >= 0) t -= prefixB[prev];

    while(t <= m){
      // compute how many A solved
      int lo = 0;
      int hi = solvedA-1;
      int cnt = 0;
      while(lo <= hi){
        int mid = hi - (hi-lo)/2;
        if (prefixA[mid] <= t){
          cnt = mid+1;
          lo = mid+1;
        }
        else hi = mid-1;
      }

      // update uses
      int can_use = cnt-used;
      if (can_use == 0) break;
      used += can_use;
      for (int i = 0; i < can_use; i++){
        if (t <= m) ans.push_back(t);
        t += B[idx];
      }
    }
   
    prev = idx;
    l = idx+1;
  }

  int nn = ans.size();
  cout << nn << endl;
  for (int i = 0; i < nn; i++){
    cout << ans[i];
    if (i == nn-1) cout << endl;
    else cout << " ";
  }
  return 0;
}
