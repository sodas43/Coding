/** GEEKSFORGEEKS (video explanation: https://www.youtube.com/watch?v=19tY6Y90TP0)
 =====================
 Given a snake and ladder board of order 5x6 , find the minimum number of dice throws required to reach the destination or last cell (30th cell) from source (1st cell) . 
 Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line of input contains an integer N denoting the no of ladders and snakes present. Then in the next line are 2*N space separated values a,b which denotes a ladder or a snake at position 'a' which takes to a position 'b'.

Output:
For each test case in a new line print the required answer denoting the min no of dice throws.

Constraints:
1<=T<=100
1<=N<=10
1<=a<30
1<=b<=30

Example:
Input:
2
6
11 26 3 22 5 8 20 29 27 1 21 9
1
2 30
Output:
3  (For 1st throw get a 2, For 2nd throw get a 6, For 3rd throw get a 2)
1  ( For 1st throw get a 2 and goto 30)
*/


#include <iostream>
#include <queue>

using namespace std;

struct QueueEntry {
    int vertex;
    int distance;
};

int MinimumDistanceRequired(vector<int> board, int N) {
    vector<bool> visited(N, false);
    
    queue<QueueEntry> q;
    visited[0] = true;
    
    QueueEntry start;
    start.vertex = 0;
    start.distance = 0;
    
    q.push(start);
    
    QueueEntry qe;
    int vertex;
    while(!q.empty()) {
        qe = q.front();
        vertex = qe.vertex;
        
        if(vertex == N-1) { break; }
        
        q.pop();
        
        for(int i=vertex+1; i <= (vertex+6) && i < N; ++i)  {
            if(visited[i] == false) {
                QueueEntry cell;
                cell.distance = qe.distance+1;
                
                visited[i] = true;
                
                if(board[i] != -1)  { cell.vertex = board[i]; }
                else                { cell.vertex = i; }
                
                q.push(cell);
            }
        }
    }
    if (vertex == N-1)    return qe.distance;
    else                  return -1; // not possible
    
}

int main() {
	//code
	int T;
	cin >> T;
	while(T--) {
	    int n;
	    cin >> n;
	    
	    int cell = 30;
	    vector<int> board(cell, -1);
	    
	    int a, b;
	    for(int i=0; i<n; ++i) {
	        cin >> a >> b;
	        board[a-1] = b-1;
	    }
	    
	    cout << MinimumDistanceRequired(board, cell) << endl;
	}
	return 0;
}
