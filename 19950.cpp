#include <iostream>
#include <cmath>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x1, y1, z1, x2, y2, z2;
	cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
	int n;
	cin >> n;
	int sum = 0, max = 0;
	for(int i = 0; i < n; ++i){
		int k;
		cin >> k;
		if(max < k){
			max = k;
		}
		sum += k;
	}
	double dist = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1));
	cout << (dist <= sum && dist >= 2 * max - sum ? "YES" : "NO");
	return 0;
}
