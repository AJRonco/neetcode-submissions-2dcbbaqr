class Solution {
private:
    unordered_map<int, vector<int>> preMap;
    unordered_set<int> visiting;
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        for (int i = 0; i < numCourses; i++) {
            preMap[i] = {};
        }

        for (auto preReq : prerequisites){
            preMap[preReq[0]].push_back(preReq[1]);
        }

        for (int course = 0; course < numCourses; course++){
            if (!dfs(course)){
                return false;
            }
        }
        return true;

    }

    bool dfs(int crs) {

        if (visiting.count(crs)) {
            return false;
        }

        if (preMap[crs].empty()) {
            return true;
        }

        visiting.insert(crs);
        for (int pre:preMap[crs]){
            if (!dfs(pre)){
                return false;
            }
        }
        visiting.erase(crs);
        preMap[crs].clear();
        return true;

    }
};
