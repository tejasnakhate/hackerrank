#include <bits/stdc++.h>

using namespace std;

// Complete the strangeCounter function below.
long strangeCounter(long t) {
    long temp=0, cyc=3;
    while(temp+cyc<t){
        temp+=cyc;
        cyc*=2;
    }
    while(temp!=t){
        temp++;
        cyc--;
    }
    return ++cyc;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    long t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = strangeCounter(t);

    fout << result << "\n";

    fout.close();

    return 0;
}
