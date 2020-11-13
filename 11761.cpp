#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int shuffles(int len, bool out){
	vector<int> v(len, 0);
	for(int idx = 0; idx < len; ++idx){
		v[idx] = idx;
	}
	int ret = 0;
	vector<int> w = v;
	do{
		++ret;
		int i = 0, j = 0;
		if(out){
			j = (len % 2 == 0) ? len / 2 : len / 2 + 1;
		}else{
			i = len / 2;
		}
		vector<int> tmp = w;
		for(int idx = 0; idx < len; ++idx){
			if(idx % 2 == 0){
				w[idx] = tmp[i];
				++i;
			}else{
				w[idx] = tmp[j];
				++j;
			}
		}
	}while(!equal(v.begin(), v.end(), w.begin()));
	return ret;
}

int main(){
	int n;
	char type[4];
	scanf("%d %s", &n, type);
	printf("%d", shuffles(n, type[0] == 'o'));
	return 0;
}
