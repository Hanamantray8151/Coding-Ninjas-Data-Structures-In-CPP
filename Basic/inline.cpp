#include <iostream>
using namespace std;

inline int max(int x, int y)
{
    return (x > y) ? x : y;
}
int main(){
    int x=10,y=20;
    cout<<max(x,y)<<endl;

    int a,b;
    cin>>a>>b;
    cout<<max(a,b)<<endl;

    return 0;
}