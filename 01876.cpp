#include <iostream>
#include <cmath>
#define PI acos(-1)
#define EPS 1e-8

using namespace std;

double dist(double x1, double y1, double angle){
	double x2 = cos(angle), y2 = sin(angle);
	double proj = x1 * x2 + y1 * y2;
	return sqrt(x1 * x1 + y1 * y1 - proj * proj);
}

bool hit(double t, double x){
	t *= 100;
	x *= PI / 180;
	double pin_x = t, pin_y = 0;
	double len = (105 - 2 * 10) / tan(x);
	double ball_x = -len / 2;
	do{
		if(dist(pin_x, pin_y, x) <= 10 + 6 + EPS){
			return true;
		}
		ball_x += len;
		pin_y += 105 - 2 * 10;
	}while(ball_x <= t + 10 + 6 + EPS);
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		double t, x;
		cin >> t >> x;
		cout << (hit(t, x) ? "yes" : "no") << "\n";
	}
	return 0;
}
