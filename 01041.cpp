#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	long long n;
	cin >> n;
	long long sides[6];
	for(int i = 0; i < 6; ++i){
		cin >> sides[i];
	}
	if(n == 1){
		sort(sides, sides+6);
		cout << sides[0] + sides[1] + sides[2] + sides[3] + sides[4] << endl;
		return 0;
	}
	for(int j = 0; j < 3; ++j){
		if(sides[j] > sides[5-j]){
			swap(sides[j], sides[5-j]);
		}
	}
	sort(sides, sides+3);
	cout << 4 * (sides[0] + sides[1] + sides[2]) + 4 * (2*n-3) * (sides[0] + sides[1]) + (5*n-6) * (n-2) * sides[0] << endl;
	return 0;
}
