class Solution
{
public:
    string getHint(string secret, string guess)
    {
        vector<int> secret_freq(10);
        vector<int> guess_freq(10);

        int bulls = 0, cows = 0;
        for (int i = 0; i < secret.size(); i++)
        {
            char secret_char = secret[i];
            char guess_char = guess[i];

            if (secret_char == guess_char)
                bulls++;
            else
            {
                secret_freq[secret_char - '0']++;
                guess_freq[guess_char - '0']++;
            }
        }
        for (int i = 0; i < 10; i++)
        {
            cows += min(secret_freq[i], guess_freq[i]);
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};