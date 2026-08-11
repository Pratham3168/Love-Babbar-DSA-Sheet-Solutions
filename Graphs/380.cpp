class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {

        int n = board.size();
        int destination = n *n ;
        queue<int> q;
        vector<bool> visited(destination + 1, false);

        q.push(1);
        visited[1] =true;
        int moves =0;

        while(!q.empty()){

            int size = q.size();
            while(size--){

                int curr = q.front();
                q.pop();

                if(curr == destination){
                    return moves;
                }

                for(int dice = 1; dice <= 6; dice ++){
                    int next = curr + dice;

                    if(next > n*n)break;

                    // -----------------------------
                    // Convert square -> board cell
                    // -----------------------------
                    int r = (next - 1) / n;
                    int c = (next - 1) % n;

                    if (r % 2 == 1)
                        c = n - 1 - c;

                    r = n - 1 - r;


                    //snake or ladder
                    if(board[r][c] != -1){
                        next = board[r][c];
                    }


                    if(!visited[next]){
                        visited[next] =true;
                        q.push(next);
                    }
                }
            }
            moves++;

        }
        return -1;
    }
};