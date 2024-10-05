//
// Created by vli15 on 10/4/2024.
//
#include <iostream>
#include "analyzer.h"
#include <string>
#include <list>
#include <vector>
#include <chrono>
#include "StringData.h"
using namespace std;


int binary_search(vector<string>& container, string element) {
    int middle = container.size()/2; //middle index
    int high = container.size()-1;
    int low = 0;
    while(low <= high){
        if (container[middle] == element) {
            return middle;
        }
        else if( container[middle] < element) //the element is to the right of the middle value
        {
            low = middle + 1;
            middle = (high + low)/2;
        }
        else //element is to the left of the middle value
        {
            high = middle - 1;
            middle = (high + low)/2;
        }
    }
    return -1;
}

int linear_search(vector<string>& container, string element) {
    for(int i=0; i< container.size(); i++) {
        if (container[i] == element)
            return i;
    }
    return -1;
}

int main() {
    string mylist[3] = { "mzzzz", "not_here", "aaaaa" };
   vector<string> dataset =  getStringData();
   for (string word: mylist) {
       auto starttimeL =  chrono::system_clock::now() ;
       int linear = linear_search(dataset, word);
       auto endtimeL = chrono::system_clock::now();
       cout<<"Linear time for "<<word<<" is: "<<endtimeL - starttimeL<<endl;
      cout<<"Index: "<< linear<<endl;
      auto starttimeB = chrono::system_clock::now();
      int binary = binary_search(dataset, word);
      auto endtimeB = chrono::system_clock::now();
      cout<<"Binary time for "<< word<<" is: "<<endtimeB - starttimeB<<endl;
       cout<<"Index: "<< binary<<endl;
       cout<<endl;
   }
    // cout<<"hello world";
    return 0;
}