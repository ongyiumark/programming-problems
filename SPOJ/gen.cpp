#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
  return rand()%(b-a+1) + a;
}

void printTreeEdges(vector<int> prufer) {
  int m = prufer.size();
  int n = prufer.size()+2;
  vector<int> vertex_set(n);

  for (int i = 0; i < n; i++)
    vertex_set[i] = 0;

  // Number of occurrences of vertex in code
  for (int i = 0; i < n - 2; i++)
    vertex_set[prufer[i]] += 1;

  int j = 0;
  // Find the smallest label not present in
  // prufer[].
  for (int i = 0; i < n - 2; i++) {
    for (j = 0; j < n; j++){
      if (vertex_set[j] == 0) {
        vertex_set[j] = -1;
        cout << j << " " << prufer[i] << "\n";
        vertex_set[prufer[i]]--;

        break;
      }
    }
  }

  j = 0;

  // For the last element
  for (int i = 0; i < n; i++) {
    if (vertex_set[i] == 0 && j == 0) {
      cout << i << " ";
      j++;
    }
    else if (vertex_set[i] == 0 && j == 1)
      cout << i << "\n";
  }
}
 
// Function to Generate Random Tree
void generateRandomTree(int n) {
  int length = n - 2;
  vector<int> arr(length);

  for (int i = 0; i < length; i++) 
    arr[i] = rand(0, length + 1);

  printTreeEdges(arr);
}

int main(int argc, char* argv[]) {
  srand(atoi(argv[1]));

  int t = 1;
  int n = 9;
  cout << t << "\n";
  for (int tt = 0; tt < t; tt++) {
    cout << n << "\n";
    generateRandomTree(n);
    int q = rand(1,3);
    cout << q << "\n";
    for (int i = 0; i < q; i++) {
      cout << rand(0, n-1) << " " << rand(0, n-1) << " " << rand(0, 10) << "\n";
    }
  }

  return 0;
}