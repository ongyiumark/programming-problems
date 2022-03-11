#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<int,pair<int,int>> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2e5+5;
ll a[N], b[N];
ll srtA[N],srtB[N];
int n;

ll find_best(int x, bool isA){
  ll* arr;
  bool *vis;
  if (isA) arr = srtA;
  else arr = srtB;
  
  int lo = 0;
  int hi = n-1;
  int ans = 0;
  while (lo <= hi){
    int mid = hi - (hi-lo)/2;
    if (x >= arr[mid]) {
      ans = mid;
      lo = mid+1;
    }
    else hi = mid-1;
  }

  ll ret = abs(x-arr[ans]);
  if (ans > 0) ret = min(ret,abs(x-arr[ans-1]));
  if (ans < n-1) ret = min(ret,abs(x-arr[ans+1]));

  return ret;
}

void testcase(){
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];

  for (int i = 0; i < n; i++) {
    srtA[i] = a[i]; srtB[i] = b[i];
  }

  sort(srtA, srtA+n); sort(srtB, srtB+n);

  vector<ll> result;
  result.push_back(find_best(a[0],0)+find_best(a[n-1],0)+find_best(b[0],1)+find_best(b[n-1],1));
  result.push_back(find_best(a[n-1],0)+find_best(b[n-1],1)+abs(a[0]-b[0]));
  result.push_back(find_best(a[0],0)+find_best(b[0],1)+abs(a[n-1]-b[n-1]));
  result.push_back(find_best(a[n-1],0)+find_best(b[0],1)+abs(a[0]-b[n-1]));
  result.push_back(find_best(a[0],0)+find_best(b[n-1],1)+abs(a[n-1]-b[0]));
  result.push_back(abs(a[0]-b[0])+abs(a[n-1]-b[n-1]));
  result.push_back((a[0]-b[n-1])+abs(a[n-1]-b[0]));
  sort(result.begin(), result.end());
  cout << result[0] << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  for (int x = 0; x < t; x++) {
    testcase();
  }
  
  return 0;
}
