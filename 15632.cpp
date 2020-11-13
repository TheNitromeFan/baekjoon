#include <iostream>

using namespace std;

int main(){
	int x[3], y[3], r[3];
	for(int i = 0; i < 3; ++i){
		cin >> x[i] >> y[i] >> r[i];
	}
	int n = 230;
	int area = 0;
	for(int i = 1; i <= n * 100; ++i){
		for(int j = 1; j <= n * 100; ++j){
			if((i / n - x[0] - 0.5 / n) * (i / n - x[0] - 0.5 / n) 
			   + (j / n - y[0] - 0.5 / n) * (j / n - y[0] - 0.5 / n) <= r[0] * r[0]){
			    ++area;
			}else if((i / n - x[1] - 0.5 / n) * (i / n - x[1] - 0.5 / n) 
			   + (j / n - y[1] - 0.5 / n) * (j / n - y[1] - 0.5 / n) <= r[1] * r[1]){
			    ++area;
			}else if((i / n - x[2] - 0.5 / n) * (i / n - x[2] - 0.5 / n) 
			   + (j / n - y[2] - 0.5 / n) * (j / n - y[2] - 0.5 / n) <= r[2] * r[2]){
			    ++area;
			}
		}
	}
	cout << area / (double)n / (double)n;
	return 0;
}
