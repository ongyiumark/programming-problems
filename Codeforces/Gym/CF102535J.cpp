/*
  Notice that each diagonal is an arithemetic sequence.
  2, 2, 6 2, 6 2, 10 6 2, 10 6 2, ...
  
  Doing algebra, we find that 2 + 6 + 10 + ... +  2 + 4(m-1) = 2m^2
  Since there's two of these sequences every diagonals, the sum of every two diagonals is 4m^2.

  We can do even better than this by getting the cummulative sum of 4n^2.
  4(1^2 + 2^2 + ... + m^2) = 2m(m+1)(2m+1)/3.

  Let x be the smallest m such that 2m(m+1)(2m+1)/3 < a.
  This means that the last electron shell must be on the 2x+1-th or the 2x+2-th diagonal.

  We know that the 2x+1-th diagonal starts with n = x+1, and the 2x+2-th diagonal starts with n = x+2.
  We also know that both diagonals start with a capacity of 2+4x.
  We can find the cummulative sum again.
  (2+4x + 2+4x-4 + 2+4x-8 + ... + 2+4x-4(m-1)) = 2m(2+2x-m).
  Now if a is greater than the sum of the 2x+1-th diagonal, then we know its in the 2x+2-th diagonal.
  Let y be the smallest m such that 2m(2+2x-m) < a after the first subtraction.

  We've know pinpointed the exact location of the last electron shell. We can easily derive n, l, and e from this.
  To convert l into letters, we subtract cummalative sums of 
    26^2(1 + 26^1 + ... + 26^m) = 26^2(26^(m+1)-1)/(26-1) 
  and write it in base 26.
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

string start = "spdfghijklmnoqrtuvwxyz";

ll fastpow(ll b, ll e){
  ll ans = 1;
  while(e > 0){
    if (e&1) ans *= b;
    b *= b;
    e >>= 1;
  }
  return ans;
}

string convert(ll l){
  string ans;
  if (l < start.size()) {
    ans.append(1, start[l]);
    return ans;
  }
  l -= (int)start.size();

  int len = 2;
  for (int i = 10; i >= 0; i--){
    if (l >= fastpow(26,2)*(fastpow(26, i)-1)/25){
      l -= fastpow(26,2)*(fastpow(26, i)-1)/25;
      len += i;
      break;
    }
  }

  while(l > 0){
    ans.append(1, l%26+'a');
    l /= 26;
    len--;
  }
  ans.append(len, 'a');
  reverse(ans.begin(), ans.end());
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while(t--){
    ll a; cin >> a;
    ll lo = 0;
    ll hi = 1e6;
    ll x = 0;
    while(lo <= hi){
      ll mid = hi-(hi-lo)/2;
      if (2*mid*(mid+1)*(2*mid+1)/3 < a){
        x = mid;
        lo = mid+1;
      }
      else hi = mid-1;
    }

    ll n = x+1;
    a -= 2*x*(x+1)*(2*x+1)/3;
    if (a > 2+2*x*(x+2)) {
      a -= 2+2*x*(x+2);
      n++;
    }

    lo = 0;
    hi = x;
    ll y = 0;
    while(lo <= hi){
      ll mid = hi-(hi-lo)/2;
      if (2*mid*(2+2*x-mid) < a){
        y = mid;
        lo = mid+1;
      }
      else hi = mid-1;
    }
    n += y;
    a -= 2*y*(2+2*x-y);
    ll lcap = 2+4*x-4*y;
    ll l = (lcap/2-1)/2;
    cout << n << convert(l) << a << endl;
  }
  return 0;
}
