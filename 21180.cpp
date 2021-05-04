#include <iostream>
#include <vector>

using namespace std;

bool good_numbers(vector<int> &x, int sum){
	for(int y : x){
		if(2 * y == sum){
			return true;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> x(n);
	int sum = 0;
	for(int i = 0; i < n; ++i){
		cin >> x[i];
		sum += x[i];
	}
	if(good_numbers(x, sum)){
		cout << sum / 2;
	}else{
		cout << "BAD";
	}
	return 0;
}
