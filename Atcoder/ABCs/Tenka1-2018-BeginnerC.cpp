/*
  Greedy Works. Start with the highest and lowest. Then, put the one with that increases the sum the most.
    You can use a deque.
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
ll A[N];
bool vis[N];
int n;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i];
  sort(A, A+n);

  memset(vis, 0, sizeof vis);
  ll ans = 0;
  
  deque<ll> dq;
  int l = 0, r = n-1;
  ans += abs(A[l]-A[r]);
  vis[l] = vis[r] = 1;
  dq.push_front(A[l++]); dq.push_back(A[r--]);
  while(!vis[l] && !vis[r]) {
    ll cl = dq.front();
    ll cr = dq.back();

    ll tmpl1 = abs(cl - A[l]);
    ll tmpl2 = abs(cr - A[l]);
    ll tmpr1 = abs(cl - A[r]);
    ll tmpr2 = abs(cr - A[r]);

    ll ansl = max(tmpl1, tmpl2);
    ll ansr = max(tmpr1, tmpr2);

    if (ansl > ansr) {
      if (tmpl1 > tmpl2) dq.push_front(A[l]);
      else dq.push_back(A[l]);
      vis[l] = 1;
      l++;
    }
    else {
      if (tmpr1 > tmpr2) dq.push_front(A[r]);
      else dq.push_back(A[r]);
      vis[r] = 1;
      r--;
    }
    ans += max(ansr, ansl);
  }
  cout << ans << endl;
  return 0;
}
