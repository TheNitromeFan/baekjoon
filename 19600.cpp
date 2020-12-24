#include <iostream>
#define MAX 5001

using namespace std;

int binary_steps(int n, int i){
	int left = 0, right = n - 1;
	int ret = 0;
	while(true){
		int mid = (left + right) / 2;
		if(mid == i){
			break;
		}else if(i < mid){
			right = mid - 1;
		}else{
			left = mid + 1;
		}
		++ret;
	}
	return ret;
}

int ternary_steps(int n, int i){
	int left = 0, right = n - 1;
	int ret = 0;
	while(true){
		int left_third = left + (right - left) / 3;
		int right_third = right - (right - left) / 3;
		if(left_third == i){
			break;
		}else if(right_third == i){
			++ret;
			break;
		}else if(i < left_third){
			ret += 2;
			right = left_third - 1;
		}else if(i < right_third){
			ret += 2;
			left = left_third + 1;
			right = right_third - 1;
		}else{
			ret += 2;
			left = right_third + 1;
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin >> q;
	int tmb[MAX][MAX];
	for(int n = 1; n < MAX; ++n){
		for(int i = 0; i < n; ++i){
			int bi = binary_steps(n, i), ti = ternary_steps(n, i);
			tmb[n][i] = ti - bi;
		}
	}
	int psum[MAX][MAX] = {};
	for(int n = 1; n < MAX; ++n){
		psum[n][0] = tmb[n][0];
		for(int i = 1; i < n; ++i){
			psum[n][i] = psum[n][i - 1] + tmb[n][i];
		}
	}
	for(int j = 0; j < q; ++j){
		int n, s, e;
		cin >> n >> s >> e;
		cout << psum[n][e] - psum[n][s] + tmb[n][s] << '\n';
		}
	return 0;
}
