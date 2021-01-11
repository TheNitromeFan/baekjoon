#include <iostream>
#include <vector>

using namespace std;

long long balloons(vector<int> &staff, long long t){
	long long ret = 0;
	for(int person : staff){
		ret += t / person;
	}
	return ret;
}

long long time(vector<int> &staff, int m){
	long long low = 1, high = 20000000000000LL;
	while(low < high){
		long long mid = (low + high) / 2;
		if(balloons(staff, mid) >= m){
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
	int n, m;
	cin >> n >> m;
	vector<int> staff(n);
	for(int i = 0; i < n; ++i){
		cin >> staff[i];
	}
	cout << time(staff, m);
	return 0;
}
