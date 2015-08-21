class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        vector<int> partial;

        backTrackingFun(n,k,1,partial,ret);
        return ret;
    }

    void backTrackingFun(int n,int k,int idx,vector<int> partial,vector<vector<int>> &ret){
        if(1==k){
            if(idx<=n && n<10){
                partial.push_back(n);
                ret.push_back(partial);
            }
            return;
        }

        for(auto i=idx;i<10;++i){
            if(i<n){
                partial.push_back(i);
                backTrackingFun(n-i,k-1,i+1,partial,ret);
                partial.pop_back();
            }else{
                break;
            }
        }
    }
};
