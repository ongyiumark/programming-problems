#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long long ld;

void forward(vector<int> &a, vector<int> &b, vector<bool> &vis, int &aidx, int &bidx, int &cidx) {
  int n = a.size(), m = b.size();
  while (aidx < n && a[aidx] > 0) aidx++;
  while (bidx < m && b[bidx] > 0) bidx++;
  while (cidx < n+m+1 && vis[cidx]) cidx++;
}

const int INF = 1e9;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m; cin >> n >> m;
  vector<int> a(n), b(m);
  vector<int> na(n, INF), nb(m, INF);
  vector<bool> vis(n+m+1);
  for (int &x : a) {
    cin >> x; vis[x] = true;
  }
  for (int &x : b) {
    cin >> x; vis[x] = true;
  }
  
  int aidx = 0, bidx = 0, cidx = 0;
  forward(a, b, vis, aidx, bidx, cidx);
  for (int i = n-1; i >= 0; i--) {
    if (a[i] > 0) na[i] = i;
    if (i < n-1) na[i] = min(na[i], na[i+1]);
  }
  for (int i = m-1; i >= 0; i--) {
    if (b[i] > 0) nb[i] = i;
    if (i < m-1) nb[i] = min(nb[i], nb[i+1]);
  }

  while(cidx < n+m+1) {
    if (aidx > 0 && a[aidx-1] > cidx) b[bidx] = cidx;
    else if (bidx > 0 && b[bidx-1] > cidx) a[aidx] = cidx;
    else if (aidx < n && bidx < m) {
      int aa = (na[aidx] < n ? a[na[aidx]] : na[aidx]);
      int bb = (nb[bidx] < m ? b[nb[bidx]] : nb[bidx]);
      if (aa < bb) a[aidx] = cidx;
      else b[bidx] = cidx;
    }
    else if (aidx < n) a[aidx] = cidx;
    else b[bidx] = cidx;

    vis[cidx] = true;
    forward(a, b, vis, aidx, bidx, cidx);
  }

  for (int i = 0; i < n; i++) cout << a[i] << (i+1 < n ? " ": "\n");
  for (int i = 0; i < m; i++) cout << b[i] << (i+1 < m ? " ": "\n");
  

  
  
  return 0;
}