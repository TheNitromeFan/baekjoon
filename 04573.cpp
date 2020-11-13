#include <cstdio>

int main(){
	int cnt = 0;
	while(true){
		++cnt;
		int menus;
		scanf("%d", &menus);
		if(menus == 0){
			break;
		}
		int ans_num, ans_den;
		scanf("%d %d", &ans_num, &ans_den);
		for(int i = 1; i < menus; ++i){
			int num, den;
			scanf("%d %d", &num, &den);
			if(ans_num * ans_num * den < num * num * ans_den){
				ans_num = num;
				ans_den = den;
			}
		}
		printf("Menu %d: %d\n", cnt, ans_num);
	}
	return 0;
}
