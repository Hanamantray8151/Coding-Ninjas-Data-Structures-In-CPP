#include <iostream>
using namespace std;

int main()
{
    int n;
    int *p = new int[50];
    cout << "Enter Number Of Elements" << endl;
    cin >> n;

    int *pa = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> pa[i];
    }

    int max = -1;
    for (int i = 0; i < n; i++)
    {
        if (max < pa[i])
        {
            max = pa[i];
        }
    }
    cout<<max<<endl;
    delete [] p;

    return 0;
}