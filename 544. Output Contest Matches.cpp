//Straight Forward First Time Answer
class Solution {
public:
    string findContestMatch(int n) {
        int left = 1, right = n;
        vector<pair<int,int>> v;
        while(left<right){
            v.push_back(make_pair(left,right));
            left++;right--;
        }
        return helper(v);
        
    }
    
    string helper(vector<pair<int,int>> v){
        if(v.size()==1) return "(" + to_string(v[0].first) + "," + to_string(v[0].second) + ")";
        bool isLeft = true;
        vector<pair<int,int>> v1,v2;
        for(int i=0;i<v.size();i++){
            if(isLeft){
                v1.push_back(v[i]);i++;
                v2.push_back(v[i]);
                isLeft = !isLeft;
            }
            else{
                v2.push_back(v[i]);i++;
                v1.push_back(v[i]);
                isLeft = !isLeft;
            }
        }
        return "(" + helper(v1) + "," + helper(v2) + ")";
    }
};

//Shorter and Better Answer
class Solution {
public:
    string findContestMatch(int n) {
        vector<string> m(n);
        for (int i = 0; i < n; i++) {
            m[i] = to_string(i + 1);
        }

        while (n > 1) {
            for (int i = 0; i < n / 2; i++) {
                m[i] = "(" + m[i] + "," + m[n - 1 - i] + ")";
            }
            n /= 2;
        }
        
        return m[0];
    }
};
