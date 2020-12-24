#include <iostream>
#include <vector>

using namespace std;

int divisions(vector<int> &sticks, int n, int len){
	int ret = 0;
	for(int i = 0; i < n; ++i){
		ret += sticks[i] / len;
	}
	return ret;
}

int max_length(vector<int> &sticks, int n, int m){
	int low = 1, high = 2000000000;
	while(low < high){
		int mid = (low + high) / 2;
		if(divisions(sticks, n, mid) >= m){
			low = mid + 1;
		}else{
			high = mid;
		}
	}
	return low - 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m, n;
	cin >> m >> n;
	vector<int> sticks(n);
	for(int i = 0; i < n; ++i){
		cin >> sticks[i];
	}
	cout << max_length(sticks, n, m);
	return 0;
}
