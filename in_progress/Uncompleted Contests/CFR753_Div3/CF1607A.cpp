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
  
  int t; cin >> t;
  for (int x = 0; x < t; x++){
    string board;
    string s;
    cin >> board >> s;
    map<char, int> idx;
    for (int i = 0; i < 26; i++){
      idx[board[i]] = i+1;
    }
    int total = 0;
    int prev = idx[s[0]];
    for (int i = 1; i < s.size(); i++){
      int curr = idx[s[i]];
      total += abs(prev-curr);
      prev = curr;
    }
    cout << total << endl;
  }
  return 0;
}
