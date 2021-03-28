#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <functional>
#include <cmath>
#include "structure.h"

using std::cout;
using std::endl;
using std::cin;



std::map<genre, std::vector<std::reference_wrapper<track> >> genreLookupTable;


// (index creation is seperate from lookup)
// index all the data points
// use genres for classification for creating a condensed nearest neighbours
// parameters for K-Dimension lattice representation
// parameters - popularity, tempo, energy, happiness, acousticness
// distance calculation - euclidian, manhattan, consine, hamming
// variable depth
// variable spread



void genreLookupTable_init() {
  for(auto i = genre::hip_hop; int(i) <= int(genre::dubstep); i = (genre)((int)i + 1)) {
    genreLookupTable.emplace(i, *(new std::vector<std::reference_wrapper<track>>) );
  }

  for(auto& i: givenTracks) {
    for(auto j: i.genres) {
      genreLookupTable.at(j).push_back(i);
    }
  }
}

void indexTracks() {
  /* Index all tracks, maintains the genreLookupTable */
  // initializes track_parameters
  // set track_genres

  genreLookupTable_init();
}

double distance_euclidian(track& from, track& to) {
  double distance = sqrt(
    pow(from.params.at(parameter::popularity) - to.params.at(parameter::popularity), 2) + 
    pow(from.params.at(parameter::tempo) - to.params.at(parameter::tempo), 2) + 
    pow(from.params.at(parameter::energy) - to.params.at(parameter::energy), 2) + 
    pow(from.params.at(parameter::happiness) - to.params.at(parameter::happiness), 2) +
    pow(from.params.at(parameter::acousticness) - to.params.at(parameter::acousticness), 2) 
  );

  // cout<<distance<<endl;
  return distance;
}

/* Helper Classes */
class queue_cmp {
  public:
    bool operator()(std::pair<std::reference_wrapper<track>, int>& p1, std::pair<std::reference_wrapper<track>, int>& p2) {
      return p1.second > p2.second;
    }
};

class set_cmp {
  public:
    bool operator()(const track& a, const track& b) {
      return a.name != b.name;
    }
};

/* Lookup Function */
// std::vector<std::reference_wrapper<track>> nearest_neighbours;
int depth = 4;
std::set<std::reference_wrapper<track>, set_cmp> nearest_neighbours;
void lookup(track& sourceTrack, int number_of_neighbours = 6) {
   /* Finds all the nearest neigbours to sourceTrack */
  // Calculate distance of every node in the condensed data set
  // store it an vector in an ordered way and return the vector
  // return the vector of size = depth provided

  // if(depth == 0)  return;
  if(depth == 0) return;
  depth--;

  // priority queue of pair (&track and distance)
  std::priority_queue<std::pair<std::reference_wrapper<track>, int>, std::vector<std::pair<std::reference_wrapper<track>, int>>, queue_cmp> ordered_neighbours;

  for(auto sourceTrack_genres: sourceTrack.genres) {
    for(auto& i: genreLookupTable.at(sourceTrack_genres)) {
      if(sourceTrack.name != i.get().name) {
        // push to priority queue 
           int distance = distance_euclidian(sourceTrack, i.get());
           ordered_neighbours.push(std::make_pair(i, distance ));
      }
    }
  }

  for(int i=0; !ordered_neighbours.empty() && i < ordered_neighbours.size() && i < number_of_neighbours; i++) {
    // cout<<ordered_neighbours.size()<<endl;
    auto t = ordered_neighbours.top();
    // cout<<ordered_neighbours.top().first.get().name<<endl;
    // nearest_neighbours.push_back(t.first.get());
    nearest_neighbours.emplace(t.first.get());
    lookup(t.first.get());
    ordered_neighbours.pop();
  }
  
  return;
}

int main() {
  indexTracks();

  lookup(givenTracks[2]);
  
  cout<<"Seed Track: \t"<<givenTracks[2].name<<endl;

  cout<<endl<<"Related Tracks:"<<endl;
  for(auto& i: nearest_neighbours) {
    cout<<i.get().name<<endl;
  }
  
}
