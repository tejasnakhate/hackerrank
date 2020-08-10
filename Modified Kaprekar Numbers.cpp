#include <bits/stdc++.h>

using namespace std;

// Complete the kaprekarNumbers function below.
void kaprekarNumbers(int p, int q) {
    long int sq,len,l,r;
    string s1,s2,s;
    bool flag=false;
    for(int i=p;i<=q;i++)
    {
        len=to_string(i).length();
        sq=pow(i,2);
        s=to_string(sq);
        reverse(s.begin(),s.end());
        s1=s.substr(0,len);
        s2=s.substr(len,s.length()-len);
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        r=stoi(s1);
        
        if(s2.length()==0){
            if(r==i){
                flag=true;
                cout<<i<<" ";
            }
        }
        else{
            l=stoi(s2);
            if(l!=0 && l+r==i)
            {
                flag=true;
                cout<<i<<" ";
            }
        }
    }
    if(!flag)
            cout<<"INVALID RANGE";

}

int main()
{
    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    kaprekarNumbers(p, q);

    return 0;
}
