#include <cstdio>
#include <cstdlib>
#include <algorithm>

int main(){
	int left, right, ambidex;
	scanf("%d %d %d", &left, &right, &ambidex);
	if(left < right){
		if(left + ambidex < right){
			left += ambidex;
			ambidex = 0;
		}else{
			ambidex -= right - left;
			left = right;
		}
	}else if(left > right){
		if(left > right + ambidex){
			right += ambidex;
			ambidex = 0;
		}else{
			ambidex -= left - right;
			right = left;
		}
	}
	left += ambidex / 2;
	right += ambidex / 2;
	printf("%d", 2 * std::min(left, right));
	return 0;
}
