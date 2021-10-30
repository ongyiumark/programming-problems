/*
  Binary search for the answer.
  Draw circles over the points. Groups of overlapping points must not cover the top left and bottom right.
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

const int N = 1e4+5;
ld x[N], y[N];
int n;
ld X, Y;

struct dsu{
  vector<int> p;
  dsu(int n) : p(n,-1){};
  int find(int x){
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
  }
  bool unite(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (p[a] > p[b]) swap(a,b);
    p[a] += p[b];
    p[b] = a;
    return true;
  }
};

bool valid(ld d){
  dsu mydsu(n);
  for (int i = 0; i < n; i++){
    for (int j = i+1; j < n; j++){
      if ((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) < d*d){
        mydsu.unite(i,j);
      } 
    }
  }

  vector<int> groups[n];
  for (int i = 0; i < n; i++){
    groups[mydsu.find(i)].push_back(i);
  }
  
  for (int i = 0; i < n; i++){
    if (groups[i].size() == 0) continue;
    bool leftup = true;
    bool downright = true;
    
    for (int j : groups[i]) {
      //cout << j << " ";
      
      if (x[j] + d/2 > X) downright = false;
      if (x[j] - d/2 < 0) leftup = false;
      if (y[j] + d/2 > Y) leftup = false; 
      if (y[j] - d/2 < 0) downright = false;
    }
    //cout << endl;
    if (leftup == false && downright == false) return false;
  }
  return true;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> X >> Y;
  cin >> n;

  ld leftup = 1e7, downright = 1e7;
  for (int i = 0; i < n; i++){
    cin >> x[i] >> y[i];
    leftup = min({leftup, x[i], Y-y[i]});
    downright = min({downright, X-x[i], y[i]});
  }

  
  ld lo = 0;
  ld hi = 2e9;
  ld ans = 0;
  while (abs(lo - hi) > 1e-6){
    ld mid = hi-(hi-lo)/2;
    if (valid(mid)) {
      ans = mid;
      lo = mid;
    }
    else hi = mid;
    //cout << mid << endl;
  }
  //cout << ans << endl;
  

  //valid(2);
  cout << setprecision(10) << fixed << max({ans/2, leftup, downright}) << endl;
  return 0;
}
