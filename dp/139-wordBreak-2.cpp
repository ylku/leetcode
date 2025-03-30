bool wordBreak(string s, vector<string>& wordDict) {
    auto size = s.size();
    unordered_map<char, vector<string>> dict;
    for(auto& word: wordDict) {
        dict[word[0]].emplace_back(word);
    }
    
    vector<bool> dp(size + 1, false);
    dp[0] = true;
    
    for(int i = 0; i <= size; ++i) {
        for(auto& element: dict[s[i]]) {
            auto e_size = element.size();
            if(dp[i] && element == s.substr(i, e_size)) 
                dp[i + e_size] = true;
        }
    }

    return dp[size];
}
