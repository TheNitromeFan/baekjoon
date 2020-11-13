#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> x;
	int v;
	for(int i = 0; i < n; ++i){
		cin >> v;
		x.push_back(v);
	}
	if(n == 1 || (n == 2 && x[0] != x[1])){
		cout << 'A' << endl;
		return 0;
	}else if(n == 2){
		cout << x[0] << endl;
		return 0;
	}
	int a, b;
	int i;
	bool valid = true;
	if(x[0] == x[1]){
		a = 0;
		b = x[1];
		if(x[1] != x[2]){
			cout << 'B' << endl;
			return 0;
		}
	}else{
		if((x[2] - x[1]) % (x[1] - x[0]) != 0){
			cout << 'B' << endl;
			return 0;
		}else{
			a = (x[2] - x[1]) / (x[1] - x[0]);
			b = x[1] - a * x[0];
		}
	}
	for(int j = 3; j < n; ++j){
		if(x[j] != a * x[j-1] + b){
			cout << 'B' << endl;
			return 0;
		}
	}
	cout << x[n-1] * a + b << endl;
	return 0;
}
