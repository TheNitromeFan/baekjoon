#include <iostream>
#include <algorithm>
#define MAX 1000

using namespace std;

long long cool(int comp[][MAX], int n, int level){
	long long ret = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			ret += min(level, comp[i][j]);
		}
	}
	return ret;
}

int height(int comp[][MAX], int n, long long total, int low, int high){
	while(low < high){
		int mid = (low + high) / 2;
		if(cool(comp, n, mid) * 2 >= total){
			high = mid;
		}else{
			low = mid + 1;
		}
	}
	return low;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int low = 0, high = 0;
	long long total = 0;
	int comp[MAX][MAX];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> comp[i][j];
			high = max(high, comp[i][j]);
			total += comp[i][j];
		}
	}
	cout << height(comp, n, total, low, high);
	return 0;
}
