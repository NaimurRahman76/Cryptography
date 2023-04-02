#include<bits/stdc++.h>
//#define int long long int
using namespace std;


int bigmod(int base,int po,int mod){

    /*if(po==0)return 1;
    int x=bigmod(base,po/2,mod);
    x=(x*x)%mod;
    if(po&1)x=(x*base)%mod;
    return x;*/
   int x=1;
   for(int i=1;i<=po;i++){
    x=(x*base)%mod;
   }
   return x;
}


int get_public(int n){

    int x=rand()%n;

    if(__gcd(x,n)==1)return x;
   else return get_public(n);
}

int get_private(int n,int mod){

    int d=2;
    while(1){
        if((d*n)%mod==1)break;
        d++;
    }
    return d;
}
int encode(int n,int key,int mod){


    int val=bigmod(n,key,mod);
    return val;
}
vector<int> encrypt(string s,int public_key,int mod){

    vector<int>ans;
    for(auto c:s){
        int32_t x=int(c);
        ans.push_back(encode(x,public_key,mod));
    }
    return ans;

}

int decode(int n,int key,int mod){

    int val=bigmod(n,key,mod);
    return val;
}

string decrypt(vector<int>v,int private_key,int mod){

    string ans="";
    for(auto c:v){

        int32_t x=decode((int)c,private_key,mod);
        ans+=char(x);
        //cout<<char(x)<<endl;
    }
    return ans;

}


int32_t main(){

    int p=31,q=29;
    int n=p*q;
    int phi=(p-1)*(q-1);
    int public_key=get_public(phi);
    int private_key=get_private(public_key,phi);
    //cout<<private_key<<' '<<n<<endl

    string msg="This is Naimur Rahman";
    vector<int>v=encrypt(msg,public_key,n);
   string ans=decrypt(v,private_key,n);
   cout<<ans<<endl;
  // cout<<bigmod(2,4,91)<<endl;
    return 0;
}
