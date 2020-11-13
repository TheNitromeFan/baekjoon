#include <cstdio>

int main(){
	int k, s;
	scanf("%d %d\n", &k, &s);
	k %= 26;
	char str[100001];
	fgets(str, 100001, stdin);
	for(int i = 0; i < s; ++i){
		if(str[i] >= 'A' && str[i] <= 'Z'){
			int tmp = str[i] - 'A';
			tmp += k;
			if(tmp >= 26){
				tmp -= 26;
			}
			str[i] = tmp + 'A';
		}else if(str[i] >= 'a' && str[i] <= 'z'){
			int tmp = str[i] - 'a';
			tmp += k;
			if(tmp >= 26){
				tmp -= 26;
			}
			str[i] = tmp + 'a';
		}
		printf("%c", str[i]);
	}
	return 0;
}
