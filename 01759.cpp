#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int main(){
	int l, c;
	scanf("%d %d\n", &l, &c);
	char x[16], y[16];
	char input[30];
	fgets(input, 30, stdin);
	for(int i = 0; i < c; ++i){
		x[i] = input[2*i];
	}
	sort(x, x+c);
	string bitmask(l, 1);
	bitmask.resize(c, 0);
	do{
		int j = 0;
		int vowels = 0, consonants = 0;
		for(int i = 0; i < c && j < l; ++i){
			if(bitmask[i]){
				y[j] = x[i];
				if(y[j] == 'a' || y[j] == 'e' || y[j] == 'i' || y[j] == 'o' || y[j] == 'u'){
					++vowels;
				}else{
					++consonants;
				}
				++j;
			}
		}
		if(vowels >= 1 && consonants >= 2){
			for(j = 0; j < l; ++j){
				printf("%c", y[j]);
			}
				printf("\n");
		}
	}while(prev_permutation(bitmask.begin(), bitmask.end()));
	return 0;
}
