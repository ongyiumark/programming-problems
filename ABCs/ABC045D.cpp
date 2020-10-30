/*
  Try every 3x3 that includes each of the painted cells.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5+1;
ll a[N];
ll b[N];

ll ans[10];

ll h, w, n;

map<pair<int,int>, bool> check;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> h >> w >> n;  
  for (int i = 0; i < n; i++){
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
    check[{a[i], b[i]}] = true;
  }

  memset(ans, 0, sizeof ans);

  for (int i = 0; i < n; i++){
    for (int j = 0; j < 9; j++){
      ll r = a[i]-j/3;
      ll c = b[i]-j%3;

      if (r < 0 || r+2 >= h || c < 0 || c+2 >= w) continue;
      int cnt = 0;
      for (int dr = 0; dr < 3; dr++){
        for (int dc = 0; dc < 3; dc++){
          if (check[{r+dr, c+dc}]) cnt++;
        }
      }
      ans[cnt]++;
    }
  }

  ans[0] = (h-2)*(w-2);
  for (int i = 1; i <= 9; i++){
    ans[i] /= i;
    ans[0] -= ans[i];

  }

  for (int i = 0; i <= 9; i++){
    cout << ans[i] << endl;
  }
  return 0;
}
