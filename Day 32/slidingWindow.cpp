#include<iostream>

int main(){
    //let's say we have vector/arr of 10 queries 
    std::vector<int> arr=  {1,2,3,4,5,6,7,8,9,10};
    int n= 10;//size of arr/vector


    //let's say we have a sliding window of 3;
    int k = 3;

    //To Code sliding window

    //Step 1: Create a Sum Variable To Store First K 
    int sum{0};
    for(int i=0;i<k;i++){
        sum = sum+ arr[i];
    }
    std::cout<<"Sum : "<<sum<<"\n";

    //Step 2: Now Start From K Till End and Add The New Element and Remove The First Element
    for(int i=k;i<n;i++){
        //1.Add the new Element
        sum = sum+ arr[i];
        //2.Remove The Old Element
        sum = sum - arr[i-k];//played with indices dry run to understand better
        //Printing For Your Understanding(Avoid using)
        std::cout<<"Sum : "<<sum<<"\n";
    }

    return 0;
}