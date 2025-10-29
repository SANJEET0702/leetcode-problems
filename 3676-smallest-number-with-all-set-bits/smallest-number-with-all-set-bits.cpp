class Solution {
public:
    int smallestNumber(int n) {
         return (1<< bitlen(n))-1;
    }

    private:
    int bitlen(int n){
        return 32 - __builtin_clz(n);
    }
};