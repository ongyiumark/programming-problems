#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

bool hate[10];

bool check(int x){
  string s = to_string(x);
  for (int i = 0; i < s.size(); i++){
    if (hate[s[i]-'0']) return false;
  }
  return true;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;

  memset(hate, 0, sizeof hate);
  for (int i = 0; i < k; i++){
    int d; cin >> d;
    hate[d] = true;
  }

  while(!check(n)) n++;

  cout << n << endl;

  return 0;
}
