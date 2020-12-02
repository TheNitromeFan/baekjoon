#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int M,Q;
int u[30];
double p[30][4];
typedef struct{
    double x;
    int q[30];
} ss;
struct cmp{
    bool operator()(ss a, ss b){
        if(a.x != b.x) return a.x < b.x;
        for(int i=0;i<Q;i++){
            if(a.q[i] != b.q[i]) return a.q[i] < b.q[i];
        }
        return 0;
    }
};
ss makess(int* l){
    ss ret;
    ret.x=1.;
    for(int i=0;i<Q;i++){
        ret.q[i] = l[i];
        ret.x *= p[i][l[i]];
    }
    return ret;
}
priority_queue<ss,vector<ss>,cmp> pq;
ss temp, prv;
int main(){
    int T,t;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        scanf("%d%d",&M,&Q);
        pq = priority_queue<ss,vector<ss>,cmp>();
        for(int i=0;i<Q;i++){
            for(int j=0;j<4;j++) scanf("%lf",&p[i][j]);
            sort(p[i],p[i]+4,greater<double>());
        }
        for(int i=0;i<Q;i++) u[i] = 0;
        pq.push(makess(u));
        if(Q < 10 && M >= (1 << (2*Q))){
            printf("Case #%d: 1.00000000\n",t);
        }
        else{
            double ans = 0.0;
            for(int i=0;i<M;i++){
                temp = pq.top();
                pq.pop();
                if(i != 0){
                    int j;
                    for(j=0;j<Q;j++){
                        if(prv.q[j] != temp.q[j]) break;
                    }
                    if(j==Q){
                        i--;
                        continue;
                    }
                }
                ans += temp.x;
                for(int j=0;j<Q;j++){
                    u[j] = temp.q[j];
                }
                for(int j=0;j<Q;j++){
                    if(u[j] < 3){
                        u[j]++;
                        pq.push(makess(u));
                        u[j]--;
                    }
                }
            }
            printf("Case #%d: %.8lf\n",t,ans);
        }
    }
}

