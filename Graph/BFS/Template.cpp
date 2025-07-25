class Solution
{
public:
    vector<int> bfs(vector<vector<int>> &adj)
    {
        int n = adj.size();

        vector<bool> visited(n, false);

        vector<int> ans;

        queue<int> q; // O(v)
        q.push(0);
        visited[0] = true;
        while (!q.empty())
        {
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for (auto &neighbour : adj[node])
            {
                if (visited[neighbour] == true)
                    continue;
                q.push(neighbour);
                visited[neighbour] = true;
            }
        }
        return ans;
    }
};

// Total time complexity: O(V+E)
// Total space complexity: O(V)