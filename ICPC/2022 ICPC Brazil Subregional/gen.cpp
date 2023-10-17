#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int rand(int a, int b) {
  return rand()%(b-a+1) + a;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  srand(atoi(argv[1]));

  int n = rand(2, 10);
  int q = rand(1, 10);
  cout << n << " " << q << "\n";
  for (int i = 0; i < n; i++) {
    cout << rand(1, 100);
    cout << (i+1 < n ? " " : "\n");
  }
  for (int i = 0; i < q; i++) {
    cout << rand(1, 100) << " " << rand(1, 5) << "\n";
  }
  return 0;
}