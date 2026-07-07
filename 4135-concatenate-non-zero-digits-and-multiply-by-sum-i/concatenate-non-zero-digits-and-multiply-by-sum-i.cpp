class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0, sum = 0, mul = 1;
        while(n > 0){
            long long dig = n%10;
            if(dig != 0){
                sum += dig;
                x += dig*mul;
                mul *= 10;
            }
            n /= 10;
        }
        return x*sum;
    }
};