#include <cstdio>
#include <string>

using namespace std;

int main(){
	string s = "0", tmp;
	for(int i = 1; i < 128; ++i){
		int j = i;
		tmp = "";
		while(j > 0){
			if(j % 2 == 0){
				tmp = "0" + tmp;
			}else{
				tmp = "1" + tmp;
			}
			j /= 2;
		}
		s += tmp;
	}
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%c %c %c %c %c", s[k-1], s[k-1+n], s[k-1+2*n], s[k-1+3*n], s[k-1+4*n]);
	return 0;
}
