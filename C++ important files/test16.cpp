#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    int n;
    cin>>n;
    string s[10];
    for(int i=0;i<n;i++)
        cin>>s[i];
    for(int i=0;i<n;i++)
    {
        for(int j = 0 ; j <s[i].size();j+=2){
                cout << s[i][j] ;
        }
        cout << " ";
        for(int j = 1; j <s[i].size(); j+=2){
                  cout << s[i][j];
        }
        if(i!=(n-1))
        cout<<endl;
    }
    return 0;
}
