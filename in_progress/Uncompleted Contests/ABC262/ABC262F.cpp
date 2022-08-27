/*
  We want to minimize the first digit, denoted by x.
  There are two cases to consider:
    - We rotate until we bring x to the front.
    - We erase from the front until we bring x to the front.

  After doing one of these operations, we can simply greedily erase elements 
    if a[i] > a[i+1] for i = 1,2,3,..,n.
  We can do this on O(n) if we maintain a previdx and a nextidx array.
  
  Gotcha: removing a rotated term may not count as an operation
    because removing it before it was rotated will cancel the rotate operation.
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

const int N = 2e5+5;
int p[N], idx[N], ans[N];
int nextidx[N], previdx[N];
bool rem[N];

vector<int> res1, res2;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, k; cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    idx[p[i]] = i;
  }

  // Edge case: k = 0
  if (k == 0) {
    for (int i = 0; i < n; i++) {
      cout << p[i];
      if (i < n-1) cout << " ";
      else cout << endl;
    }
    return 0;
  }

  // Erase beginning
  for (int x = 1; x <= n; x++) {
    if (idx[x] > k) continue;
    int tmpK = k-idx[x];
    
    // Reset variables
    for (int i = 0; i < n; i++) {
      previdx[i] = i-1;
      nextidx[i] = i+1;
      rem[i] = 0;
    }

    // Erase beginning
    for (int i = 0; i < n; i++) {
      ans[i] = p[(i+idx[x])%n];
    
      if ((i+idx[x])%n < idx[x]) {
        rem[i] = 1; 
        nextidx[i] = n;
      }
    }

    // Greedily erase terms
    int j = 0;
    while(nextidx[j] < n) {
      if (ans[j] > ans[nextidx[j]] && tmpK > 0) {
        tmpK--;
        rem[j] = 1;
        if (previdx[j] >= 0) nextidx[previdx[j]] = nextidx[j];
        previdx[nextidx[j]] = previdx[j];
        if (previdx[j] >= 0) j = previdx[j];
        else j = nextidx[j];
        continue;
      }
      j = nextidx[j];
    }

    // Erase terms from the end
    for (int i = n-1; i >= 0 && tmpK > 0; i--){
      if (!rem[i]) {
        rem[i] = 1;
        tmpK--;
      }
    } 

    for (int i = 0; i < n; i++) {
      if (!rem[i]) res1.push_back(ans[i]);
    }

    break;
  }

  // Rotate end
  for (int x = 1; x <= n; x++) {
    if (n-idx[x] > k) continue;
    int tmpK = k-(n-idx[x]);
    
    // Reset variables
    for (int i = 0; i < n; i++) {
      previdx[i] = i-1;
      nextidx[i] = i+1;
      rem[i] = 0;
    }

    // Rotate end
    for (int i = 0; i < n; i++) {
      ans[i] = p[(i+idx[x])%n];
    }

    // Greedily erase terms
    int j = 0;
    while(nextidx[j] < n) {
      if (ans[j] > ans[nextidx[j]] && (tmpK > 0 || idx[ans[j]] > idx[x])) {
        if (idx[ans[j]] <= idx[x]) tmpK--;
        rem[j] = 1;
        if (previdx[j] >= 0) nextidx[previdx[j]] = nextidx[j];
        previdx[nextidx[j]] = previdx[j];
        if (previdx[j] >= 0) j = previdx[j];
        else j = nextidx[j];
        continue;
      }
      j = nextidx[j];
    }

    // Erase terms from the end
    for (int i = n-1; i >= 0 && tmpK > 0; i--){
      if (!rem[i]) {
        rem[i] = 1;
        tmpK--;
      }
    } 

    for (int i = 0; i < n; i++) {
      if (!rem[i]) res2.push_back(ans[i]);
    }

    break;
  }

  // Comparing results
  int sz1 = res1.size(), sz2 = res2.size();
  int cmp = 0;
  for (int i = 0; i < min(sz1, sz2) && cmp == 0; i++) {
    if (res1[i] == res2[i]) continue;
    if (res1[i] < res2[i]) cmp = -1;
    else cmp = 1;
  }

  if (cmp == 0) {
    if (sz1 < sz2) cmp = -1;
    else cmp = 1;
  }

  if (cmp == 1) {
    swap(res1, res2);
    swap(sz1, sz2);
  }
  for (int i = 0; i < sz1; i++) {
    cout << res1[i];
    if (i < sz1-1) cout << " ";
    else cout << endl;
  }

  
  return 0;
}
