/*
  First, notice that the parity of the manhattan distance must be the same for all points.
  Second, notice that lengths 1, 2, 4, 8, ..., 2^k encapsulates all points 
    with odd manhattan distance of at most 2^(k+1)-1. 
  If the manhattan distance is even, simply add an arm of length 1 at the end.
  
  To determine the way to reach a point, work backwards while making sure that the current point 
    is within the limits of the lengths that are left. 
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

const int N = 1000;
ll x[N], y[N];
ll pow2[31];

ll manhattan(ll cx, ll cy){
  return abs(cx)+abs(cy);
}

string solve(ll cx, ll cy, int i){
  if (i == 0){
    if (cx == 1) return "R";
    if (cx == -1) return "L";
    if (cy == 1) return "U";
    if (cy == -1) return "D";
  }
  int lim = pow2[i]-1;
  string res;
  if (manhattan(cx+pow2[i],cy) <= lim) res.append(1, 'L'), res += solve(cx+pow2[i],cy,i-1);
  else if (manhattan(cx-pow2[i],cy) <= lim) res.append(1, 'R'), res += solve(cx-pow2[i],cy,i-1);
  else if (manhattan(cx,cy+pow2[i]) <= lim) res.append(1, 'D'), res += solve(cx,cy+pow2[i],i-1);
  else if (manhattan(cx,cy-pow2[i]) <= lim) res.append(1, 'U'), res += solve(cx,cy-pow2[i],i-1);
  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

  int parity = (x[0]+y[0])%2;
  if (parity < 0) parity += 2;
  for (int i = 1; i < n; i++){
    int tmp = (x[i]+y[i])%2;
    if (tmp < 0) tmp += 2;
    if (parity != tmp) {
      cout << -1 << endl;
      return 0;
    }
  }

  // Up last move.
  if (parity == 0){
    for (int i = 0; i < n; i++)
      y[i]--;
  }

  pow2[0] = 1;
  for (int i = 1; i < 31; i++){
    pow2[i] = 2*pow2[i-1];
  }

  cout << 31+(parity==0) << endl;
  cout << pow2[0];
  for (int i = 1; i < 31; i++) cout << " " << pow2[i];
  if (parity == 0) cout << " " << 1;
  cout << endl;

  for (int i = 0; i < n; i++){
    string ans = solve(x[i], y[i], 30);
    reverse(ans.begin(), ans.end());
    cout << ans;
    if (parity == 0) cout << 'U';
    cout << endl;
  }
  return 0;
}
