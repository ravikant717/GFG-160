class Solution
{
public:
    void dfs(vector<vector<int>> &adj, vector<int> &ans, vector<bool> &visited, int node)
    {
        visited[node] = true;
        ans.push_back(node); // Preorder processing
        for (auto &neighbour : adj[node])
        {
            if (visited[neighbour] == true)
                continue;
            dfs(adj, ans, visited, neighbour);
        }
    }
    vector<int> dfs(vector<vector<int>> &adj)
    {
        int n = adj.size();
        vector<bool> visited(n, false);
        vector<int> ans;
        for (int i = 0; i < n; i++)
        { // O(V)
            if (visited[i] == true)
                continue;
            dfs(adj, ans, visited, i); // O(E): all the dfs called independtly do work and in total only E edges are processed
        }

        return ans;
    }
};