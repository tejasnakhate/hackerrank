#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the surfaceArea function below.
int surfaceArea(vector<vector<int>> s) {
    if(s.size()==1 and s[0].size()==1){
        return s[0][0]*4+2;
    }
    if(s[0].size()==1){
        int ans=2*s.size();
        for(int i=0; i<s.size(); i++){
            ans+=s[i][0]*2;
        }
        for(int i=1; i<s.size(); i++){
            ans+=abs(s[i][0]-s[i-1][0]);
        }
        return ans+=s[0][0]+s[s.size()-1][0];
    }
    int area=0;
    area=s.size()*s[0].size()*2;
    cout<<"top and bottom: "<<area<<endl;
    int temp=0;
    for(int i=0; i<s.size(); i++){
        temp+=s[i][0];
        temp+=s[i][s[i].size()-1];
    }
    for(int j=1; j<s[0].size()-1; j++){
        temp+=s[0][j];
        temp+=s[s.size()-1][j];
    }
    temp+=s[0][0]+s[0][s[0].size()-1]+s[s.size()-1][0]+s[s.size()-1][s[0].size()-1];
    cout<<"edges: "<<temp<<endl;
    int temp2=temp; temp=0;
    for(int j=0; j<s[0].size(); j++){
        for(int i=1; i<s.size(); i++){
            temp+=abs(s[i][j]-s[i-1][j]);
        }
    }
    for(int i=0; i<s.size(); i++){
        for(int j=1; j<s[0].size(); j++){
            temp+=abs(s[i][j]-s[i][j-1]);
        }
    }
    cout<<"rest: "<<temp<<endl;
    return area+temp+temp2;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string HW_temp;
    getline(cin, HW_temp);

    vector<string> HW = split_string(HW_temp);

    int H = stoi(HW[0]);

    int W = stoi(HW[1]);

    vector<vector<int>> A(H);
    for (int i = 0; i < H; i++) {
        A[i].resize(W);

        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = surfaceArea(A);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
