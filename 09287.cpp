#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 1; a0 <= t; ++a0){
		int height;
		scanf("%d", &height);
		bool fallen = false;
		char row[4];
		for(int i = 0; i < height; ++i){
			scanf("%s", row);
			if((row[0] == '0' && row[1] == '0') || (row[1] == '0' && row[2] == '0')){
				fallen = true;
			}
		}
		printf("Case %d: %s\n", a0, (fallen ? "Fallen" : "Standing"));
	}
	return 0;
}
