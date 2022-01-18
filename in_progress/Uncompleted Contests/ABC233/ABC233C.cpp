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
int L[N];
vector<ll> a[N];
int curr[N];
ll X;
int n;

ll solve(int i){
  if (i == n) {
    if (X == 1) return 1;
    else return 0;
  }
  ll cnt = 0;
  for (int j = 0; j < L[i]; j++){
    if (X%a[i][j] != 0) continue;
    X/=a[i][j];
    cnt += solve(i+1);
    X*=a[i][j];
  }
  return cnt;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> X;
  for (int i = 0; i < n; i++){
    cin >> L[i];
    a[i].resize(L[i]);
    for (int j = 0; j < L[i]; j++){
      cin >> a[i][j];
    }
  }

  memset(curr, 0, sizeof curr);
  cout << solve(0) << endl;
  
  return 0;
}
