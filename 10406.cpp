#include <cstdio>

int main(){
	int waist, neck, punches;
	scanf("%d %d %d", &waist, &neck, &punches);
	int ans = 0;
	for(int i = 0; i < punches; ++i){
		int x;
		scanf("%d", &x);
		if(x >= waist && x <= neck){
			++ans;
		}
	}
	printf("%d", ans);
	return 0;
}
