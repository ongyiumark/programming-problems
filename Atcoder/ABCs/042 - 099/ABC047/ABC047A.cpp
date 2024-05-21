#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int cand[3];
  for (int i = 0; i < 3; i++)
    cin >> cand[i];

  sort(cand, cand+3);

  cout << (cand[0]+cand[1] == cand[2] ? "Yes" : "No") << endl;
  return 0;
}
