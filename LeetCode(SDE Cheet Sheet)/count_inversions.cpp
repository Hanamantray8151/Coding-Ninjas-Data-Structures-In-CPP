//T.C : O(n^2).
//S.C : O(1).
long long int inversionCount(long long a[], long long n)
{
    int invCount = 0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i] > a[j]){
                invCount++;
            }
        }
    }
    return invCount;
}
