#include <iostream>
#include <vector>
#include <math.h>
 
using namespace std;
typedef long long int lli;
 
lli n,d,q,x,y,N;
vector<lli>arbol;
 
void inicializa(int n){
    int pot=log2(n);
    if(n!=pow(2,pot)){
        pot++;
    }
    N=pow(2,pot);
    arbol.resize(2*N,0);
}
 
void actualiza(int i,int dato){
    int j=N+i;
    arbol[j]=dato;
    j/=2;
    while(j>0){
        arbol[j]=(arbol[2*j]+arbol[2*j+1]);
        j/=2;
    }
}
 
lli suma(int a,int b){
    a+=N,b+=N;
    lli sum=0;
    while(a<=b){
        if(a%2==1){
            sum+=arbol[a++];
        }
        if(b%2==0){
            sum+=arbol[b--];
        }
        a/=2,b/=2;
    }
    return sum;
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    cin>>n>>q;
    inicializa(n);
    for(int i=1;i<=n;i++){
        cin>>d;
        actualiza(i,d);
    }
    while(q-->0){
        int id;
        cin>>id>>x>>y;
        if(id==1){
            actualiza(x,y);
        }
        else{
            cout<<suma(x,y)<<"\n";
        }
    }
 
    return 0;
}
