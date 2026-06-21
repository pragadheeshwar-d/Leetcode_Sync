class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int m = *max_element(costs.begin(),costs.end());
        vector<int>freq(m+1,0);
        for(int x:costs){
            freq[x]++;
        }    
        int ans=0;
        for(int i=1;i<=m;i++){
            if(freq[i]==0)
                continue;
            if(coins<i)
                break;
            long long t = (long long)i * freq[i]; 

            if(coins>=t){
                ans+=freq[i];
                coins-=t;
            }
            else{
                ans+=coins/i;
                break;
            }
        }
        return ans;
    }
};