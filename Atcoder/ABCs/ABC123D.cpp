/*
  Binary search for the minimum total such that there are k combinations whose sum greater than that total.
    Basically, we are searching for the kth sum in the list.
    
  Then, we can go through A, B, C sorted in descending order. 
    We fix A and B and break C when the A+B+C is less than the sum.
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

const int N = 1005;
ll A[N], B[N], C[N];
int x,y,z,k;

bool valid(ll m){
  int cnt = 0;
  for (int a = 0; a < x; a++){
    for (int b = 0; b < y; b++){
      for (int c = 0; c < z; c++){
        if (A[a] + B[b] + C[c] < m) break;
        cnt++;
        if (cnt >= k) return true;
      }
    }
  }
  return false;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> x >> y >> z >> k;
  for (int i = 0; i < x; i++) cin >> A[i];
  for (int i = 0; i < y; i++) cin >> B[i];
  for (int i = 0; i < z; i++) cin >> C[i];
  sort(A, A+x, greater<ll>());
  sort(B, B+y, greater<ll>());
  sort(C, C+z, greater<ll>()); 

  ll lo = 0;
  ll hi = 1e11;
  ll minTotal = -1;
  while(lo <= hi){
    ll mid = hi - (hi-lo)/2;
    if (valid(mid)){
      minTotal = mid;
      lo = mid+1;
    }
    else hi = mid-1;
  }

  vector<ll> ans;
  for (int a = 0; a < x; a++){
    for (int b = 0; b < y; b++){
      for (int c = 0; c < z; c++){
        if (A[a] + B[b] + C[c] < minTotal) break;
        ans.push_back(A[a]+B[b]+C[c]);
      }
    }
  }
  sort(ans.begin(), ans.end(), greater<ll>());
  for (int i = 0; i < min((int)ans.size(), k); i++) cout << ans[i] << endl;

  return 0;
}
