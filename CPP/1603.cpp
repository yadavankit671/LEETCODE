#include<bits/stdc++.h>
using namespace std;

    // big ==> 1
    // medium ==> 2
    // small ==> 3
class ParkingSystem {
    private:
    int big=0,medium=0,small=0;
    public:
    ParkingSystem(int big, int medium, int small) {
        this->big=big;
        this->medium=medium;
        this->small=small;
    }
    
    bool addCar(int carType) {
        if(carType == 1){
            if(big == 0) return false;
            big --;
            return true;
        }
        else if (carType == 2){
            if(medium == 0) return false;
            medium --;
            return true;
        }
        else{
            if(small == 0) return false;
            small--;
            return true;
        }
    }
};

int main(){

}