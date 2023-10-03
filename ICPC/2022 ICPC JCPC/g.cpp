#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

const int INF = 1e9;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ifstream cin("milk.in");

  int t; cin >> t;
  while(t--) {
    int n, q; cin >> n >> q;
    vector<int> A(n);
    for (int &x : A) cin >> x;

    vector<ii> inc, dec;
    vector<int> sufmin(n, INF), sufmax(n, -INF);
    sufmin[n-1] = sufmax[n-1] = A[n-1];
    for (int i = n-2; i >= 0; i--) {
      sufmax[i] = max(A[i], sufmax[i+1]);
      sufmin[i] = min(A[i], sufmin[i+1]);
    }

    for (int i = 0; i < n-1; i++) {
      int a = A[i];
      int b = sufmax[i+1];
      int c = sufmin[i+1];

      if (a > b) b = a;
      if (a < c) c = a;

      inc.push_back({a, b});
      dec.push_back({a, c});
    }
    inc.push_back({A[n-1], A[n-1]});
    dec.push_back({A[n-1], A[n-1]});

    sort(inc.begin(), inc.end(), [](const ii &left, const ii &right) {
      if (left.first == right.first) return left.second > right.second;
      return left.first < right.first;
    });
    sort(dec.begin(), dec.end(), [](const ii &left, const ii &right) {
      if (left.first == right.first) return left.second < right.second;
      return left.first > right.first;
    });

    vector<ii> finc, fdec;
    int j = 0;
    finc.push_back(inc[j]);
    for (int i = 1; i < n; i++) {
      auto [l, r] = inc[j];
      auto [cl, cr] = inc[i];
      if (l <= cl && cr <= r) continue;
      
      j = i;
      finc.push_back(inc[j]);
    }

    j = 0;
    fdec.push_back(dec[j]);
    for (int i = 1; i < n; i++) {
      auto [l, r] = dec[j];
      auto [cl, cr] = dec[i];
      if (l >= cl && cr >= r) continue;
      
      j = i;
      fdec.push_back(dec[j]);
    }

    // for (auto [l, r] : fdec) {
    //   cout << l << " " << r << endl;
    // }

    while(q--) {
      int u, v; cin >> u >> v;
 
      bool valid = false;
    
      if (u <= v) {
        int lo = 0;
        int hi = (int)finc.size()-1;
        int ans = -1;
        
        while(lo <= hi) {
          int mid = hi-(hi-lo)/2;
          auto [l, r] = finc[mid];
          if (l <= u) {
            ans = mid;
            lo = mid+1;
          }
          else hi = mid-1;
        }

        if (ans >= 0) {
          auto [l, r] = finc[ans];
          if (l <= u && v <= r) valid = true;
        } 
      }
      
      if (u >= v) {
        int lo = 0;
        int hi = (int)fdec.size()-1;
        int ans = -1;
        
        while(lo <= hi) {
          int mid = hi-(hi-lo)/2;
          auto [l, r] = fdec[mid];
          if (l >= u) {
            ans = mid;
            lo = mid+1;
          }
          else hi = mid-1;
        }

        if (ans >= 0) {
          auto [l, r] = fdec[ans];
          if (l >= u && v >= r) valid = true;
        } 
      }

      cout << (valid ? "Yes\n" : "No\n");
    }
  }

  return 0;
}