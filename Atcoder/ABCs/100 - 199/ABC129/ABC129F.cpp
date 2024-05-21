/*
  We want to multiply by 10^d where d is the number of digits of the next number in the sequence.
  Then, add the next number in the sequence.

  We can do this with matrices.
  Let X be the current number, and let s be the next number in the sequence.
  Multiply the following:
    X s 1

    10^d 0  0
    1    1  0
    0    B  1

  We simply need to count how many elements in the sequence have d digits.
  Then, do matrix exponentiation.
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

ll L, A, B, M;

vector<vector<ll>> matmult(vector<vector<ll>> &a, vector<vector<ll>> &b) {
  int m = a.size();
  int n = b[0].size();
  vector<vector<ll>> ans(m, vector<ll>(n, 0));
  for (int i = 0; i < m; i++) {
    for (int k = 0; k < b.size(); k++){
      for (int j = 0; j < n; j++){
        ans[i][j] = (ans[i][j] + a[i][k]*b[k][j])%M;
      }
    }
  }
  return ans;
}

vector<vector<ll>> matpow(vector<vector<ll>> &b, ll e){
  int m = b.size();
  vector<vector<ll>> ans(m, vector<ll>(m, 0));
  for (int i = 0; i < m; i++) ans[i][i] = 1;
  while(e) {
    if (e&1) ans = matmult(ans, b);
    b = matmult(b,b);
    e >>= 1;
  }
  return ans;
}

void debugprint(vector<vector<ll>> &a){
  int m = a.size();
  int n = a[0].size();
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++){
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

ll lim[19];
ll tens[19];
ll cnt[19];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> L >> A >> B >> M;
  tens[0] = 1;
  lim[0] = A-1;
  ll totalcnt = 0;
  for (int i = 1; i <= 18; i++) {
    tens[i] = tens[i-1]*10;
    lim[i] = tens[i]-1;

    if (lim[i] <= lim[i-1]) {
      lim[i] = A-1;
      continue;
    }

    // lim[i-1] < A + Bi <= lim[i]
    // i <= (lim[i]-A)/B
    // (lim[i-1]-A)/B < i
    cnt[i] = (lim[i]-A)/B;
    if (lim[i-1] >= A) cnt[i] -= (lim[i-1]-A)/B;
    else cnt[i] += 1;

    totalcnt += cnt[i];
    if (totalcnt > L) {
      ll extra = totalcnt - L;
      totalcnt -= extra;
      cnt[i] -= extra;
    }
  }

  vector<vector<ll>> st = {{0, A, 1}};
  
  for (int i = 1; i <= 18; i++) {
    vector<vector<ll>> b = {{tens[i]%M,0,0}, {1, 1, 0}, {0, B, 1}};
    vector<vector<ll>> powd = matpow(b, cnt[i]);
    st = matmult(st, powd);
  }
  cout << st[0][0] << endl;
  return 0;
}
