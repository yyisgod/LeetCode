class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        const int N = buildings.size();
        vector<pair<int, int>> result;
        if (0 == N) return result;
        map<int, int> x2hmap;
        int lb = buildings[0][0];
        int rb = buildings[0][1];
        int tb = buildings[0][2];
        x2hmap[buildings[0][0]] = 0;
        x2hmap[buildings[0][1]] = 0;
        for (int i = 1; i < N; ++i){
            if(buildings[i][0] >= lb && buildings[i][1] <= rb && buildings[i][2] <= tb) continue;
            x2hmap[buildings[i][0]] = 0;
            x2hmap[buildings[i][1]] = 0;
            lb = buildings[i][0];
            rb = buildings[i][1];
            tb = buildings[i][2];
        }

        for (int i = 0; i < N; ++i){
            auto lowbound = x2hmap.lower_bound(buildings[i][0]);
            auto upperbound = x2hmap.upper_bound(buildings[i][1] - 1);//第i个房子中包含的点 
            for (auto it = lowbound; it != upperbound; it++){
                if(buildings[i][2] > it->second){
                    it->second = buildings[i][2];
                }
            }
        }
        for (auto &x2hpair : x2hmap)
        {
            const int &curx = x2hpair.first;
            const int &maxh = x2hpair.second;
            if (result.empty() || (curx != result.back().first && maxh != result.back().second)){
                    result.emplace_back(pair<int, int>(curx, maxh));
            }
        }
        return result;
    }
};
