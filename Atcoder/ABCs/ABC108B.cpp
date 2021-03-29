/*
  Make a vector and rotate it 90 degrees.
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

pair<int, int> rotate(pair<int,int> p){
  return {-p.second, p.first};
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  pair<int,int> p = {x2-x1,y2-y1};

  int x = x2;
  int y = y2;
  for (int i = 0; i < 2; i++){
    p = rotate(p);
    x += p.first;
    y += p.second;
    cout << x << " " << y;
    if (i == 0) cout << " ";
    else cout << endl;
  }

  return 0;
}
