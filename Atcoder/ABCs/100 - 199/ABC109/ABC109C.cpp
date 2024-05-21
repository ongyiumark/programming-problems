/*
  GCD of all the distances from x.
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

const int N = 1e5;
int dist[N];

int gcd(int a, int b){
  if (b == 0) return a;
  return gcd(b, a%b);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, x; cin >> n >> x;
  int ans = 0;
  for (int i = 0; i < n; i++){
    int tmp; cin >> tmp;
    dist[i] = abs(tmp-x);
    ans = gcd(ans, dist[i]);
  }

  cout << ans << endl;
  return 0;
}
