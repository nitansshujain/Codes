
class Solution
{
public:
    typedef pair<int, string> pis;
    struct comp
    {
        bool operator()(const pis &a, const pis &b)
        {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        }
    };
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        // top k me minHeap bnega
        // here we want to sort the freq of words,  we need a map and a minHeap custom pq.

        // create freq map
        unordered_map<string, int> mp;
        for (string &word : words)
            mp[word]++;

        // create custom minHeap pq
        priority_queue<pis, vector<pis>, comp> pq;

        // push the top k freq words into the pq
        for (auto it : mp)
        {
            pq.push({it.second, it.first});
            if (pq.size() > k)
                pq.pop();
        }

        // init the res vector of size k
        vector<string> res(k);
        int idx = k - 1;

        // since pq is minHeap, so the top element will be the minimum of all the items in pq, so start inserting backwards
        while (!pq.empty())
        {
            res[idx--] = pq.top().second;
            pq.pop();
        }

        return res;
    }
};