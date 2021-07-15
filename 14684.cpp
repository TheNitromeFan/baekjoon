#include <iostream>
#include <vector>

using namespace std;

bool arithmetic_sequence(int h, int m){
	if(h < 10){
		int m1 = m / 10, m2 = m % 10;
		return 2 * m1 == h + m2;
	}else{
		int h1 = h / 10, h2 = h % 10, m1 = m / 10, m2 = m % 10;
		return 2 * h2 == h1 + m1 && 2 * m1 == h2 + m2;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> v(12 * 60);
	for(int time = 1; time < 12 * 60; ++time){
		v[time] = v[time - 1];
		int h = time / 60, m = time % 60;
		if(arithmetic_sequence((h + 11) % 12 + 1, m)){
			++v[time];
		}
	}
	int d;
	cin >> d;
	cout << v.back() * (d / (12 * 60)) + v[d % (12 * 60)] << '\n';
	return 0;
}
