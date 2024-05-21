/*
  Just implement it with a while true.
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

unordered_set<int> found;

int f(int n){
  if (n%2==0) return n/2;
  return 3*n+1;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int s; cin >> s;
  found.insert(s);
  int cnt = 1;
  while(true){
    cnt++;
    s = f(s);
    if (found.find(s) != found.end()){
      cout << cnt << endl;
      return 0;
    }
    found.insert(s);
  }
  return 0;
}
