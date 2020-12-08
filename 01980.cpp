#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, t;
	cin >> n >> m >> t;
	int time = t;
	int burgers = 0;
	for(int a = 0; a * n <= t; ++a){
		for(int b = 0; a * n + b * m <= t; ++b){
			if(time > t - a * n - b * m || (time == t - a * n - b * m && burgers < a + b)){
				time = t - a * n - b * m;
				burgers = a + b;
			}
		}
	}
	cout << burgers << " " << time;
	return 0;
}
