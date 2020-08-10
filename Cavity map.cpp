#include <bits/stdc++.h>

using namespace std;

// Complete the cavityMap function below.
vector<string> cavityMap(vector<string> m) {
    vector<vector<int> > x(m.size(),vector<int>(m[0].size(),0));
    for(int i=1; i<m.size()-1; i++){
        for(int j=1; j<m[i].size()-1; j++){
            bool cav=true;
            if((int)m[i-1][j]-'0' >= (int)m[i][j]-'0' or (int)m[i+1][j]-'0' >= (int)m[i][j]-'0' or (int)m[i][j-1]-'0' >= (int)m[i][j]-'0' or (int)m[i][j+1]-'0' >= (int)m[i][j]-'0'){
                cav=false;
            }
            if(cav){
                x[i][j]=1;
            }
        }
    }
    for(int i=1; i<m.size()-1; i++){
        for(int j=1; j<m[i].size()-1; j++){
            if(x[i][j]==1){
                m[i][j]='X';
            }
        }
    }
    return m;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = cavityMap(grid);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
