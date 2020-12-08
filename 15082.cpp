#include <iostream>
#include <cmath>
#include <iomanip>
#define PI acos(-1)

using namespace std;

long long square(long long x){
	return x * x;
}

void launch(int xm, int vx, int vy, int xa, int va, int tk){
	if(16 * tk >= vy){
		cout << "start running";
		return;
	}
	if(square(va * tk) < square(xm - xa + vx * tk) + square(vy * tk - 16 * tk * tk)){
		cout << "start running";
		return;
	}
	double tl = tk - sqrt(square(xm - xa + vx * tk) + square(vy * tk - 16 * tk * tk)) / va;
	double alpha = acos((xm - xa + vx * tk) / (va * (tk - tl))) * 180 / PI;
	cout << fixed << setprecision(8) << tl << " " << alpha;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int xm, vx, vy, xa, va, tk;
	cin >> xm >> vx >> vy >> xa >> va >> tk;
	launch(xm, vx, vy, xa, va, tk);
	return 0;
}
