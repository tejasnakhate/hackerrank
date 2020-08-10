#include <bits/stdc++.h>

using namespace std;
const int mod=1000000007;
// Complete the substrings function below.
int substrings(string s) {

    int n=s.size();
    vector<long> a(n),b(n);
    a[0]=1;b[0]=1;
    for(int i=1; i<n; i++){
        a[i]=(10*a[i-1])%mod;
        b[i]=(b[i-1]+a[i])%mod;
        
    }
    for(int i=0; i<n; i++){
        cout<<a[i]<<"   ";
    }
    cout<<endl;
    for(int i=0; i<n; i++){
        cout<<b[i]<<"   ";
    }
    long ans =0;
    for(int i=0; i<n; i++){
        ans+=((s[i]-'0')*b[n-i-1]*(i+1))%mod;
    }
    cout<<ans;
    return ans%mod;
    /*vector<int> v;
    int p=stoi(n);
    while(p!=0){
        int i=p%10;
        v.push_back(i);
        p/=10;
    }
    reverse(v.begin(),v.end());
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<"   ";
    }cout<<endl;
    long long ans=0LL;
     
    vector<long long> dp(v.size());
    /*
    dp.push_back(v[0]);
    long long ans=dp[0];
    for(int i=1; i<v.size(); i++){
        for(auto it=dp.begin(); it!=dp.end(); it++){
            *it=(*it)*10;
        }
        dp.push_back(v[i]);
        for(auto it=dp.begin(); it!=dp.end(); it++){
            ans+=(*it);
        }
    }
    cout<<"hi"<<ans;
    return ans%mod;
    // int n=v.size();
    for(int i=0; i<v.size(); i++){
        dp[i]=(i+1)*pow(10,i)*v[i];
    }
    for(int i=0; i<dp.size(); i++){
        ans+=dp[i];
        cout<<dp[i]<<"  ";
    }
    return ans;*/
    return 1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n;
    getline(cin, n);

    int result = substrings(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
