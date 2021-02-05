/*
  This is probably the most complicated problem I've solved.
  Like before we let MEEKs be 0 and MOOKs be 1.
  First, we notice that we can simply ignore all the rightmost 0s.
    We create shorter string from this that ends in 1.

  From our shortened string, we notice that its optimal to reverse a suffix.
  This is because if we can turn that rightmost 1 into a 0, that's better than turning everything else to 0.
  
  Now, we only have n strings to compare, where n is the length of s.
  Notice that the string we want is the lexicographically smallest of the reverse.

  Let r be the reverse of s.
  If we list down all the strings we need to compare, we'll notice that they're all composed of substrings of s+r.

  If we can efficiently compare subtrings of a string, we can do the following:
    Say we want to compare a and b, both of which are composed of substrings of sr.
    We break up string a into x_1, x_2, x_3, ... where x_i is a substring of sr.
    Similarly, we break up string b into y_1, y_2, y_3, ....
    Finally, we can move around the x_i's and y_i's to make it such that |x_i| = |y_i|.

    After doing this, we can simply compare x_i with y_i.
    The first one that's not equal decides the comparison.

  So how do we compare substrings?
  The answer is a combination of suffix arrays, LCP arrays, and a segment tree.
  Suffix arrays can do comparison, but it fails in equality, so we use an LCP array for that.
  If the length of the strings are less than or equal to the LCP, then theyre equal.

  However, the LCP only compares adjacent strings in the suffix array.
  It turns out that the LCP of suffixes i and j is the minimum LCP along the interval [i+1,j] (1-indexed LCP).
  This is a ranged minimum query, which can be done with a segment tree. 
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<pair<int,int>, int> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

string s, sr;
int n;

const ll MOD = 1e9; 
const int N = 1e6+5;
int c[N], LCP[N], inv_suffix[N];
int seg_tree[2*N];
piii suffix[N];

int convert(char c){
  if (c == '$') return 0;
  return c-'0'+1;
}

void generate_suffix(){
  sr += '$';
  int m = sr.size();

  for (int h = -1; (1<<h) < m; h++){
    for (int i = 0; i < m; i++) suffix[i] = {{(h == -1 ? sr[i] : c[i]), (h == -1 ? 0 : c[(i+(1<<h))%m])}, i};
    sort(suffix, suffix+m);
    c[suffix[0].second] = 0;
    int cl = 1;
    for (int i = 1; i < m; i++){
      if (suffix[i].first != suffix[i-1].first) cl++;
      c[suffix[i].second] = cl-1;
    }
  }

  for (int i = 0; i < m-1; i++){
    suffix[i] = suffix[i+1];
  }  
}

void generate_lcp(){
  for (int i = 0; i < 2*n; i++) inv_suffix[suffix[i].second] = i;
  
  int l = 0;
  for (int i = 0; i < 2*n; i++){
    int k = inv_suffix[i];
    if (k == 0) continue;
    int j = suffix[k-1].second;
    while(sr[i+l] == sr[j+l]) l++;
    LCP[k] = l;
    if (l > 0) l--;
  }
}

void update(int k, int x){
  k += 2*n;
  seg_tree[k] = x;
  for (k /= 2; k >= 1; k/= 2){
    seg_tree[k] = min(seg_tree[2*k],seg_tree[2*k+1]);
  }
}

void generate_segtree(){
  int m = 2*n;
  for (int i = 0; i < 2*m; i++) seg_tree[i] = 1e9;
  for (int i = 0; i < m; i++) update(i, LCP[i]);
}

int range_min(int a, int b){
  a += 2*n;
  b += 2*n;
  int ret = 1e9;
  while(a <= b){
    if (a%2 == 1) ret = min(ret, seg_tree[a++]);
    if (b%2 == 0) ret = min(ret, seg_tree[b--]);
    a /= 2; b /= 2;
  }
  return ret;
}

int best_suffix(){
  sr = "";
  for (int i = 0; i < n; i++) sr += s[i];
  for (int i = n-1; i >= 0; i--) sr += s[i];
  generate_suffix();
  LCP[0] = 0;
  generate_lcp();
  generate_segtree();

  int best = 0;

  vector<pii> a = {{0,n},{0,0},{0,0}};
  for (int i = 1; i < n; i++){
    vector<pii> orig = a;
    vector<pii> b = {{i, n-i}, {2*n-i, i}, {0,0}};
    // refining
    for (int i = 0; i < 3; i++){
      if (a[i].second == b[i].second) continue;
      if (a[i].second > b[i].second) {
        int og = a[i].second;
        a[i].second = b[i].second;
        if (i == 0) a[2] = a[1];
        a[i+1] = {a[i].first+a[i].second, og-a[i].second};
      }
      else {
        int og = b[i].second;
        b[i].second = a[i].second;
        if (i == 0) b[2] = b[1];
        b[i+1] = {b[i].first+b[i].second, og-b[i].second};
      }
    }

    // compare
    bool lower = 0;
    for (int i = 0; i < 3; i++){
      if (a[i].second == 0) continue;
      int l = inv_suffix[a[i].first];
      int r = inv_suffix[b[i].first];
      if (r < l) swap(l,r);
      // strings are equal
      if (range_min(l+1,r) >= a[i].second) continue;
      if (inv_suffix[a[i].first] > inv_suffix[b[i].first]) lower = 1;
      break;
    }

    if (lower) {
      a = {{i, n-i}, {2*n-i, i}, {0,0}};
      best = i;
    }
    else a = orig;
  }

  return best;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while(t--){
    cin >> s;
    n = s.size();
    int r = n-1;
    while(r >= 0 && s[r] == 'E') r--;
    if (r < 0){
      cout << 0 << endl;
      continue;
    } 

    n = r+1;
    for (int i = 0; i < n; i++){
      s[i] = (s[i] == 'O' ? '1' : '0');
    }
    int x = best_suffix();

    ll ans = 0;
    ll mult = 1;
    for (int i = 0; i < x; i++){
      if (s[i] == '1') ans = (ans+mult)%MOD;
      mult = mult*2%MOD;
    }

    for (int i = n-1; i >= x; i--){
      if (s[i] == '1') ans = (ans+mult)%MOD;
      mult = mult*2%MOD;
    }
    cout << ans << endl;
  }
  return 0;
}
