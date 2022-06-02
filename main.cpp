// Spring'22
// Instructor: Diba Mirza
// Student name: Tagore Zhao 
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
#include <iterator>
using namespace std;


bool parseLine(string &line, string &movieName, double &movieRating);

int main(int argc, char** argv){
    if (argc < 2){
        cerr << "Not enough arguments provided (need at least 1 argument)." << endl;
        cerr << "Usage: " << argv[ 0 ] << " filename prefix1 prefix2 ... prefix n " << endl;
        exit(1);
    }

    ifstream movieFile (argv[1]);
 
    if (movieFile.fail()){
        cerr << "Could not open file " << argv[1];
        exit(1);
    }
//Part 1  
  // Create an object of a STL data-structure to store all the movies
  set<Movies> m;

  string line, movieName;
  double movieRating;
  // Read each file and store the name and rating
  while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){
        // Use std::string movieName and double movieRating
        // to construct your Movie objects
        // cout << movieName << " has rating " << movieRating << endl;
        // insert elements into your data structure
        Movies m1 = Movies(movieName,movieRating);
        m.insert(m1);

  }

  movieFile.close();
  if (argc == 2){
        //print all the movies in ascending alphabetical order of movie names
            for (auto item : m){
            item.printInfo();
            cout << endl;
        }
        return 0;
  }

//Part 2
if (argc > 2){
    int numBest;
    queue<M> bestMovies;
    queue<string> prefix;
    for(int i=2; i<argc; i++){
        prefix.push(argv[i]);
    }
    for (int i=2; i<argc; i++){
        set<M> preMovies;
        string pf = argv[i];
//        cout <<"prefix: "<<pf<<endl;
        for (auto movie: m){
            string name = movie.getName();
            Movies c = movie;
            if(name.substr(0,pf.length()) == pf){
                M r;
                r.equal(c);
                preMovies.insert(r);
//                cout << "insert: "<< c.getName()<<endl;
            }
        }
//        cout << endl << "print premovies: "<<endl;
        if(preMovies.empty()){
            cout << "No movies found with prefix "<<pf << endl << endl;
        }else{
            for (auto item : preMovies){
                item.printInfo();
                cout << endl;
            }
            cout<<endl;
            M o;
            o.equal(*(preMovies.begin()));
            bestMovies.push(o);
        }
    }
    for (int i = 0; i<numBest; i++){
        if(bestMovies.empty()){
        return 0;
    }
        M b;
        b.equal( bestMovies.front());
        string a = prefix.front();        
        bestMovies.pop();
        prefix.pop();
        cout << "Best movie with prefix " << a << " is: " << b.getName() << " with rating " << std::fixed << std::setprecision(1) << b.getRating() << endl;
    }

/*
  if (argc > 2){
    string pf;
    set<string> prefix;
    set<Movies> preMovies;
    for(int i=2; i<argc; i++){
        prefix.insert(argv[i]);
    }
    


    while(getline(cin,pf)){
        cout << pf << endl;
        prefix.insert(pf);
    }

    cout << " all movies: "<<endl;
    for (auto item : m){
            item.printInfo();
            cout << endl;
        }
    cout <<endl<< "start insersion:"<<endl;
    for(auto p: prefix){
        cout <<"prefix: "<<p<<endl;
        for (auto movie: m){
            string name = movie.getName();
            Movies c = movie;
            if(name.substr(0,p.length()) == p){
                preMovies.insert(c);
                cout << "insert: "<< c.getName()<<endl;
            }
        }
    }
    cout << endl << "print premovies: ";
    for (auto item : preMovies){
            item.printInfo();
            cout << endl;
        }
    


*/
/*
    for (auto p: prefix){
        for (auto n: name){
            cout <<"prefix: "<<p<<" ";
            cout <<"substr: "<< n.substr(0,p.length()) << endl;
            if (n.substr(0,p.length()) == p){
            Movies t = Movies(n,0.0);
            m.find(t);
            Movies s = *(m.find(t));
            //preMovies.insert(s);
            s.printName();
            //preMovies.insert(*(m.find(Movies(n,0.0))));
            cout<<"insert an item"<< endl;
            }
        }
    }
*/
/*
    cout << endl;
    cout <<"Movies with Prefix:"<<endl;
    for (auto item : preMovies){
            item.printInfo();
            cout << endl;
        }
    Movies max = *(preMovies.cend());*
/*
  //  For each prefix,
  //  Find all movies that have that prefix and store them in an appropriate data structure
  //  If no movie with that prefix exists print the following message
  cout << "No movies found with prefix "<<"<replace with prefix>" << endl << endl;

  //  For each prefix,
  //  Print the highest rated movie with that prefix if it exists.
  cout << "Best movie with prefix " << "<replace with prefix>" << " is: " << "replace with movie name" << " with rating " << std::fixed << std::setprecision(1) << "replace with movie rating" << endl;
*/
  return 0;
  }


/* Add your run time analysis for part 3 of the assignment here as commented block*/

}
bool parseLine(string &line, string &movieName, double &movieRating) {
    if (line.length() <= 0) return false;
    string tempRating = "";

    bool flag = false;
    movieName = tempRating = "", movieRating = 0.0, flag = false;

    for (int i = 0; i < line.length(); i++){
        if(flag) tempRating += line[i];
        else if(line[i]==','&& line[0]!='"') flag = true;
        else {
            if(i==0 && line[0]=='"') continue;
            if(line[i]=='"'){ i++; flag=true; continue;}
            movieName += line[i];
        }
    }
    
    movieRating = stod(tempRating);
    return true;
}
