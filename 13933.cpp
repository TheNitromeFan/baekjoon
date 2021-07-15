#include <iostream>
#include <vector>
#define MAX 1000001

using namespace std;

bool can_adjoin_weights(int w[MAX], int n, int thres){
	vector<int> v;
	for(int i = 0; i < n; ++i){
		if(w[i] > thres){
			v.push_back(w[i]);
		}
	}
	if(v.size() % 2 != 0){
		return false;
	}
	for(unsigned idx = 0; idx < v.size(); idx += 2){
		if(v[idx] != v[idx + 1]){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int w[2][MAX];
	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < n; ++j){
			cin >> w[i][j];
		}
	}
	int low = 0, high = 1000000001;
	while(low < high){
		int mid = (low + high) / 2;
		if(can_adjoin_weights(w[0], n, mid) && can_adjoin_weights(w[1], n, mid)){
			high = mid;
		}else{
			low = mid + 1;
		}
	}
	cout << high << '\n';
	return 0;
}
