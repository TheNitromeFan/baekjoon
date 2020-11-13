#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int score(vector<int> cards){
	int ret = 0;
	vector<int> bitmask = {0, 0, 1, 1, 1};
	do{
		int sum = 0;
		for(int i = 0; i < 5; ++i){
			if(bitmask[i]){
				sum += cards[i];
			}
		}
		sum %= 10;
		if(sum > ret){
			ret = sum;
		}
	}while(next_permutation(bitmask.begin(), bitmask.end()));
	return ret;
}

int main(){
	int n;
	scanf("%d", &n);
	int max_idx = 0, max_score = 0;
	for(int i = 1; i <= n; ++i){
		vector<int> cards(5, 0);
		for(int j = 0; j < 5; ++j){
			scanf("%d", &cards[j]);
		}
		int s = score(cards);
		if(max_score <= s){
			max_score = s;
			max_idx = i;
		}
	}
	printf("%d", max_idx);
	return 0;
}
