#include<iostream>
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
	   if(C>E && G>A && H>B && D>F)
		   return  (C-A)*(D-B)+(G-E)*(H-F)-(min(C,G)-max(A,E))*(min(D,H)-max(B,F));
	   else 
		   return (C-A)*(D-B)+(G-E)*(H-F); 
    }
};

int main() {
	Solution s;
	int a = s.computeArea(-3,0,3,4,0,-1,9,2);
	cout << a;
	return 0;
}
