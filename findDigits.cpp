#include <bits/stdc++.h>

using namespace std;

// Complete the findDigits function below.
int findDigits(int n) {
    vector<int> d;
    int temp=n;
    while(temp!=0){
        int a=temp%10;
        d.push_back(a);
        temp/=10;
    }
    int ans=0;
    for(int i=0; i<d.size(); i++){
        if(d[i]==0){
            continue;
        }
        else{
            if(n%d[i]==0){
                ans++;
            }
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = findDigits(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
