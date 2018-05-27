/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        vector<string> guess;
        vector<int> res;
        int round = 0;
        while(round<10){
            int size = wordlist.size();
            string cur = wordlist[(rand()%size)];
            guess.push_back(cur);
            int feedback = master.guess(cur);
            res.push_back(feedback);
            round++; 
            if(round==10) break;
            vector<string> temp;
            for(int i=0;i<wordlist.size();i++){
                bool valid = true;
                for(int j=0;j<guess.size();j++){
                    if(match(wordlist[i],guess[j])!=res[j]) valid = false;
                }
                if(valid) temp.push_back(wordlist[i]);
            }
            wordlist = temp;
        }
        
    }
    
    int match(string s1,string s2){
        int count = 0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]==s2[i]) count++;
        }
        return count;
    }
};
