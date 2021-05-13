#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#define PI acos(-1)

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m, n;
	double r;
	int ax, ay, bx, by;
	cin >> m >> n >> r >> ax >> ay >> bx >> by;
	double arc = PI * r * abs(ax - bx) / m * min(ay, by) / n;
	double line = r * abs(ay - by) / n;
	cout << fixed << setprecision(11) << min(r * ay / n + r * by / n, arc + line);
	return 0;
}
