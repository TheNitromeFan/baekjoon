#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> jobs(n);
	for(int i = 0; i < n; ++i){
		cin >> jobs[i];
	}
	int max_load = 0;
	int j = 0;
	for(int i = 0; i < n; ++i){
		while(j < n && jobs[j] - jobs[i] < 1000){
			++j;
		}
		if(max_load < j - i){
			max_load = j - i;
		}
	}
	cout << (max_load - 1) / k + 1;
	return 0;
}
