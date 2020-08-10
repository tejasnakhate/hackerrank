#include <bits/stdc++.h>

using namespace std;

// Complete the stones function below.
vector<int> stones(int n, int a, int b) {
    // vector<vector<int> > v(n+1, vector<int>(pow(2,n),-1));
    // v[0][0]=0;
    set<int> s1,s2; s1.insert(0);
    for(int i=1; i<n; i++){
        for(auto it=s1.begin(); it!=s1.end(); it++){
            int p=*it+a, q=*it+b;
            s2.insert(p); s2.insert(q);
        }
        s1=s2;
        s2.clear();
    }
    vector<int> ret;
    for(auto it=s1.begin(); it!=s1.end(); it++){
        ret.push_back(*it);
    }
    sort(ret.begin(),ret.end());
    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int a;
        cin >> a;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int b;
        cin >> b;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = stones(n, a, b);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}
