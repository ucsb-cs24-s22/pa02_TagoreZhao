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
        double getRating ()const;
        string getName ()const;

    private:
        string name;
        double rating;

        void changeRating (double r);
        void changeName (string n);


};

class M{
    public:
    M();
    M(string n ,double r);
    void printRating ()const;
    void printName ()const;
    void printInfo ()const;
    M& equal (const Movies& m);
    M& equal(const M& m);
    bool operator ==(const M& m)const;
    bool operator >(const M& m) const;
    bool operator <(const M& m) const;
    double getRating ()const;
    string getName ()const;
    private:
    string name;
    double rating;
    void changeRating (double r);
    void changeName (string n);
};

#endif
