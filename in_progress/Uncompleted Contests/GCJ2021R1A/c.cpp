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

int gcd(int a, int b){
  if (b == 0) return a;
  return gcd(b, a%b);
}

void testcase(){
  int n, q; cin >> n >> q;
  string A[n];
  int S[n];
  for (int i = 0; i < n; i++) cin >> A[i] >> S[i];
  if (q > 10) return;
  set<int> pos;
  for (int mask = 0; mask < (1<<q); mask++){
    int scores[n];
    memset(scores, 0, sizeof scores);
    for (int i = 0; i < n; i++){
      for (int j = 0; j < q; j++){
        if ((1<<j)&mask) scores[i] += A[i][j] == 'T';
        else scores[i] += A[i][j] == 'F';
      }
    }
    bool valid = 1;
    for (int i = 0; i < n; i++) {
      valid &= scores[i] == S[i];
    }
    if (valid) pos.insert(mask);
  }
  //for (auto p : pos) cout << p << endl;

  int best = 0;
  for (int j = 0; j < q; j++){
    int cnt = 0;
    for (auto p : pos){
      if ((1<<j)&p) cnt++;
    }
    if (2*cnt > pos.size()) best |= (1<<j);
  }
  int z = 0;
  for (auto p : pos){
    for (int j = 0; j < q; j++){
      if (((1<<j)&best) == ((1<<j)&p)) z++;
    }
  }
  string ans = "";
  for (int j = 0; j < q; j++){
    if ((1<<j)&best) ans += 'T';
    else ans += 'F';
  }
  int w = pos.size();
  int g = gcd(z,w);
  cout << ans << " " << z/g << "/" << w/g << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  for (int x = 1; x <= t; x++){
    cout << "Case #" << x << ": ";
    testcase();
  }
  return 0;
}
