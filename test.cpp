#include "movies.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <iomanip>
#include <set>
#include <queue>
using namespace std;

int main(){
    Movies m1,m2;
    m1 = Movies("ace ventura: when nature calls",6.1);
    m2 = Movies("balto",7.1);
    m1.printInfo();
    cout<<endl;
    m2.printInfo();
    cout<<endl;

    if (m1<m2){
        cout <<"m1 < m2"<< endl;
    }else{
        cout <<"false"<< endl;
    }
    if (m1 == m1){
        cout <<"m1 == m1"<<endl;
    }else{
        return false;
    }
    cout<<endl;
    
    return 0;
}