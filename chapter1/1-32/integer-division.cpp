#include "integer-division.hpp"

int integerDivision1(int a, int b)
{
        bool aNegative = false;
        bool bNegative = false;
        if(a < 0) {
                a = -a;
                aNegative = true;
        }
        if(b < 0) {
                b = -b;
                bNegative = true;
        }
        // complexity: a / b
        int result = 0;
        while(a > 0) {
                a -=b;
                result++;
        }
        if(a < 0) {
                result--;
        }
        if(aNegative ^ bNegative) {
                result = -result;
        }
        return result;
}

int integerDivision2(int a, int b)
{
        bool aNegative = false;
        bool bNegative = false;
        if(a < 0) {
                a = -a;
                aNegative = true;
        }
        if(b < 0) {
                b = -b;
                bNegative = true;
        }
        // complexity: (log2(a / b))^2
        int result = 0;
        int powerOfTwoMultiple = 0;
        int temp = a;
        while(true) {
                temp = a - (b << powerOfTwoMultiple);
                if(temp <= 0 && powerOfTwoMultiple == 0) {
                        break;
                } else if(temp <= 0) {
                        a -= (b << (powerOfTwoMultiple - 1));
                        result += powerOfTwoMultiple;
                        powerOfTwoMultiple = 0;               
                } else {
                        powerOfTwoMultiple++;
                }
        }
        if(temp == 0) {
                result++;
        }
        if(aNegative ^ bNegative) {
                result = -result;
        }
        return result;
}