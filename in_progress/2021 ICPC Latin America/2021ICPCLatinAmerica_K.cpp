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
  
  int n; cin >> n;
  vector<string> words(n);
  bool letters[26];
  memset(letters, 0, sizeof letters);
  for (int i = 0; i < n; i++) {
    cin >> words[i];
    letters[words[i][0]-'A'] = true;
  }

  bool valid = false;
  for (int i = 0; i < n; i++) {
    bool tmp = true;
    for (char &c : words[i]) {
      tmp &= letters[c-'A'];
    }
    valid |= tmp;
  }

  cout << (valid ? "Y" : "N") << "\n";
  return 0;
}
