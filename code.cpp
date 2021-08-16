/*
//
//
simple approach
first find no. of cable available which is equal to the size of connection given
then find no. of unconnected computer
then find connected computer by n-unconneted computer
then find cable required to connect connected computer = (connected_computer-1)
then find cable remanning after connectioning all connected computer=total cable-no of cable required to connec tconnected computer
if no of cable remaning >= unconnected computer return no. of unconnected computer count
else return -1;
//
//
*/

class Solution {
public:
    void dfs(int i,vector<int>connection[],vector<int> &visit)
    {
        visit[i]=1;
        for(auto s:connection[i])
        {
            if(visit[s]!=1)
            {
                dfs(s,connection,visit);
            }
        }
        
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int unvisited=-1;
        int extra_cable=0;
        vector<int>visit(n,0);
        vector<int>connection[n];
        int total_cable=connections.size();
        for(int i=0;i<connections.size();i++)
        {
            connection[connections[i][0]].push_back(connections[i][1]);
             connection[connections[i][1]].push_back(connections[i][0]);
        }
        for(int i=0;i<n;i++)
        {
            if(visit[i]!=1)
            {
              unvisited++;
                dfs(i,connection,visit);
            }
        }
        int remain_cable=total_cable-(n-unvisited-1);
        if(remain_cable>=unvisited)
        {
            return unvisited;
        }
        return -1;
    }
};
