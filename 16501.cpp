#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	vector<int> skills(8, 0);
	for(int i = 0; i < 8; ++i){
		scanf("%d", &skills[i]);
	}
	sort(skills.begin(), skills.end());
	int diff = 20;
	do{
		int cmp = max(abs(skills[0] + skills[1] - skills[2] - skills[3]), abs(skills[4] + skills[5] - skills[6] - skills[7]));
		if(cmp < diff){
			diff = cmp;
		}
	}while(next_permutation(skills.begin(), skills.end()));
	if(diff % 2 == 0){
		printf("%.1f", 1 - diff / 20.0);
	}else{
		printf("%.2f", 1 - diff / 20.0);
	}
	return 0;
}
