class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        // Gajab Q h
        int n = s.size(), i = 0, j = 0;

        int res_max = 0;       // res to return
        int window_size = 0;   // j-i+1
        int max_freq_char = 0; // char having max freq in current window
        vector<int> freq(26, 0);
        while (j < n)
        {
            char c = s[j];
            freq[c - 'A']++;
            max_freq_char = max(max_freq_char, freq[c - 'A']);

            window_size = j - i + 1;

            // shrinking the window
            while (window_size - max_freq_char > k)
            { // chars to replace > k
                freq[s[i] - 'A']--;
                i++;
                window_size--;
            }

            res_max = max(res_max, window_size);
            j++;
        }
        return res_max;
    }
};