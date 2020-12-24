#include <iostream>

using namespace std;

bool glue_side(int h1, int w1, int h2, int w2, int h3, int w3){
	if(h1 == h2 && w1 + w2 == h3 && h1 + w3 == h3){
		return true;
	}
	if(w1 == h2 && h1 + w2 == h3 && w1 + w3 == h3){
		return true;
	}
	if(h1 == w2 && w1 + h2 == h3 && h1 + w3 == h3){
		return true;
	}
	if(h1 == w2 && w1 + h2 == h3 && h1 + w3 == h3){
		return true;
	}
	if(h1 == h2 && w1 + w2 == w3 && h1 + h3 == w3){
		return true;
	}
	if(w1 == h2 && h1 + w2 == w3 && w1 + h3 == w3){
		return true;
	}
	if(h1 == w2 && w1 + h2 == w3 && h1 + h3 == w3){
		return true;
	}
	if(h1 == w2 && w1 + h2 == w3 && h1 + h3 == w3){
		return true;
	}
	return false;
}

int glue_stack(int h1, int w1, int h2, int w2, int h3, int w3){
	if(h1 == h2 && h2 == h3 && w1 + w2 + w3 == h1){
		return true;
	}
	if(h1 == h2 && h2 == w3 && w1 + w2 + h3 == h1){
		return true;
	}
	if(h1 == w2 && w2 == h3 && w1 + h2 + w3 == h1){
		return true;
	}
	if(h1 == w2 && w2 == w3 && w1 + h2 + h3 == h1){
		return true;
	}
	if(w1 == h2 && h2 == h3 && h1 + w2 + w3 == w1){
		return true;
	}
	if(w1 == h2 && h2 == w3 && h1 + w2 + h3 == w1){
		return true;
	}
	if(w1 == w2 && w2 == h3 && h1 + h2 + w3 == w1){
		return true;
	}
	if(w1 == w2 && w2 == w3 && h1 + h2 + h3 == w1){
		return true;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int h1, w1, h2, w2, h3, w3;
	cin >> h1 >> w1 >> h2 >> w2 >> h3 >> w3;
	cout << (glue_side(h1, w1, h2, w2, h3, w3) || glue_side(h2, w2, h3, w3, h1, w1)
	|| glue_side(h3, w3, h1, w1, h2, w2) || glue_stack(h1, w1, h2, w2, h3, w3) ? "YES" : "NO");
	return 0;
}
