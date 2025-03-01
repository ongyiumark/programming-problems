#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  map<int,int> cnt;
  for (int i = 0; i < 3; i++) {
    int a; cin >> a;
    cnt[a]++;
  }

  cout << ((cnt[5] == 2 && cnt[7] == 1) ? "YES": "NO") << endl;
  return 0;
}
