/*
  The critical observation is that if we're facing left or right, we can choose to turn either up or down.
  If we're facing up or down, we can choose to turn either left or right.
  That is, we can either add or subtract the x-component, or add or subtract the y-component.
  A turn simply switches the component we're dealing with.

  More concretely, let's separate the sequence by turns. Let f_i be the numbers of F's in the i-th part.
    - Move d_1 to the right
    - Move d_2 up or down
    - Move d_3 left or right
    - Move d_4 up or down
    ...

  We simply need to determine if its possible to reach (x,y) with these numbers.
  This can be done with DP. Deal with x and y separately.
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

const int N = 8001;
vector<int> numsx, numsy;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s; cin >> s;
  int x, y;
  cin >> x >> y;
  x += 8000;
  y += 8000;
  
  int n = s.size();
  int i = 0;
  while(i < n && s[i] == 'F'){
    i++;
  }
  int first_cnt = i;
  
  bool vert = 0;
  while(true){
    if (i >= n) break;
    if (s[i] == 'T'){
      vert = !vert;
      i++;
      continue;
    }
    int cnt = 0;
    while(i < n && s[i] == 'F'){
      i++;
      cnt++;
    }
    if (vert) numsy.push_back(cnt);
    else numsx.push_back(cnt);
  }

  int xn = numsx.size();
  bool dpx[xn+1][2*N];
  memset(dpx, 0, sizeof dpx);
  dpx[0][8000+first_cnt] = 1;
  for (int i = 0; i < xn; i++){
    for (int j = 0; j < 2*N; j++){
      if (!dpx[i][j]) continue;
      if (j+numsx[i] < 2*N) dpx[i+1][j+numsx[i]] = 1;
      if (j-numsx[i] >= 0) dpx[i+1][j-numsx[i]] = 1;
    }
  }

  int yn = numsy.size();
  bool dpy[yn+1][2*N];
  memset(dpy, 0, sizeof dpy);
  dpy[0][8000] = 1;
  for (int i = 0; i < yn; i++){
    for (int j = 0; j < 2*N; j++){
      if (!dpy[i][j]) continue;
      if (j+numsy[i] < 2*N) dpy[i+1][j+numsy[i]] = 1;
      if (j-numsy[i] >= 0) dpy[i+1][j-numsy[i]] = 1;
    }
  }

  cout << (dpx[xn][x] && dpy[yn][y] ? "Yes" : "No") << endl;
}
