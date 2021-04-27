#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int simulate(vector<int> &a, vector<int> &b, int as, int bs, int start){
	int switches = 0;
	int i = 0, j = 0;
	while(i < as || j < bs){
		if(i == as && start == 1){
			++switches;
			start = 2;
			++j;
		}else if(i == as){
			++j;
		}else if(j == bs && start == 2){
			++switches;
			start = 1;
			++i;
		}else if(j == bs){
			++i;
		}else if(a[i] < b[j] && start == 2){
			++switches;
			start = 1;
			++i;
		}else if(a[i] < b[j]){
			++i;
		}else if(a[i] > b[j] && start == 1){
			++switches;
			start = 2;
			++j;
		}else if(a[i] > b[j]){
			++j;
		}else{
			++i;
			++j;
		}
	}
	return switches;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, a, b;
	cin >> n >> a >> b;
	vector<int> alice(a), bob(b);
	for(int i = 0; i < a; ++i){
		cin >> alice[i];
	}
	for(int j = 0; j < b; ++j){
		cin >> bob[j];
	}
	sort(alice.begin(), alice.end());
	sort(bob.begin(), bob.end());
	cout << min(simulate(alice, bob, a, b, 1), simulate(alice, bob, a, b, 2));
	return 0;
}
