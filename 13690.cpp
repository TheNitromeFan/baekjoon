#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		double v;
		int n, m;
		cin >> v >> n >> m;
		if(v == 0 && n == 0 && m == 0){
			break;
		}
		double reward;
		if(n % 10000 == m % 10000){
			reward = v * 3000;
		}else if(n % 1000 == m % 1000){
			reward = v * 500;
		}else if(n % 100 == m % 100){
			reward = v * 50;
		}else if((n % 100 + 3) / 4 == (m % 100 + 3) / 4){
			reward = v * 16;
		}else{
			reward = 0;
		}
		cout << fixed << setprecision(2) << reward << '\n';
	}
	return 0;
}
