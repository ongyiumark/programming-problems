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

int p;
const int N = 100;
string player[N];
int cnt[N];
void testcase(){
  memset(cnt, 0, sizeof cnt);
  int total = 0;
  for (int i = 0; i < N; i++) {
    cin >> player[i];
    for (int j = 0; j < player[i].size(); j++){
      total += player[i][j] == '1';
      cnt[i] += player[i][j] == '1';
    }
  }

  int idx = 0;
  ld lo = 100000;
  for (int i = 0; i < N; i++){
    ld total = 0;
    for (int j = 0; j < N; j++){
      if (i == j) continue;
      total += (ld)cnt[j]/10000;
    }
    ld mean = total/99;
    if (abs(mean-0.5) < lo){
      lo = abs(mean-0.5);
      idx = i;
    }
  }
  cout << idx << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  cin >> p;
  for (int x = 1; x <= t; x++){
    cout << "Case #" << x << ": ";
    testcase();
  }
  return 0;
}
