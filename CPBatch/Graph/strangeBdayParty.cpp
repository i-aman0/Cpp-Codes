#include <iostream>
using namespace std;

#define ll long long

void merge(ll array[], ll const left, ll const mid, ll const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
 
    auto *leftArray = new ll[subArrayOne], *rightArray = new ll[subArrayTwo];

    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];

    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0; 
    ll indexOfMergedArray = left; 
 
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
 
void sort(ll array[], ll const begin, ll const end)
{
    if (begin >= end)
        return; 
 
    auto mid = begin + (end - begin) / 2;
    sort(array, begin, mid);
    sort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

int main()
{
    long long a[300010];
    long long b[300010];
    long long t, n, m;
    cin >> t;
    while (t--){
        cin >> n >> m;
        long long sum = 0;

        for(long long i = 0; i < n; i++){
            cin >> a[i];
        }

        for(long long i = 1; i <=m; i++){
            cin >> b[i];
        }

        sort(a, 0, n-1);

        ll curr = 1;

        for(ll i = n - 1; i >= 0; i--){
            if(b[a[i]] > b[curr] && curr <= m){
                sum += b[curr++];
            }
            else{
                sum += b[a[i]];
            }
        }
        cout << sum << endl;
    }

    return 0;
}