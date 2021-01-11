#include <iostream>

using namespace std;

void puzzle(int c, int e, int m){
	if(c != 4 || e % 2 != 0){
		cout << "impossible";
		return;
	}
	if(m == 0){
		int w = e / 2, h = 0;
		cout << w + 2 << ' ' << h + 2;
	}
	for(int h = 1; h * h <= m; ++h){
		if(m % h == 0 && h + m / h == e / 2){
			cout << m / h + 2 << ' ' << h + 2;
			return;
		}
	}
	cout << "impossible";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int c, e, m;
	cin >> c >> e >> m;
	puzzle(c, e, m);
	return 0;
}
