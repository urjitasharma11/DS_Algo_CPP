#include<bits/stdc++.h>

using namespace std;

void print( int arr[] , int n)
{
    for( int i = 0 ; i < n ; i++)
   {
       cout << arr[i] << " ";
   }
}

void reverse1 ( int arr[] , int d , int n)
{
    int temp=0;

    while(d<n)
    {
        temp = arr[d];
        arr[d]  = arr[n];
        arr[n] = temp;
        d++;
        n--;
    }

}

void rotation ( int arr[] , int d , int n)
{
   if ( d == 0)
        return;
   else
   {
       reverse1 (arr , 0 , d-1);
       reverse1 (arr , d , n-1);
       reverse1 (arr , 0 , n-1);
   }
   print(arr, n);
}

int main()
{
    int i,n,d ,arr[100];
    cin >> d >> n;
    for(i = 0 ; i < n ; i++)
    {
        cin >> arr[i];
    }
    rotation(arr , d , n) ;
}
