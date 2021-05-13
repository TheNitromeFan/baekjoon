#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> x(10);
	for(int i = 0; i < 10; ++i){
		cin >> x[i];
	}
	int cnt = 0;
	for(int i = 0; i < 10; ++i){
		for(int j = 0; j < i; ++j){
			cnt += x[i] | x[j];
		}
	}
	for(int i = 0; i < 10; ++i){
		for(int j = 0; j < i; ++j){
			for(int k = 0; k < j; ++k){
				cnt += x[i] | x[j] | x[k];
			}
		}
	}
	cout << cnt % 2;
	return 0;
}
