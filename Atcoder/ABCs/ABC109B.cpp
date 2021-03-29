/*
  Implement it with sets.
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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  set<string> words;
  int n; cin >> n;
  bool valid = 1;
  char prev = '\0';
  for (int i = 0; i < n; i++){
    string s; cin >> s;
    if (words.find(s) != words.end()) valid = 0;
    if (i > 0 && s[0] != prev) valid = 0;
    prev = s[(int)s.size()-1];
    words.insert(s);
  }
  cout << (valid ? "Yes" : "No") << endl;
  return 0;
}
