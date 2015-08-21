#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<unordered_set<int>> matrix(numCourses); // save this directed graph
		for(int i = 0; i < prerequisites.size(); ++ i)
    	    matrix[prerequisites[i].second].insert(prerequisites[i].first);

    	vector<int> d(numCourses, 0); // in-degree
    	for(int i = 0; i < numCourses; ++ i)
    	    for(auto it = matrix[i].begin(); it != matrix[i].end(); ++ it)
    	        ++ d[*it];
		vector<int> result;
    	for(int j = 0, i; j < numCourses; ++ j)
    	{
    	    for(i = 0; i < numCourses && d[i] != 0; ++ i); // find a node whose in-degree is 0

    	    if(i == numCourses) // if not find
    	        return vector<int>();
			result.push_back(i);
    	    d[i] = -1;
    	    for(auto it = matrix[i].begin(); it != matrix[i].end(); ++ it)
    	        -- d[*it];
    	}

    	return result; 
    	}
};

int main() {

}
