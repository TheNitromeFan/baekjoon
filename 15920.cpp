#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	char act[11];
	scanf("%s", act);
	int pos = 0;
	int crushed = 0;
	bool top = false, bottom = true;
	for(int i = 0; i < n; ++i){
		if(act[i] == 'P'){
			if(pos == 1){
				top = true;
				bottom = true;
			}else if(pos == 0){
				top = !top;
				bottom = !bottom;
			}
		}else{
			pos += 1;
			if(pos == 2){
				if(top){
					crushed += 1;
				}
				if(bottom){
					crushed += 5;
				}
			}
		}
	}
	printf("%d", crushed);
	return 0;
}
