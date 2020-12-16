#include <iostream>
#include <vector>

using namespace std;

bool travel(vector<long long> &v, int n, long long speed){
	for(int i = 0; i < n; ++i){
		if(speed < v[i]){
			return false;
		}
		speed -= speed % v[i];
	}
	return true;
}

long long minimum_speed(vector<long long> &v, int n){
	long long low = 1, high = 2000000000000000000LL;
	while(low < high){
		long long mid = (low + high) / 2;
		if(travel(v, n, mid)){
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
	vector<long long> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	cout << minimum_speed(v, n);
	return 0;
}
