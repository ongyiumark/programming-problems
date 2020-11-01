/*
  Get the max of the lefts and bottoms and min of the rights and tops.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 101;

int x[N];
int y[N];
int a[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int w, h, n;
  cin >> w >> h >> n;
  
  int left = 0;
  int right = w;
  int bottom = 0;
  int top = h;

  for (int i = 0; i < n; i++){
    cin >> x[i] >> y[i] >> a[i];
    if (a[i] == 1) left = max(left, x[i]);
    else if (a[i] == 2) right = min(right, x[i]);
    else if (a[i] == 3) bottom = max(bottom, y[i]);
    else top = min(top, y[i]);
  }

  if (top < bottom || right < left) cout << 0 << endl;
  else cout << (top-bottom)*(right-left) << endl;
  return 0;
}
