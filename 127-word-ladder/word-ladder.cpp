class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        set<string>st;
        int n=wordList.size();
        for(int i=0;i<n;i++){
            if(wordList[i]!=beginWord)st.insert(wordList[i]);
        }
        string s="";
        int ans=0;
        q.push({beginWord,1});
        while(!q.empty()){
            string word=q.front().first;
            int ord=q.front().second;
            q.pop();
            if(word==endWord)return ord;
            for(int i=0;i<word.size();i++){
                char org=word[i];
                for(char j='a';j<='z';j++){
                    word[i]=j;
                    if(st.contains(word)){
                        q.push({word,ord+1});
                        st.erase(word);
                    }
                }
                word[i]=org;
            }
        }
        return 0;
    }
};