#include <bits/stdc++.h>

using namespace std;

// Complete the encryption function below.
string encryption(string s) {
    int row=floor(sqrt(s.size()));
    int col=ceil(sqrt(s.size()));
    if(row*col<s.size()){
        row++;
    }
    vector<vector<char>> m;
    int k=0;
    for(int i=0; i<row; i++){
        vector<char> temp;
        for(int j=0; j<col; j++){
            if(k>=s.size()){
                temp.push_back('\0');
            }
            else{
                temp.push_back(s[k]);
                k++;
            }
        }
        m.push_back(temp);
        if(k==s.size()){
            break;
        }
    }
    for(int i=0; i<row; i++){
        for(int j=0; j<m[i].size(); j++){
            cout<<m[i][j]<<"    ";
        }
        cout<<endl;
    }
    string s1=""; vector<char> v;
    k=0;
    for(int i=0; i<col; i++){
        for(int j=0; j<row; j++){
            if(m[j][i]!='\0'){
                s1=s1+m[j][i];
            }
            cout<<m[j][i];
        }
        s1=s1+' ';
       
        cout<<endl;
    }
    for(int i=0; i<v.size(); i++){
        // cout<<v[i];
    }
    cout<<s1;

    return s1;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
