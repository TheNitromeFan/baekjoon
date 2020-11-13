#include <cstdio>
#include <algorithm>

int main(){
	int n;
	scanf("%d", &n);
	char pass[101];
	scanf("%s", pass);
	bool number = false, upper = false, lower = false, special = false;
	for(int i = 0; i < n; ++i){
		if(pass[i] >= '0' && pass[i] <= '9'){
			number = true;
		}else if(pass[i] >= 'A' && pass[i] <= 'Z'){
			upper = true;
		}else if(pass[i] >= 'a' && pass[i] <= 'z'){
			lower = true;
		}else{
			special = true;
		}
	}
	int ans = 0;
	if(!number){
		++ans;
	}
	if(!upper){
		++ans;
	}
	if(!lower){
		++ans;
	}
	if(!special){
		++ans;
	}
	printf("%d", std::max(ans, 6 - n));
	return 0;
}
