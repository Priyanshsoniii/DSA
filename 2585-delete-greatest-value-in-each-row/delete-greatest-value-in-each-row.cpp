class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int sum = 0;
        priority_queue<int>pq;
        int row = grid.size();
        int col = grid[0].size();
        for(int i=0;i<row;++i){
            sort(grid[i].begin(),grid[i].end());
        }


        for(int j=0;j<col;++j){
            pq = priority_queue<int>();
            for(int i=0;i<row;++i){
                pq.push(grid[i][j]);
            }
            sum += pq.top();
        }
        return sum;

    }
};