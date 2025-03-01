/*
  I used calculus to show that the optimal choice is S/n where S is the sum of A_i for 1 <= i <= n. 
  Simply choose the nearest integer.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 101;
ll a[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  int total = 0;
  for (int i = 0; i < n; i++){
    cin >> a[i];
    total += a[i];
  }

  int best = round((ld)total/n);

  int ans = 0;
  for (int i = 0; i < n; i++){
    ans += (a[i]-best)*(a[i]-best);
  }

  cout << ans << endl;
  return 0;
}
