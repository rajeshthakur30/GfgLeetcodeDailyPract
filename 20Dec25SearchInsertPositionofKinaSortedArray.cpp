//this also can be done using this 
//  int n = arr.size();
//       int i=0;
//       for( i=0;i<n;++i){
//           if(arr[i]==k || arr[i]>k) esme agar k ke barabar ho toh ya toh agar array ka elemnet k se bara ho      example ke liye arr = [1, 3, 5, 6] k = 2
              //return i;
//       }
//       if(i==n) return i; agar koi element ho hi nhi k ke barabar toh hm last me toh usko insert kar sakte hai n ex arr = [1, 3, 5, 6] k=7 







#include<iostream>
using namespace std;

int main(){
    int arr[] = {1, 3, 5, 6};
    int k = 5;

    int n = sizeof(arr) / sizeof(arr[0]);
    int s = 0, e = n - 1;
    int ans = n;   // default insert position

    while(s <= e){
        int mid = s + (e - s) / 2;

        if(arr[mid] == k){
            cout << mid;
            return 0;
        }
        else if(arr[mid] > k){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }

    cout << ans;
    return 0;
}
