 //GCD BY EUCLIDEAN ALGO 

The Euclidean algorithm is a method to find the Greatest Common Divisor (GCD) of two numbers.
The GCD of two numbers is the largest number that divides both of them without leaving a remainder.

The Idea:
The Euclidean algorithm is based on the principle that:

The GCD of two numbers doesn't change if we subtract the smaller number from the larger one.

This can be further optimized using the remainder operation:

The GCD of two numbers A and B is the same as the GCD of B and A % B (where % is the remainder when A is divided by B).

Steps of the Euclidean Algorithm:
Step 1: Start with two numbers A and B.
Step 2: Replace A with B and B with A % B (the remainder when A is divided by B).
Step 3: Repeat step 2 until B becomes 0. At this point, A will hold the GCD.
Why Does It Work?
The Euclidean algorithm works because if a number divides two numbers A and B, it also divides the remainder when A is divided by B.
By repeatedly reducing the numbers this way, we are "shrinking" the problem, and the final number left when one of them becomes zero is the greatest common divisor.


// LCM 

The LCM (Least Common Multiple) of two numbers is the smallest number that is a multiple of both.
The relationship between the GCD and the LCM can be understood by the following formula:

LCM(A, B) × GCD(A, B) = A × B

class Solution {
  public:
   long long solveGCD(long long A, long long B) {
        while (B != 0) {
            A = A % B;
            swap(A, B);
        }
        return A;
    }
    
    long long solveLCM(long long A, long long B, long long gcd) {
        return (A * B) / gcd;
    }
   
    vector<long long> lcmAndGcd(long long A , long long B) {
        long long gcd = solveGCD(A, B);
        long long lcm = solveLCM(A, B, gcd);
        return {lcm, gcd};
    }
};
