/*
  We can calculate the number of operations by looking at the largest number in A, 
    and counting how many numbers get deleted each operation.
  
  Let OP be the number of operations.
  Go through each index i, advance OP operations to some index j.
    If a[j] <= n, set b[i] = a[j].
    If a[j] has already been set before, push index i into a vector indexed by a[j].
      This way, we know which indexes are grouped with which number.
    
  Let H be the highest number we already assigned.
  We simply want to make sure that we assigned all numbers less than H.

  Go through each number x until H, 
    If x has been already been assigned, push the indexes it's grouped with into a min heap.
    If x has not been assigned, we have to group it with a lower number (and leftmost).
      The optimal index of x is the top of this min heap.
    
  Go through each number x from H+1 to N.
    Greedily assign x into the first avalable space.
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
int par[N][31];
int a[N], b[N];
bool vis[N];
vector<int> track[N];

int findpar(int i, int k){
  for (int x = 0; x < 31; x++){
    if ((1<<x)&k) i = par[i][x];
  }
  return i;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> par[i][0];
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int k = 1; k < 31; k++){
    for (int i = 1; i <= n; i++){
      par[i][k] = par[par[i][k-1]][k-1];
    }
  }
  memset(b, -1, sizeof b);

  int hi = 0;
  for (int i = 1; i <= n; i++) hi = max(hi, a[i]);

  memset(vis, 0, sizeof vis);
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[par[i][0]]) {
      cnt++; 
    }
    vis[par[i][0]] = 1;
  }

  int op = (hi-n)/cnt;
  memset(vis, 0, sizeof vis);
  int nhi = 0;
  for (int i = 1; i <= n; i++){
    int j = findpar(i,op);
    if (vis[a[j]]) track[a[j]].push_back(i);
    if (a[j] <= n && !vis[a[j]]) {
      b[i] = a[j];
      vis[b[i]] = 1;
      nhi = max(nhi, b[i]);
    }
  }

  priority_queue<int,vector<int>,greater<int>> available;
  for (int i = 1; i < nhi; i++) {
    if (vis[i]) {
      for (int v : track[i]){
        if (b[v] == -1) available.push(v);
      }
      continue;
    }
    int idx = available.top();
    available.pop();
    b[idx] = i;
  }


  int curr = nhi+1;
  for (int i = 1; i <= n; i++) {
    if (b[i] == -1) {
      b[i] = curr;
      curr++;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << b[i];
    cout << (i == n ? "\n" : " ");
  }


  return 0;
}
