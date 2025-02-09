#include <iostream>
#include <iomanip>
using namespace std;

typedef long double ld;
int main(int argc, char *argv[])
{
	ld a,b; cin >> a >> b;
	cout << setprecision(10) << fixed << b/100*a << endl;
}