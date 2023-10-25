#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  vector<int> A, B, rounds;

  A.push_back(0); B.push_back(0); 
  rounds.push_back(0);
  
  int ans = -1;
  bool game_ended = false;
  for (int i = 0; i < n; i++) {
    string line; cin >> line;
    istringstream ss(line);
    string token;
    vector<int> vals;
    while(getline(ss, token, '-')) vals.push_back(stoi(token));

    int a = vals[0], b = vals[1];
    int round = a+b;
    if (round > 0 && (round-1)/2 % 2 == 0) swap(a, b);
    
    bool valid = true;
    if (round < rounds.back() || a < A.back() || b < B.back() || (a == 11 && b == 11)) {
      valid = false;
      ans = i+1;
      break;
    }
    if (game_ended && (a > A.back() || b > B.back())) {
      valid = false;
      ans = i+1;
      break;
    }

    if (a == 11 || b == 11) game_ended = true; 
    A.push_back(a); 
    B.push_back(b);
    rounds.push_back(round);
  }
  if (ans == -1) cout << "ok\n";
  else cout << "error " << ans << "\n"; 
  return 0;
}