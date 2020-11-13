#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int score(vector<int> &t, vector<int> &k){
	int n = t.size();
	int i1 = 0, j1 = 0, i2 = n-1, j2 = n-1;
	int wins = 0;
	while(i1 <= i2){
		if(t[i2] > k[j2]){
			--i2;
			--j2;
			++wins;
		}else if(t[i2] < k[j2]){
			--i2;
			++j1;
			--wins;
		}else if(t[i1] > k[j1]){
			++i1;
			++j1;
			++wins;
		}else if(t[i2] > k[j1]){
			--i2;
			++j1;
			++wins;
		}else if(t[i2] < k[j1]){
			--i2;
			++j1;
			--wins;
		}else{
			--i2;
			++j1;
		}
	}
	return wins;
}

int main(){
	while(true){
		int n;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		vector<int> t(n, 0), king(n, 0);
		for(int i = 0; i < n; ++i){
			scanf("%d", &t[i]);
		}
		sort(t.begin(), t.end(), greater<int>());
		for(int i = 0; i < n; ++i){
			scanf("%d", &king[i]);
		}
		sort(king.begin(), king.end(), greater<int>());
		printf("%d\n", 200 * score(t, king));
	}
	return 0;
}
