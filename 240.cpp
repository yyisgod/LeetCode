#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int m = matrix.size(); 
	   if (!m)
		   return false;
	   int n = matrix[0].size();
	   vector<int> rows(m);

	   for (int i = 0; i < m; i++)
		   rows[i] = matrix[i][0];
	   auto row = lower_bound(rows.begin(), rows.end(),target);
	   if( *row == target && row <= rows.end())
			return true;
	//	else 
			//row--;
	
	   int irow = row - rows.begin();
	   for (int i = 0; i < irow; i++) {
	   		auto col = lower_bound(matrix[i].begin(), matrix[i].end(), target);
	   		if (*col == target && col <= matrix[i].end())
		   		return true;
	   }
	   
	   return false;
    }
};

int main() {
	vector<vector<int> > m(2,vector<int>(1));
	int target;
	Solution s;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 1; j++)
			cin >> m[i][j];
	cin >> target;
	cout << s.searchMatrix(m,target) << endl;
	return 0;
}
