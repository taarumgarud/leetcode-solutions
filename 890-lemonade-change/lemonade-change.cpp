class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0, tens = 0;
        for(int i = 0 ;i<bills.size(); i++){
            if(bills[i]==20 && fives>0 && tens>0){
                fives--;
                tens--;
            }
            else if(bills[i]==20 && fives>2){
                fives-=3;
            }
            else if(bills[i]==10 && fives>0){
                fives--;
                tens++;
            }
            else if(bills[i]==5){
                fives++;
            }
            else{
                return false;
            }
        }
        return true;
    }
};