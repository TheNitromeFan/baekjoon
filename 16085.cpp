#include <iostream>
#include <cmath>
#include <iomanip>
#define PI acos(-1)

using namespace std;

double area(int w, int c){
	if(w >= c){
		return PI * w * w;
	}
	double alpha = acos(w / (double)c);
	return (PI - 2 * alpha) * w * w + 2 * w * c * sin(alpha);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		int t, w, c;
		cin >> t >> w >> c;
		cout << setprecision(3) << fixed << area(t * w, t * c) << '\n';
	}
	return 0;
}
