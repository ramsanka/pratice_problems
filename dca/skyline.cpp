#include <bits/stdc++.h>

using namespace std;


vector <pair<int, int> >
createSkyline(vector<vector<int> >&buildings)
{

   int N = buildings.size();
   
   vector<pair<int, int> > wall;

   int left, right, height;

   //iterate through the list.
   //populate the wall vector. <left, -height>
   //populate the right wall <right, +height>
   //This will ensure that left gets inserted first in the multiset.
   for (int i = 0; i < N; i++) {

 	left = buildings[i][0];
	height = buildings[i][1];
        right  = buildings[i][2];

        wall.push_back({left, -height}); //can make_pair work withe negative val
        wall.push_back(make_pair(right, height));
   }

   sort(wall.begin(), wall.end()); //sort the entries based on the first entry.

   vector<pair<int, int> >skyline;	//for the output.

   multiset<int> leftWallHeight = { 0 };  //this is the priority queue mainatina the list of hghts.

   int top = 0; //current max height.

   for (auto w : wall) {  //auto keyword for iterator ease in parsing.

       if (w.second < 0) { //left wall is found
          leftWallHeight.insert(-w.second); //insert in the queue.
       } else {
          leftWallHeight.erase(leftWallHeight.find(w.second)); //remove from the queue.
       }
   
       //If they do not match top and the top of the queue.
       //need to dump it at the skyline output.

       if (*leftWallHeight.rbegin() != top) {  
	  top = *leftWallHeight.rbegin();
          skyline.pushback(make_pair(w.first, top));
       }


   }


   return skyline;
}


void printSkyline (
	vector<vector<int> >&buildings) {

	vector<pair<int, int> > skyline = createSkyline(buildings);
	cout << "skyline paradise " << endl;


        for (auto it : skyline) {

 	   cout << "{" << it.first << ","<< it.second << "}" << endl;
        }

}


//driver code;

int main() {

	vector<vector<int> >buildings;

        buildings = { { 1, 11, 5 }, { 2, 6, 7 },  
                  { 3, 13, 9 }, { 12, 7, 16 }, 
                  { 14, 3, 25 }, { 19, 18, 22 }, 
                  { 23, 13, 29 }, { 24, 4, 28 } };

        //prinnt the final output.
        printSkyline(buildings);
	return 0;
}

	     
  
	

   



   

