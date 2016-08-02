#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
	//private:
//    int findMinMax(const vector<int>& prices, vector<int>& minP, vector<int>& maxP)
//    {
//        int i, len = prices.size(), res = 0;
//        for(i=0; i<len-1; i++)
//        {
//            while(i<len-1 && prices[i+1] <= prices[i]) i++; // detect the local minimum points
//            if(i<len-1) minP.push_back(prices[i]);
//            else break;
//            while(i<len-1 && prices[i+1] >= prices[i]) i++; // detect the local maximum points
//            maxP.push_back(prices[i]);
//            res +=maxP.back()-minP.back(); // res  = sum(maxP - minP), the maximum margin we can make
//        }
//        return res;
//    }

//    int FSM_stock(vector<int>& minP, vector<int>& maxP, int k)
//    {
//            int states[2][1+2*k], i, j, cur =0, next =1, res =0, numMax = maxP.size();
//            fill_n(&states[0][1], 2*k, INT_MIN/2);
//            states[0][0] = states[1][0] = 0;

//            for(i=0; i<numMax;++i)
//            {
//                for(j=0; j<k; ++j)  
//                { // only buy at the local minimum points
//                    states[next][j*2+1] = max(states[cur][j*2+1], states[cur][j*2]-minP[i]); 
//                    states[next][j*2+2] = states[cur][j*2+2];
//                }
//                swap(cur, next);
//                for(j=1; j<=k; ++j) 
//                { // only sell at the local maximum points
//                    states[next][j*2] = max(states[cur][j*2], states[cur][j*2-1] + maxP[i]);
//                    states[next][j*2-1] = states[cur][j*2-1];
//                }
//                swap(cur, next);
//            }
//            for(i=1; i<=k;++i) res = max(res, states[cur][i*2]);
//            return res;
//    }

//public:
//    int maxProfit(int k, vector<int>& prices) {

//        vector<int> minP, maxP;

//        int res = findMinMax(prices, minP, maxP);
//        if(maxP.size() <= k) return res;
//        else
//            return FSM_stock(minP, maxP, k);
//    }
public:
	int maxProfit(int k, vector<int>& prices) {
	        //int states[2][4] = {INT_MIN, 0, INT_MIN, 0}; // 0: 1 buy, 1: one buy/sell, 2: 2 buys/1 sell, 3, 2 buys/sells
	        int len = prices.size();
	        if (len<2) return 0;
	        if (k>len/2){ // simple case
	            int ans = 0;
	            for (int i=1; i<len; ++i){
	                ans += max(prices[i] - prices[i-1],0);
	            }
	            return ans;
	        }
			vector<vector<int> > states(2,vector<int>(2*k+2));
			for (int i = 0; i <= 2*k; i+=2) {
				states[0][i] = INT_MIN;
				states[0][i+1] = 0;
			}
	        int i, cur = 0, next =1;
	        for(i=0; i<len; ++i)
	        {
	          for (int j = 2; j <= 2*k; j+=2) {
				states[next][j] = max(states[cur][j], states[cur][j-1]-prices[i]);
	            states[next][j+1] = max(states[cur][j+1], states[cur][j]+prices[i]);
			  }
	            swap(next, cur);
	        }
			int maxp = 0;
			for (int i = 0; i <= 2*k; i+=2) {
				if(maxp < states[cur][i+1])
					maxp = states[cur][i+1];
			}
	        return maxp;
	    }

//int maxProfit(int k, vector<int> &prices) {
//        int len = prices.size();
//        if (len<2) return 0;
//        if (k>len/2){ // simple case
//            int ans = 0;
//            for (int i=1; i<len; ++i){
//                ans += max(prices[i] - prices[i-1],0);
//            }
//            return ans;
//        }
//        int hold[k+1];
//        int rele[k+1];
//        for (int i=0;i<=k;++i){
//            hold[i] = INT_MIN;
//            rele[i] = 0;
//        }
//        int cur;
//        for (int i=0; i<len; ++i){
//            cur = prices[i];
//            for(int j=k; j>0; --j){
//                rele[j] = max(rele[j],hold[j] + cur);
//                hold[j] = max(hold[j],rele[j-1] - cur);
//            }
//        }
//        return rele[k];
//    }
};

int main() {
	int a[] = {1,2};
	vector<int> b(a,a+2);
	Solution s;
	cout << s.maxProfit(1,b);
}
/*
 * int maxProfit(int k, vector<int>& prices) {
    int n = (int)prices.size();
    if (n <= 1) return 0;
    int fm = 0, km = 0;
    for (int j = 1; j < n; j++) {
        int f = prices[j]-prices[j-1];
        if (f>0) {
            fm += f;
            km++;
        }
    }
    if (k >= km) {
        return fm;
    } else {
        int f[n], prev;
        fill_n(f, n, 0);
        for (int i = 1; i <= k; i++) {
            int S = INT_MIN;
            prev = f[0];
            for (int j = 1; j < n; j++) {
                S = std::max(S, prev-prices[j-1]);
                prev = f[j];
                f[j] = std::max(f[j-1], S+prices[j]);
            }
        }
        return f[n-1];
    }
	*/
