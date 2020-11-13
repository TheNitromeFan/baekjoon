#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	vector<int> v(3, 0);
	for(int i = 0; i < t; ++i){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v[0] += a;
		v[1] += b;
		v[2] += c;
		int m = *min_element(v.begin(), v.end());
		if(m >= 30){
			printf("%d\n", m);
			v[0] -= m;
			v[1] -= m;
			v[2] -= m;
		}else{
			printf("NO\n");
		}
	}
	return 0;
}
