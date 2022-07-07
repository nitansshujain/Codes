class Solution
{
public:
    // Input: stones = [2,7,4,1,8,1]
    // Output: 1
    // Explanation:
    // We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
    // we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
    // we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
    // we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of the last stone.
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> pq;
        int n = stones.size();
        for (int i = 0; i < n; i++)
        {
            pq.push(stones[i]);
        }

        while (pq.size() >= 2)
        {
            int a = pq.top();
            pq.pop();

            int b;
            if (pq.size() > 0)
            {
                b = pq.top();
                pq.pop();
            }

            int diff = 0;
            if (a != b)
            {
                diff = a - b;
            }

            if (diff != 0)
                pq.push(diff);
            // if(pq.size()==1) break; no need
        }

        return (!pq.empty() ? pq.top() : 0);
    }
};