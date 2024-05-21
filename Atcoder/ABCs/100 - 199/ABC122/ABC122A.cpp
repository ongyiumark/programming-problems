/*  
  Just follow instructions.
  If it's A, print T. If it's T, print A.
  If it's C, print G. If it's G, print C.
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
  unordered_map<char, char> um = {{'A','T'} , {'T', 'A'}, {'C', 'G'}, {'G','C'}};
  string b; cin >> b;
  for (char c : b){
    cout << um[c];
  }
  cout << endl;
  return 0;
}
