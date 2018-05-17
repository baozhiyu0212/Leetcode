class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int top = 0, bot = image.size()-1, left = 0, right = image[0].size()-1;
        int xx = x, yy = y;
        while(top<x){
            int mid = (top+x)/2;
            if(checkrow(image,mid)) x=mid;
            else top =mid+1;
        }
        while(xx<bot){
            int mid = (xx+bot+1)/2;
            if(checkrow(image,mid)) xx=mid;
            else bot = mid-1;
        }
        while(left<y){
            int mid = (left+y)/2;
            if(checkcol(image,mid)) y=mid;
            else left = mid+1;
        }
        while(yy<right){
            int mid = (yy+right+1)/2;
            if(checkcol(image,mid)) yy=mid;
            else right = mid-1;
        }
        return (bot-top+1) * (right-left+1);
        //return right;
    }
    
    bool checkrow(vector<vector<char>> image, int r){
        for(int i=0;i<image[0].size();i++){
            if(image[r][i]=='1') return true;
        }
        return false;
    }
    bool checkcol(vector<vector<char>> image, int c){
        for(int i=0;i<image.size();i++){
            if(image[i][c]=='1') return true;
        }
        return false;
    }
};
