#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  cin.tie(0)->sync_with_stdio(false);
  int n, m, k; cin >> n >> m >> k;
  vector<int> a(m);
  for (int &x : a) cin >> x;

  vector<int> scores(n+5), scores_geq(n+5);
  vector<int> ans(n+5, -1);
  for (int i = 0; i < m; i++) {
    fill(scores.begin(), scores.end(), 0);
    fill(scores_geq.begin(), scores_geq.end(), 0);
    for (int j = i; j < m && j-i+1 <= k; j++) {
      ans[a[j]] = max(scores_geq[scores[a[j]]+1], ans[a[j]]);
      scores[a[j]]++;
      scores_geq[scores[a[j]]]++;
    }
    for (int j = 1; j <= n; j++) {
      ans[j] = max(scores_geq[scores[j]+1], ans[j]);
    }
  }
  for(int i = 1; i <= n; i++) {
    cout << ans[i]+1 << " \n"[i==n];
  }
  
  return 0;
}