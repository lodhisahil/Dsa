class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0;
        int tens = 0;
        for(int i=0 ;i<bills.size(); i++){
            if(bills[i] == 5){
                //koi change nai chaiye 
                fives++;
            }else if(bills[i] == 10){
                //atleast ek 5 chaiye
                if(fives > 0){
                    tens++;
                    fives--;
                }else{
                    return false;
                }
            }else{
                //atleast ek 5 aur ek 10 chaiye ya 3 ya 3 se jyada 5 chaiye 
                if(fives > 0 && tens > 0){
                    fives--;
                    tens--;
                }else if(fives >= 3){
                    fives -= 3;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};