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

string brackets = "()[]{}<>";
map<char, int> bracketidx;

void generate(string &s, vector<string> &all, string &ctx, int i) {
  if (i == s.size()) {
    all.push_back(ctx);
    return;
  }

  if (s[i] == '?') {
    for (int j = 0; j < 8; j++) {
      if (j % 2 == 1) {
        if (ctx.empty()) continue;
        if (bracketidx[ctx.back()] != j-1) continue;
        
        int last = ctx.back();
        ctx.pop_back();
        generate(s, all, ctx, i+1);
        ctx.push_back(last);
      }
      else {
        ctx.push_back(brackets[j]);
        generate(s, all, ctx, i+1);
        ctx.pop_back();
      }
    }
  }
  else {
    int j = bracketidx[s[i]];
    if (j % 2 == 1) {
      if (ctx.empty()) return;
      if (bracketidx[ctx.back()] != j-1) return;
      
      int last = ctx.back();
      ctx.pop_back();
      generate(s, all, ctx, i+1);
      ctx.push_back(last);
    }
    else {
      ctx.push_back(brackets[j]);
      generate(s, all, ctx, i+1);
      ctx.pop_back();
    }
  }
}

void solve(string &s, map<string, ll> &strmap) {
  vector<string> all;
  string ctx = "";
  generate(s, all, ctx, 0);
  for (string t : all) strmap[t]++;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i = 0; i < 8; i++) {
    bracketidx[brackets[i]] = i;
  }

  string s; cin >> s;

  int n = s.size();
  string left = s.substr(0, n/2);
  string right = s.substr(n/2, n/2);
  reverse(right.begin(), right.end());

  map<string,ll> leftmap, rightmap;
  for (int i = 0; i < n/2; i++) {
    if (right[i] == '?') continue;
    if (bracketidx[right[i]] % 2 == 0) right[i] = brackets[bracketidx[right[i]]+1];
    else right[i] = brackets[bracketidx[right[i]]-1];
  }

  solve(left, leftmap);
  solve(right, rightmap);

  ll ans = 0;
  for (auto it : leftmap) {
    ans += it.second*rightmap[it.first];
  }
  cout << ans << endl;
  return 0;
}
