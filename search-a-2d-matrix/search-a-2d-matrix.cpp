class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
      int col = matrix[0].size();
        vector<int> colm(row);
        for (int i = 0; i <row; i++) {
             colm[i] = matrix[i][0];
        }

        int idx = upper_bound(colm.begin(), colm.end(), target) - colm.begin() ;
        cout << "index: " << idx << "\n";
       if(idx  == 0 || idx > row) return false;
        else{
               auto it =  lower_bound(matrix[idx-1].begin(), matrix[idx-1].end(), target);
                if( it != matrix[idx-1].end() &&  *it == target) return true;
                else return false;
        }
        
    }
};