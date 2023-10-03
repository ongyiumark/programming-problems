#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int>> iii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  string s; cin >> s;
  vector<int> cnt(26);
  for (char ch : s) cnt[ch-'a']++;

  bool guessable = true;
  for (int i = 0; i < 26; i++) {
    guessable &= (cnt[i] <= 1);
  } 
  cout << (guessable ? 1 : 0) << "\n";
  return 0;
}
