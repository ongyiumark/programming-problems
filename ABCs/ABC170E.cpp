/*
  Have a separate multiset for the strongest of the each multiset.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5+5;
int a[N];
int b[N];
int strongest[N];

multiset<int> kinder[N];
multiset<int> ans;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(strongest, -1, sizeof strongest);
  ll n, q;
  cin >> n >> q;
  
  for (int i = 1; i <= n; i++){
    cin >> a[i] >> b[i];
    kinder[b[i]].insert(a[i]);
    if (strongest[b[i]] < a[i]){
      if (strongest[b[i]] != -1) ans.erase(ans.find(strongest[b[i]]));
      strongest[b[i]] = a[i];
      ans.insert(strongest[b[i]]);
    }
  }

  for (int i = 0; i < q; i++){
    int c, d; cin >> c >> d;
    int from = b[c];
    int to = b[c] = d;
    
    if(strongest[from] != -1) ans.erase(ans.find(strongest[from]));
    kinder[from].erase(kinder[from].find(a[c]));
    if (kinder[from].size() > 0) {
      strongest[from] = *--kinder[from].end();
      ans.insert(strongest[from]);
    }
    else strongest[from] = -1;

    if (strongest[to] != -1) ans.erase(ans.find(strongest[to]));
    kinder[to].insert(a[c]);
    strongest[to] = *--kinder[to].end();
    ans.insert(strongest[to]);

    cout << *ans.begin() << "\n";
  }
  return 0;
}
