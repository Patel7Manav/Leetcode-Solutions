class Solution {
    vector<vector<string>> ans;     
    unordered_map<string,int> m;    
    string b;   
    int sz;    
    void dfs(string& word,vector<string>& seq){
        if(word==b){
            reverse(seq.begin(), seq.end());
            ans.emplace_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int steps = m[word];
        for(int i=0;i<sz;++i){
                char orig = word[i];
                for(char c='a';c<='z';++c){
                    word[i]=c;
                    if(m.count(word) and m[word]+1==steps){
                        seq.emplace_back(word);    
                        dfs(word, seq);
                        seq.pop_back();   
                    }
                }
                word[i] = orig;
            }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        b=beginWord;
        
        unordered_set<string> st(wordList.begin(), wordList.end());     
        queue<string> q;    
        
        q.push(b);
        
        m[b]=1;
        sz = b.size();
        st.erase(b);
        while(!q.empty()){
            string word = q.front();
            q.pop();
            
            if(word==endWord)
                break;
            int steps = m[word];
            
            for(int i=0;i<sz;++i){
                char orig = word[i];
                for(char c='a';c<='z';++c){
                    word[i]=c;
                    if(st.count(word)){
                        st.erase(word);
                        q.push(word);
                        m[word] = steps+1;
                    }
                }
                word[i] = orig;
            }
        }
        if(m.count(endWord)){
            vector<string> seq;
            seq.emplace_back(endWord);
            dfs(endWord, seq);
        }
        return ans;
    }
};