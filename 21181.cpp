#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> x(n);
	for(int i = 0; i < n; ++i){
		cin >> x[i];
	}
	int min_energy = 2000000000;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < i; ++j){
			int energy = 0;
			for(int k = 0; k < n; ++k){
				energy += min((x[k] - x[i]) * (x[k] - x[i]), (x[k] - x[j]) * (x[k] - x[j]));
			}
			if(energy < min_energy){
				min_energy = energy;
			}
		}
	}
	cout << min_energy;
	return 0;
}
