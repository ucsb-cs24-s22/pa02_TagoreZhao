// Spring'22
// Instructor: Diba Mirza
// Student name: Tagore Zhao 
#include <iostream>
#include <string>
using namespace std;

class Movies {
    
    public:

        Movies();
        void printRating const();
        void printName const();
        void printInfo const();
        bool operator ==(const Movies& m); //only when the name and the ratings are the same
        bool operator >(const Movies& m); // first compare name then ratings
        bool operator <(const Movies& m); // first compare name then ratings

    private:
        string name;
        double rating;

        double getRating const();
        string getName const();


};