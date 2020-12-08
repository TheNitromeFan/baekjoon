#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int c, p;
	cin >> c >> p;
	int h[100];
	for(int i = 0; i < c; ++i){
		cin >> h[i];
	}
	int ans = 0;
	if(p == 1){
		ans += c;
		for(int i = 0; i + 3 < c; ++i){
			if(h[i] == h[i + 1] && h[i] == h[i + 2] && h[i] == h[i + 3]){
				++ans;
			}
		}
	}else if(p == 2){
		for(int i = 0; i + 1 < c; ++i){
			if(h[i] == h[i + 1]){
				++ans;
			}
		}
	}else if(p == 3){
		for(int i = 0; i + 2 < c; ++i){
			if(h[i] == h[i + 1] && h[i] + 1 == h[i + 2]){
				++ans;
			}
		}
		for(int i = 0; i + 1 < c; ++i){
			if(h[i] == h[i + 1] + 1){
				++ans;
			}
		}
	}else if(p == 4){
		for(int i = 0; i + 2 < c; ++i){
			if(h[i] == h[i + 1] + 1 && h[i] == h[i + 2] + 1){
				++ans;
			}
		}
		for(int i = 0; i + 1 < c; ++i){
			if(h[i] + 1 == h[i + 1]){
				++ans;
			}
		}
	}else if(p == 5){
		for(int i = 0; i + 2 < c; ++i){
			if(h[i] == h[i + 1] && h[i] == h[i + 2]){
				++ans;
			}
		}
		for(int i = 0; i + 1 < c; ++i){
			if(h[i] == h[i + 1] + 1){
				++ans;
			}
		}
		for(int i = 0; i + 1 < c; ++i){
			if(h[i] + 1 == h[i + 1]){
				++ans;
			}
		}
		for(int i = 0; i + 2 < c; ++i){
			if(h[i] == h[i + 1] + 1 && h[i] == h[i + 2]){
				++ans;
			}
		}
	}else if(p == 6){
		for(int i = 0; i + 2 < c; ++i){
			if(h[i] == h[i + 1] && h[i] == h[i + 2]){
				++ans;
			}
		}
		for(int i = 0; i + 1 < c; ++i){
			if(h[i] == h[i + 1]){
				++ans;
			}
		}
		for(int i = 0; i + 2 < c; ++i){
			if(h[i] + 1 == h[i + 1] && h[i] + 1 == h[i + 2]){
				++ans;
			}
		}
		for(int i = 0; i + 1 < c; ++i){
			if(h[i] == h[i + 1] + 2){
				++ans;
			}
		}
	}else if(p == 7){
		for(int i = 0; i + 2 < c; ++i){
			if(h[i] == h[i + 1] && h[i] == h[i + 2]){
				++ans;
			}
		}
		for(int i = 0; i + 1 < c; ++i){
			if(h[i] == h[i + 1]){
				++ans;
			}
		}
		for(int i = 0; i + 2 < c; ++i){
			if(h[i] == h[i + 1] && h[i] == h[i + 2] + 1){
				++ans;
			}
		}
		for(int i = 0; i + 1 < c; ++i){
			if(h[i] + 2 == h[i + 1]){
				++ans;
			}
		}
	}
	cout << ans;
	return 0;
}
