class Solution {
  private:
    bool knows(int a, int b, vector<vector<int> >& M) {
        if(M[a][b] == 1)
            return true;
        else
            return false;
    }    
    
  public:
    
    int solve(vector<vector<int>>& mat){
        
        stack<int> s;
        int n = mat.size();
        
        for(int i = 0 ; i < n ; i++){
            s.push(i);
        }
        
        while(s.size() > 1){
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if(knows(a,b,mat)){
                s.push(b);
            }
            else{
                s.push(a);
            }
        }
        
        //check 
        int ans = s.top();
        for(int i = 0; i < n; i++) {

            if(i != ans && mat[ans][i] != 0)
                return -1;
        
            if(i != ans && mat[i][ans] != 1)
                return -1;
        }
        
        return ans;
        
    }
  
  
    int celebrity(vector<vector<int>>& mat) {
        // code here
        return solve(mat);
        
    }
};