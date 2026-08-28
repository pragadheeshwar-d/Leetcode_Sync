class Solution {
public:
    bool isHappy(int n) {
        int slow = squareSum(n);
        int fast = squareSum(squareSum(n));
        if(slow == 1 || fast == 1) return true;
        
        while(slow != fast){
            slow = squareSum(slow);
            fast = squareSum(squareSum(fast));
            if(slow == 1 || fast == 1) return true;
        }
         
        return false;
    }

    int squareSum(int a){
        int sum = 0;
        while(a>0){
            sum += (int)pow((a % 10),2) ;

            a = a/10;
        }
        return sum;
    }
};