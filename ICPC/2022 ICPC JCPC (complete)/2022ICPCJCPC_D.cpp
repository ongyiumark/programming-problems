#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ifstream f("dotak.in", ios::in);
  
  ll t; f >> t;
  while (t--) {
    ll n, k; f >> n >> k;
    n = n*k;
    bool isOmda = 0;
    if (k % 2 == 1) isOmda = n%2;
    else {
      n %= k+1;
      if (n == k) isOmda = 1;
      else isOmda = n%2;
    } 

    cout << (isOmda ? "Omda\n" : "Teemo\n");
  }
  f.close();

  return 0;
}