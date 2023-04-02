#include<bits/stdc++.h>
using namespace std;

string words[]={"SCIENCE","REVOULATION","LIFE","OF","PART","OUR","MANY","SECTORS","BECAUSE","RESULT","HAS","AN","IN","BECOME","EASY","HELP","PEOPLE","BY","NO","IS","ARE","INTEREST","HAVE","INVENTION","FINO","THE","GENERAL","LIMIT","ALL"};

int bigmod(int base,int po,int mod){

    if(po==0)return 1;
    int x=bigmod(base,po/2,mod);
    x=(x*x)%mod;
    if(po&1)x=(x*base)%mod;
    return x;
}

string encrypt(string s,int key,int mod){

   string ans="";
    for(auto c:s){
        int x=int(c)-65;
        x=(x*key)%mod;
        ans+=char(x+65);
    }
    return ans;
}
bool find_pattern(string s){

    string tem="";
    tem+=s[0];
    for(int i=1;i<s.size();i++){
        tem+=s[i];
        for(auto c:words){
               // cout<<tem<<' '<<c<<endl;
            if(tem==c)return true;
        }
    }
    return false;
}
string decrypt(string s){

    for(int i=1;i<26;i++){
        if(__gcd(i,26)==1){

            int inv_mod=bigmod(i,11,26);
            string temp=encrypt(s,inv_mod,26);
            if(find_pattern(temp))return temp;
        }
    }
    return "NO Pattern found";
}

int32_t main(){

    //string msg="PARTYHASESTARTED";
    //cout<<"Plain Text ="<<msg<<endl;
    cout<<"Please enter Cipher text"<<endl;
    string chi_msg;
    cin>>chi_msg;
    string dec_msg=decrypt(chi_msg);
    //string chi_msg=encrypt(msg,7,26);
    cout<<"Cipher_text ="<<chi_msg<<endl;
    cout<<"Decrypted_msg ="<<dec_msg<<endl;
    return 0;
}
