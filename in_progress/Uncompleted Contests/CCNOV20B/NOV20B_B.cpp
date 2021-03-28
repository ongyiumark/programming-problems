#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5+1;
int B[N];
int A[N];

const int M = 4e6+1;
vector<int> primes;
bool is_composite[M];

void sieve(int n){
  memset(is_composite, 0, sizeof is_composite);
  for (int i = 2; i < n; i++){
    if (!is_composite[i]) primes.push_back(i);
    for (int j = 0; j < (int)primes.size() && i*primes[j] < n; j++){
      is_composite[i*primes[j]] = 1;
      if (i%primes[j]==0) break; 
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  sieve(M);
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    for (int i = 0; i < n; i++){
      cin >> B[i];
      A[i] = primes[B[i]];
    }

    for (int i = 0; i < n; i++){
      cout << A[i];
      if (i == n-1) cout << endl;
      else cout << " ";
    }
  }
  return 0;
}
