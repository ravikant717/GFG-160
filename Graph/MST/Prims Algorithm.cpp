class Solution
{
public:
    typedef pair<int, int> P;
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();

        vector<vector<P>> adj(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int wt = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, wt});
                adj[j].push_back({i, wt});
            }
        }

        priority_queue<P, vector<P>, greater<P>> pq;

        vector<bool> inMST(n, false);

        pq.push({0, 0});

        int sum = 0;

        while (!pq.empty())
        {
            auto it = pq.top();

            pq.pop();

            int wt = it.first;
            int node = it.second;

            if (inMST[node] == true)
                continue;

            inMST[node] = true;
            sum += wt;

            for (auto &temp : adj[node])
            {
                int neighbour = temp.first;
                int new_wt = temp.second;

                if (inMST[neighbour] == false)
                {
                    pq.push({new_wt, neighbour});
                }
            }
        }
        return sum;
    }
};