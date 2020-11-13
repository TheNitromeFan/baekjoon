#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 10000

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int p[MAX], w[MAX];
	for(int i = 0; i < n; ++i){
		scanf("%d %d", &p[i], &w[i]);
	}
	for(int len = 8; len <= n; ++len){
		vector<int> bitmask(8, 1);
		bitmask.resize(len, 0);
		long long ans_psum = 0, ans_wsum = 1;
		do{
			long long psum = 0, wsum = 0;
			for(int i = 0; i < len; ++i){
				if(bitmask[i]){
					psum += p[i];
					wsum += w[i];
				}
			}
			if(ans_psum * wsum < psum * ans_wsum){
				ans_psum = psum;
				ans_wsum = wsum;
			}
		}while(prev_permutation(bitmask.begin(), bitmask.end()));
		printf("%f\n", ans_psum / (double)ans_wsum);
	}
	return 0;
}
