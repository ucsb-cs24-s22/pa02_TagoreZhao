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
            cout << item.getName() <<", "<< std::fixed << std::setprecision(1) <<item.getRating();
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
        prefix.push(argv[i]); //log(m)
    } // O(m log(m))
    for (int i=2; i<argc; i++){
        set<M> preMovies;
        string pf = argv[i];
        for (auto movie: m){
            string name = movie.getName();
            Movies c = movie;
            if(name.substr(0,pf.length()) == pf){
                M r;
                r.equal(c);
                preMovies.insert(r);

            }
        } // O(k log(k))
        if(preMovies.empty()){
            cout << "No movies found with prefix "<<pf << endl << endl;
        }else{
            for (auto item : preMovies){
                cout << item.getName() <<", "<< std::fixed << std::setprecision(1) <<item.getRating();
                cout << endl;
            }//O(n)
            cout<<endl;
            M o;
            o.equal(*(preMovies.begin()));
            bestMovies.push(o);
        }
    } // O(m*k*log(k))
    for (int i = 0; i<numBest; i++){
        if(bestMovies.empty()){
        return 0;
        }
        M b;
        b.equal( bestMovies.front()); 
        string a = prefix.front();        
        bestMovies.pop(); //O(log(k))
        prefix.pop();//O(log(m))
        cout << "Best movie with prefix " << a << " is: " << b.getName() << " with rating " << std::fixed << std::setprecision(1) << b.getRating() << endl;
    }// T(n) = k*(O(logk)+O(logm))= O(klog(m))
  return 0;
  }


/* Add your run time analysis for part 3 of the assignment here as commented block*/
/* Part 3 Analysis:
Time Complexity analysis:
    There are three loops in total.
        1.The first loop push all prefix into a quene: T1(m,k,n) = O(m*log(m))
        2.The second loop have two inner loop:
            a.the first loop iterate through the set and push all the movie with the prefix into a quene: T2.a(m,k,n)=O(k*log(k))
            b.the second loop iterate through the quene push all the movies with the prefix into a quene: T2.b(m,k,n)=O(n)
         T2(m,k,n)= m(O(k*log(k))+O(n))=O(m*k*log(k))
        3. The third loop iterate through the two quene and pop them out: T3(n) = k*(O(logk)+O(logm))= O(klog(m))
    The total Time complexity T(m,k,n)= O(m*log(m)) + O(m*k*log(k)) + O(klog(m)) = O(m*k*log(k))

Space Complexisy analysis:
    Besides the given movie set and prefix quene, I need a quene that can contain all the movie with the prefix
    S(m,k,n) = O(k)

I tried to design my program for both:
    I was not able to achieve both of them.
    The main reason I think is that I am not fully confortable with all the properties and functions of different data type,
    Therefore when I am desigining my program I can not find the best option to approach the question. The original design 
    actually set a top boundary for the effieceny and complexity for my program. Simplyfying lines of code will not make too
    much difference, the design part before start writing my code is the key to a lower time and space complexity from my point
    of view.If the design is bad, there is not much I can do besides redesign it.
    Time complexity is harder to achieve in my opinion, because it closely corresponds to how I approach the question. If I want
    to reduce time complexity I would have to find another approach sometime even changing the space complexity. If I do not want
    the trade off, I would have to find another approach under limitations of space.  

*/

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
