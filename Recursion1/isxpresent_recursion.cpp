#include <iostream>
using namespace std;

bool checkNumber(int input[], int size, int x)
{
    if(size==0){
        return false;
    }
    if(x==input[0]){
        return true;
    }
    bool output = checkNumber(input+1,size-1,x);
    return output;
}
int main()
{
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    int x;

    cin >> x;

    if (checkNumber(input, n, x))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}