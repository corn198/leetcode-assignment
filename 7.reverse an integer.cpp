class Solution {
public:
    int reverse(int x) {
        long long reversed = 0; // use long long to detect overflow
        while (x != 0) {
            int digit = x % 10;
            reversed = reversed * 10 + digit;
            if (reversed > INT_MAX || reversed < INT_MIN) return 0; // handle overflow
            x /= 10;
        }
        return (int)reversed;
    }
};