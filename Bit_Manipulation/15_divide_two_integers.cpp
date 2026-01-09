int divide(int dividend, int divisor) {
    if(dividend == divisor) return 1;
    if(dividend == INT_MIN && divisor == -1) return INT_MAX;
    bool isNeg = (dividend < 0) ^ (divisor < 0); 
    long long n = abs((long long)dividend);
    long long d = abs((long long)divisor);
    int cnt = 0;
    long long quotient = 0;
    while(n >= d){
        cnt = 0;
        while(n >= (d << cnt+1)){
            cnt++;
        }
        quotient += (1 << cnt);
        n -= (d << cnt);
    }
    if(quotient > INT_MAX) return INT_MAX;
    if(quotient < INT_MIN) return INT_MIN;

    return (isNeg ? quotient * -1 : quotient);
}
