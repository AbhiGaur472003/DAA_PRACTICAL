// I. Given a number n, write an algorithm and a program to find nth ugly number. Ugly numbers are
// those numbers whose only prime factors are 2, 3 or 5. The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12,
// 15, 16, 18, 20, 24,. is sequence of ugly numbers.

#include<bits/stdc++.h>
using namespace std;

int FindUglyNumber(int n){
    int ugly[n];
    int i2=0,i3=0,i5=0;
    int m2=2,m3=3,m5=5;
    int ans=1;

    ugly[0]=0;
    for(int i=1;i<n;i++){
        ans=min(m2,min(m3,m5));
        ugly[i]=ans;

        if(ans==m2){
            i2+=1;
            m2=ugly[i2]*2;
        }
        if(ans==m3){
            i3+=1;
            m3=ugly[i3]*3;
        }
        if(ans==m5){
            i5+=1;
            m5=ugly[i5]*5;
        }
    }

    return ans;
}
int main(){
    int n;
    cout<<"Enter the value: ";
    cin>>n;

    cout<<"Nth Ugly Number : "<<FindUglyNumber(n)<<endl;
}