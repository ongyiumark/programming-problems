/*
  There's only 2 answers.
  We either reduce the length of S to the length of the binary representation of K.
    Or one less than that since any binary number with less digits is automatically smaller.
  
  We simply need to check of the first reduction is possible. 
    We can do this by greedily removing the second most significant 1 digit until S is sufficiently reduced.
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

string bitify(ll x){
  string res = "";
  while(x > 0){
    if (x&1) res += '1';
    else res += '0';
    x/=2;
  }
  reverse(res.begin(), res.end());
  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  ll k; cin >> k;
  string s; cin >> s;
  string t = bitify(k);

  int n = t.size();
  int m = s.size();
  if (n > m){
    cout << 0 << endl;
    return 0;
  }

  int moves = m-n;
  bool rem[m];
  memset(rem, 0, sizeof rem);
  for (int i = 1; i < m; i++){
    if (moves > 0 && s[i] == '1') {
      moves--;
      rem[i] = 1;
    }
  }

  for (int i = 1; i < m; i++){
    if (moves > 0 && rem[i] == 0){
      moves--;
      rem[i] = 1;
    }
  }

  string ns = "";
  for (int i = 0; i < m; i++){
    if (rem[i]) continue;
    ns += s[i];
  }

  if (t >= ns) cout << m-n << endl;
  else cout << m-n+1 << endl;


  return 0;
}
