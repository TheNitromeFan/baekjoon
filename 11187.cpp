#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int additional_birds(vector<int> birds, int n, int len, int d){
	if(len < 12){
		return 0;
	}
	birds.push_back(6);
	birds.push_back(len - 6);
	sort(birds.begin(), birds.end());
	int ret = 2;
	for(int i = 0; i <= n; ++i){
		ret += (birds[i + 1] - birds[i]) / d - 1;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int len, d, n;
	cin >> len >> d >> n;
	vector<int> birds;
	for(int i = 0; i < n; ++i){
		int bird;
		cin >> bird;
		birds.push_back(bird);
	}
	cout << additional_birds(birds, n, len, d);
	return 0;
}
