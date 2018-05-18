#include<iostream>
#include<algorithm>
#include<stack>
#include<string>
#include<vector>

using namespace std;
int main()
{
    int minH = 1;
    long int maxI = 1000000;
    int num;
    cin>>num;
    vector<int> arr;
    for(int i=0;i<num;i++){
        cin>>arr[i];
    }
    int maxi = 0;
    int myHealth=100;
    long int myInjury = 1;
    vector<int> maxpos;
    for(int i=0;i<num;i++){
        if(i==0){
            int j = i;
            while(myHealth>minH && myInjury<maxI){
                myHealth -= arr[j];
                myInjury *= arr[j];
                maxi++;
                j++;
            }
            maxpos.push_back(i);
        }
        else{
            myHealth += arr[i-1];
            myInjury /= arr[i-1];
            maxi -= 1;
            int j = i+maxi;
            int counti = 0;
            while(myHealth > minH && myInjury < maxI){
                myHealth -= arr[j];
                myInjury *= arr[j];
                maxi++;
                j++;
                counti++;
            }
            if(counti == 1){
                maxpos.push_back(i);
            }else{
                maxpos.clear();
                maxpos.push_back(i);
            }

        }
    }
    cout<<maxpos[0];

}
