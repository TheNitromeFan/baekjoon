#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#define PI acos(-1)

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, r;
	cin >> n >> r;
	vector<int> a(n);
	int sum = 0;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		sum += a[i];
	}
	double area = PI * r * r;
	for(int i = 0; i < n; ++i){
		cout << fixed << setprecision(9) << area * a[i] / sum << '\n';
	}
	return 0;
}
