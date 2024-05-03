public class NQueen {

    public Boolean isSafe(int[][]board,int row,int col,int n){
           int i,j;
           for(i=0;i<col;i++){
            if(board[row][i]==1) return false;
           }   

           for(i=0,j=0;i<row && j<col;i++,j++){
            if(board[i][j]==1) return false;
           }

           for(i=0,j=col;i<row && j>=0;i++,j--){
                  if(board[i][j]==1) return false;
           }

           return true;
    } 
    public Boolean solveNqueen(int [][]board,int col,int n){
        if(col>=n) return true;

        for(int i=0;i<n;i++){
            if(isSafe(board, i, col, n)){
                board[i][col]=1;
                if(solveNqueen(board, col+1, n)){
                    return true;
                }
                board[i][col]=0;
            }

        }
        return false;

    }
    public static void main(String[] args) {
        
    }
}
