#include <iostream>
#include <iomanip>

using namespace std;

void helloworld(long long n){
	for(int h = 1; h <= 9; ++h){
		for(int e = 0; e <= 9; ++e){
			if(e == h){
				continue;
			}
			for(int l = 0; l <= 9; ++l){
				if(l == h || l == e){
					continue;
				}
				for(int o = 0; o <= 9; ++o){
					if(o == h || o == e || o == l){
						continue;
					}
					for(int w = 1; w <= 9; ++w){
						if(w == h || w == e || w == l || w == o){
							continue;
						}
						for(int r = 0; r <= 9; ++r){
							if(r == h || r == e || r == l || r == o || r == w){
								continue;
							}
							for(int d = 0; d <= 9; ++d){
								if(d == h || d == e || d == l || d == o || d == w || d == r){
									continue;
								}
								if(10000 * h + 1000 * e + 100 * l + 10 * l + o
								+ 10000 * w + 1000 * o + 100 * r + 10 * l + d == n){
									cout << "  " << h << e << l << l << o << "\n+ " << w << o << r << l << d
									<< "\n-------\n";
									cout << right << setw(7) << n;
									return;
								}
							}
						}
					}
				}
			}
		}
	}
	cout << "No Answer";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	cin >> n;
	helloworld(n);
	return 0;
}
