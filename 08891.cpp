#include <iostream>

using namespace std;

int coordinates_to_n(int x, int y){
	int n = x + y - 2;
	return n * (n + 1) / 2 + x;
}

void n_to_coordinates(int n, int &x, int &y){
	int m = 0, diag = 0;
	while(true){
		++diag;
		if(m + diag >= n){
			break;
		}
		m += diag;
	}
	x = 1;
	y = diag;
	++m;
	while(m < n){
		++x;
		--y;
		++m;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int a, b;
		cin >> a >> b;
		int x1, y1, x2, y2;
		n_to_coordinates(a, x1, y1);
		n_to_coordinates(b, x2, y2);
		cout << coordinates_to_n(x1 + x2, y1 + y2) << '\n';
	}
	return 0;
}
