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

const int N = 1e6+5;
string s;
int xMax[N], xMin[N], yMax[N], yMin[N];


void testcase(){
  map<pii, bool> vis;
  int n, m; cin >> n >> m;
  cout << n << " " << m << endl;
  cin >> s;
  int posX = 0;
  int posY = 0;

  int moves = 0;
  xMax[0] = yMax[0] = xMin[0] = yMin[0] = 0;
  for (int i = 0; i < (int)s.size(); i++){
    if (s[i] == 'L') posX--;
    if (s[i] == 'R') posX++;
    if (s[i] == 'U') posY--;
    if (s[i] == 'D') posY++;

    if (vis[{posY,posX}]) break;
    vis[{posY,posX}] = 1;
    moves++;

    xMax[i] = max(0,posX);
    xMin[i] = min(0,posX);
    yMax[i] = max(0,posY);
    yMin[i] = min(0,posY);
    if (i != 0) {
      xMax[i] = max(xMax[i], xMax[i-1]);
      yMax[i] = max(yMax[i], yMax[i-1]);
      xMin[i] = min(xMin[i], xMin[i-1]);
      yMin[i] = min(yMin[i], yMin[i-1]);
    }
  }

  int xAns = 1;
  int yAns = 1;
  int mAns = 0;
  //cout << moves << endl;
  for (int i = 0; i < moves; i++){
    // xAns + xMax <= m
    // xAns + xMin >= 1
    // yAns + yMax <= n
    // yAns + yMin >= 1
    if (m-xMax[i] >= 1-xMin[i] && n-yMax[i] >= 1-yMin[i]){
      xAns = m-xMax[i];
      yAns = n-yMax[i];
      mAns = i+1;
    }
  }
  //cout << yAns << " " << xAns << " " << mAns << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  for (int k = 0; k < t; k++){
    testcase();
  }
  return 0;
}
