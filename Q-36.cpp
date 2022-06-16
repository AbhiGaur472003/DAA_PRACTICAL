// III. Given a string of characters, design an algorithm and implement it using a program to print all
// possible permutations of the string in lexicographic order.

#include<bits/stdc++.h>
using namespace std;

void Permutation(string s,int l,int h){
    if(l==h){
        cout<<s<<endl;
    }

    for(int i=l;i<=h;i++){
        swap(s[l],s[i]);
        Permutation(s,l+1,h);
        swap(s[l],s[i]);
    }
}
int main(){
    int n;
    cout<<"Enter the size: ";
    cin>>n;

    string s;
    cout<<"Enter the string: ";
    cin>>s;

    sort(s.begin(),s.end());

    Permutation(s,0,n-1);

}