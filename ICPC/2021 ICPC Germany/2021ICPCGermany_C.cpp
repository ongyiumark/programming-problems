#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

string divide_by_hundred(ll x) {
  ostringstream decimal;
  decimal << setfill('0') << setw(2) << x%100;
  return to_string(x/100) + "." + decimal.str();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  vector<tuple<ll,ll,ll>> ar(n);

  ll buyers = 0;
  ll sellers = 0;
  for (int i = 0; i < n; i++) {
    string str_p; int b, s;
    cin >> str_p >> b >> s;


    str_p.erase(str_p.find('.'), 1);
    ll p = stoll(str_p);
    ar[i] = {p, b, s};
    buyers += b;
  }

  sort(ar.begin(), ar.end());
  ll turnover = 0;
  ll price = 0;
  for (int i = 0; i < n; i++) {
    auto [p, b, s] = ar[i];
    sellers += s;

    if (turnover <= min(buyers, sellers)*p) {
      price = p;
      turnover = min(buyers, sellers)*p;
    }

    buyers -= b;
  }

  if (turnover == 0) cout << "impossible\n";
  else cout << divide_by_hundred(price) << " " << divide_by_hundred(turnover) << "\n";
  
  return 0;
}