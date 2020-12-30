#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> fibs = {1, 2};
	while(fibs.back() <= 10000){
		fibs.push_back(fibs[fibs.size() - 2] + fibs.back());
	}
	int max[10001] = {}, min[10001] = {};
	max[2] = 1;
	min[2] = 1;
	max[3] = 2;
	min[3] = 2;
	for(int i = 4; i <= 10000; ++i){
		min[i] = 1000000000;
		for(int j = 1; i >= fibs[j]; ++j){
			if(max[i] < fibs[j - 1] + max[i - fibs[j]]){
				max[i] = fibs[j - 1] + max[i - fibs[j]];
			}
			if(min[i] > fibs[j - 1] + min[i - fibs[j]]){
				min[i] = fibs[j - 1] + min[i - fibs[j]];
			}
		}
	}
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	cout << min[n] << ' ' << max[n];
	return 0;
}
