#include<iostream>
#include <climits>
using namespace std;
int getMin(int arr[],int n){
    
    int min=INT_MAX;//yaha hm ye max issiliye liye hai ki maan liye int min ka jo value hai wo sabse jaida hai and phir usko ek ek element se compare karbayenge agar wo esse chota rahega toh wo return kar denge
    
    for(int i=0;i<n;i++){
    if(arr[i]<min){
        min=arr[i];
    }
    }
    return min;
}
int getMax(int arr[],int n){
    
    int max=INT_MIN;
    
    for(int i=0;i<n;i++){
    if(arr[i]>max){
        max=arr[i];
    }
    }
    return max;
}   
int main(){
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    
    int arr[100];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Minimum value is:"<<getMin(arr,n)<<endl;
    cout<<"Maximum value is: "<<getMax(arr,n)<<endl;

}