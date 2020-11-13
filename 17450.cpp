#include <cstdio>

int money(int price){
	int ret = 10 * price;
	if(ret >= 5000){
		ret -= 500;
	}
	return ret;
}

int main(){
	char ans[4] = "SNU";
	int ans_price, ans_weight, ans_idx = 0;
	scanf("%d %d", &ans_price, &ans_weight);
	for(int i = 1; i < 3; ++i){
		int price, weight;
		scanf("%d %d", &price, &weight);
		if(ans_weight * money(price) < weight * money(ans_price)){
			ans_price = price;
			ans_weight = weight;
			ans_idx = i;
		}
	}
	printf("%c", ans[ans_idx]);
	return 0;
}
