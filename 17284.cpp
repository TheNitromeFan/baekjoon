#include <cstdio>

int main(){
	int money = 5000;
	int button;
	while(scanf("%d", &button) == 1){
		switch(button){
			case 1:
				money -= 500;
				break;
			case 2:
				money -= 800;
				break;
			case 3:
				money -= 1000;
				break;
		}
	}
	printf("%d", money);
	return 0;
}
