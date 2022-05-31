// Spring'22
// Instructor: Diba Mirza
// Student name: Tagore Zhao 
#ifndef MOVIES_H
#define MOVIES_H
#include <iostream>
#include <string>
using namespace std;

class Movies {
    
    public:

        Movies();
        Movies(string n ,double r);
//        Movies(string info); 
        void printRating ()const;
        void printName ()const;
        void printInfo ()const;
        bool operator ==(const Movies& m)const; //only when the name and the ratings are the same
        bool operator >(const Movies& m)const; // first compare name then ratings
        bool operator <(const Movies& m)const; // first compare name then ratings
        Movies(const Movies& m);
        Movies& operator=(const Movies& m); 
        //need a copy constructor

    private:
        string name;
        double rating;

        double getRating ()const;
        string getName ()const;
        void changeRating (double r);
        void changeName (string n);


};

#endif
