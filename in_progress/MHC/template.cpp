#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

void testcase() {
  
}

void main_() {
  cin.tie(0)->sync_with_stdio(false);
  int t; cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    cout << "Case #" << tt << ": ";
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