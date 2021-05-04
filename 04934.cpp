#include <iostream>
#include <cmath>
#include <iomanip>
#define PI acos(-1)

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 1; a0 <= t; ++a0){
		int h1, m1, s1, u1, h2, m2, s2, u2;
		cin >> h1 >> m1 >> s1 >> u1 >> h2 >> m2 >> s2 >> u2;
		double r;
		cin >> r;
		double angle1 = 30 * h1 + 0.5 * m1 + 0.5 * s1 / 60 + 0.5 * u1 / 6000;
		double angle2 = 30 * h2 + 0.5 * m2 + 0.5 * s2 / 60 + 0.5 * u2 / 6000;
		double angle_diff = angle2 - angle1;
		if(angle_diff < 0){
			angle_diff += 360;
		}
		cout << fixed << setprecision(3) << a0 << ". " << 0.5 * r * r * (angle_diff / 180 * PI) << '\n';
	}
	return 0;
}
