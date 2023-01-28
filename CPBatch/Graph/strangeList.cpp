#include<iostream>
#include<vector>
using namespace std;

#define ll long long

void calculateSum(ll n, ll x){

    ll a[n];
    ll b[n];
    for(ll i = 0; i < n; i++)
        {
            cin >> a[i];
            ll val = a[i];
            ll count = 1;
            while(val%x == 0)
            {
                val = val/x;
                count++;
            }
            
            b[i] = count;
        }
            
    ll index = 0; ll max = INT_MAX;
    for(ll i = 0; i < n; i++)
    {
        if(b[i] < max)
        {
            max = b[i];
            index = i;
        }
    }
    ll sum = 0;
    for(ll i = index; i < n; i++)
    sum += max * a[i];
    for(ll i = index-1; i >= 0; i--)
    sum += (max + 1) * a[i];
    
    cout << sum << endl;
}

int main()
{
    long long t;
    cin >> t;

    while(t){
        long long n;
        cin >> n;
        long long x;
        cin >> x;

        calculateSum(n, x);
        t--;

    }
    return 0;
}