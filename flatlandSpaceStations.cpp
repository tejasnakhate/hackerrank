#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the flatlandSpaceStations function below.
int flatlandSpaceStations(int n, vector<int> c) {
    if(n==c.size()){
        return 0;
    }
    vector<int> v;
    sort(c.begin(),c.end());
    for(int i=0; i<n; i++){
        v.push_back(i);
    }
    int ans=0;
    if(c[0]>0){
        for(int i=0; i<c[0]; i++){
            ans=max(ans,abs(v[i]-c[0]));
        }
    }
    for(int j=0; j<c.size()-1; j++){
        for(int i=c[j]; i<c[j+1]; i++){
            ans=max(ans,min(abs(v[i]-c[j]),abs(v[i]-c[j+1])));
        }
    }
    if(c[c.size()-1]<(n-1)){
        for(int i=c[c.size()-1]; i<v.size(); i++){
            ans=max(ans,abs(v[i]-c[c.size()-1]));
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(m);

    for (int i = 0; i < m; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = flatlandSpaceStations(n, c);

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
