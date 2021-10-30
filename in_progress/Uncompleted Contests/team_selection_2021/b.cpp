/*
  Brute force all the valid lengths of h(1) and h(0).
  We need to compare substrings quickly, so we use suffix array + LCP array + range minimum segment tree.
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

const int N = 3e5+5;
int c[N], LCP[N], inv_suffix[N];
int seg_tree[2*N];
piii suffix[N];
int n, m;
string s, t;

int convert(char c){
  if (c == '$') return 0;
  return c-'0'+1;
}

void generate_suffix(){
  t += '$';
  int k = t.size();

  for (int h = -1; (1<<h) < k; h++){
    for (int i = 0; i < k; i++) suffix[i] = {{(h == -1 ? t[i] : c[i]), (h == -1 ? 0 : c[(i+(1<<h))%k])}, i};
    sort(suffix, suffix+k);
    c[suffix[0].second] = 0;
    int cl = 1;
    for (int i = 1; i < k; i++){
      if (suffix[i].first != suffix[i-1].first) cl++;
      c[suffix[i].second] = cl-1;
    }
  }

  for (int i = 0; i < k-1; i++){
    suffix[i] = suffix[i+1];
  }  
}

void generate_lcp(){
  for (int i = 0; i < m; i++) inv_suffix[suffix[i].second] = i;
  
  int l = 0;
  for (int i = 0; i < m; i++){
    int k = inv_suffix[i];
    if (k == m-1) continue;
    int j = suffix[k+1].second;
    while(t[i+l] == t[j+l]) l++;
    LCP[k] = l;
    if (l > 0) l--;
  }
}

void update(int k, int x){
  k += m;
  seg_tree[k] = x;
  for (k /= 2; k >= 1; k/= 2){
    seg_tree[k] = min(seg_tree[2*k],seg_tree[2*k+1]);
  }
}

void generate_segtree(){
  for (int i = 0; i < 2*m; i++) seg_tree[i] = 1e9;
  for (int i = 0; i < m; i++) update(i, LCP[i]);
}

int range_min(int a, int b){
  a += m;
  b += m;
  int ret = 1e9;
  while(a <= b){
    if (a%2 == 1) ret = min(ret, seg_tree[a++]);
    if (b%2 == 0) ret = min(ret, seg_tree[b--]);
    a /= 2; b /= 2;
  }
  return ret;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> s >> t;
  int cnt0, cnt1;
  cnt0 = cnt1 = 0;
  n = s.size();
  m = t.size();
  for (int i = 0; i < n; i++){
    cnt0 += (s[i] == '0');
    cnt1 += (s[i] == '1');
  }

  // edge cases when cnt0 or cnt1 is 0
  if (cnt0==0 || cnt1==0){
    if (m%n == 0) cout << -1 << endl;
    else cout << 0 << endl;
    return 0;
  }

  generate_suffix();
  LCP[m-1] = 0;
  generate_lcp();
  generate_segtree();

  int ans = 0;
  for (int i = 0; i <= m; i++){
    int a = i;
    //a*cnt0 + b*cnt1 == m;
    if ((m - a*cnt0)%cnt1 != 0) continue;
    int b = (m-a*cnt0)/cnt1;
    if (b < 0 || b > m) continue;
    //cout << a << " " << b << endl;

    // verify
    pair<int,int> f0, f1;
    f0 = f1 = {-1,-1};
    int idx = 0;
    bool valid = true;
    for (int j = 0; j < n; j++){
      if (s[j] == '0') {
        pair<int,int> tmp = {idx,a};
        if (f0.first == -1) f0 = tmp;
        else {
          int cmp1 = inv_suffix[f0.first];
          int cmp2 = inv_suffix[tmp.first];
          if (cmp1 > cmp2) swap(cmp1, cmp2);
          if(range_min(cmp1, cmp2-1) < a) valid = false;
        }
        idx += a;
      } 
      else {
        pair<int,int> tmp =  {idx,b};
        if (f1.first == -1) f1 = tmp;
        else {
          int cmp1 = inv_suffix[f1.first];
          int cmp2 = inv_suffix[tmp.first];
          if (cmp1 > cmp2) swap(cmp1, cmp2);
          if(range_min(cmp1, cmp2-1) < b) valid = false;
        }
        idx += b; 
      }
      if (valid == false) break;
    }
    //cout << valid << endl;
    ans += valid;
  }
  cout << ans << endl;
  return 0;
}
