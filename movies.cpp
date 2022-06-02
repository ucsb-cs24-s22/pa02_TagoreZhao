// Spring'22
// Instructor: Diba Mirza
// Student name: Tagore Zhao 
#include "movies.h"
#include <string>
#include <iostream>
using namespace std;


Movies:: Movies (){
    name = "N";
    rating = 0.0;
}
Movies:: Movies(string n ,double r){
    changeName(n);
    changeRating(r);
}
Movies::Movies(const Movies& m){
    name = m.getName();
    rating = m.getRating();
}
Movies& Movies::operator=(const Movies& m){
    changeName(m.getName());
    changeRating(m.getRating());
    return *this; 

} 
/*Movies:: Movies(string info){
    int index = info.find(',');
    name = info.substr(0,index+1);
    rating = stod(info.substr(index));
}*/
void Movies::changeRating (double r){
    rating = r;
}
void Movies::changeName (string n){
    name = n;
}
double Movies::getRating ()const{
    return rating;
}
string Movies::getName ()const{
    return name;
}
void Movies::printRating ()const{
    cout << rating;
}
void Movies::printName ()const{
    cout << name;
}
void Movies::printInfo ()const{
    cout << name <<", "<<rating;
}
bool Movies::operator ==(const Movies& m)const{
    return (name == m.getName());
}
bool Movies::operator >(const Movies& m)const{
    if (name > m.getName()){
        return true;
    }
    if (name == m.getName()){
        if (rating > m.getRating()){
            return true;
        }
    }
    return false;
}
bool Movies::operator <(const Movies& m)const{
    if (name < m.getName()){
        return true;
    }
    if (name == m.getName()){
        if (rating < m.getRating()){
            return true;
        }
    }
    return false;
}




M::M(){
    name = "N";
    rating = 0.0;
}
M::M(string n ,double r){
    changeName(n);
    changeRating(r);
}
void M::changeRating (double r){
    rating = r;
}
void M::changeName (string n){
    name = n;
}
double M::getRating ()const{
    return rating;
}
string M::getName ()const{
    return name;
}
M& M::equal (const Movies& m){
    changeName(m.getName());
    changeRating(m.getRating());
    return *this;
}
M& M::equal (const M& m) {
    changeName(m.getName());
    changeRating(m.getRating());
    return *this;
}
bool M::operator >(const M& m) const{
    return (rating<m.getRating());
}
bool M::operator <(const M& m) const{
    return (rating>m.getRating());
}
void M::printRating ()const{
    cout << rating;
}
void M::printName ()const{
    cout << name;
}
void M::printInfo ()const{
    cout << name <<", "<<rating;
}