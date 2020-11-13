#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	vector<int> dice(3, 0);
	for(int i = 0; i < 3; ++i){
		scanf("%d", &dice[i]);
	}
	sort(dice.begin(), dice.end());
	int ans;
	if(dice[0] == dice[1] && dice[1] == dice[2]){
		ans = 10000 + dice[1] * 1000;
	}else if(dice[0] == dice[1] || dice[1] == dice[2]){
		ans = 1000 + dice[1] * 100;
	}else{
		ans = dice[2] * 100;
	}
	printf("%d", ans);
	return 0;
}
