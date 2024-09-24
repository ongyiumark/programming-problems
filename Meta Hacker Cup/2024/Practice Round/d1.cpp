#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef pair<ii, int> iii;

void testcase() {
  int n, g; cin >> n >> g;
  vector<int> E(n);
  for (int &x : E) cin >> x;
  sort(E.begin(), E.end());

  int closest_index = 0;
  int closest = 1e9;
  for (int i = 0; i < n; i++) {
    if (abs(E[i]-g) <= closest) {
      closest = abs(E[i]-g);
      closest_index = n-i;
    }
  }
  cout << closest_index << " " << closest << "\n";
}

void main_() {
  cin.tie(0)->sync_with_stdio(false);
  int T; cin >> T;
  for (int t = 1; t <= T; t++){
    cout << "Case #" << t << ": ";
    testcase();
  }
}

static void run_with_stack_size(void (*func)(void), size_t stsize) {
  char *stack, *send;
  stack = (char *)malloc(stsize);
  send = stack + stsize - 16;
  send = (char *)((uintptr_t)send / 16 * 16);
  asm volatile(
    "mov %%rsp, (%0)\n"
    "mov %0, %%rsp\n"
    :
    : "r"(send));
  func();
  asm volatile("mov (%0), %%rsp\n" : : "r"(send));
  free(stack);
}

int main() {
  run_with_stack_size(main_, 1024 * 1024 * 1024); // run with a 1 GiB stack
  return 0;
}