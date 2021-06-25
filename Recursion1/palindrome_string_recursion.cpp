#include <iostream>
using namespace std;

int length(char input[])
{
    int len = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        len++;
    }
    return len;
}
bool checkPalindrome(char input[], int start, int end)
{
    if (input[0] == '\0' || input[1] == '\0')
    {
        return true;
    }
    if (start >= end)
    {
        return true;
    }
    if (input[start] == input[end])
    {
        return checkPalindrome(input, start + 1, end - 1);
    }
    else
    {
        return false;
    }
}
bool checkPalindrome(char input[])
{
    int len = length(input);
    return checkPalindrome(input, 0, len - 1);
}
int main()
{
    char n[50];
    cin >> n;
    if (checkPalindrome(n))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}