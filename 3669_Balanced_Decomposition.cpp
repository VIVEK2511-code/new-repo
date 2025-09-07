// Key Ideas in the Approach

// Divisor Precomputation
// Only divisors of n are considered as factors (makes sense, because other numbers cannot divide n cleanly).

// Backtracking
// Try to build factorization step by step, reducing n at each choice.

// Exact k factors
// Controlled using the k parameter (decremented each time we pick a factor).

// Optimization Goal
// At the end, among all valid factorizations, pick the one where (max - min) is minimal.
// This ensures the chosen factors are as “close” as possible to each other (balanced split).

// Example Walkthrough

// Say n = 12, k = 2.

// Divisors = {1, 12, 2, 6, 3, 4}

// Explore:

// Pick 2: next call → n=6, k=1.

// Pick 6: factors = {2, 6}, diff = 4.

// Pick 3: next call → n=4, k=1.

// Pick 4: factors = {3, 4}, diff = 1 (best).

// Pick 1: next call → n=12, k=1.

// Pick 12: factors = {1, 12}, diff = 11 (worse).

// Final answer = {3,4}.

// ✅ So the approach is:
// Generate all factorizations of n into exactly k parts → compute max-min → keep the best.
class Solution {
public:
    int mini =1e9;
    vector<int> best;

    void check(vector<int> curr ){
        sort(curr.begin(),curr.end());
        int val = (curr.back()-curr[0]);
        if(val<mini){
            mini =val;
            best = curr;
        }
      
    }
    void solve(int n,int k,int i,vector<int> curr,vector<int> &fac){

        if(k==0){
           
            if(n==1){
               check(curr);

            }
            return;
        }

        for(int j=i;j<fac.size();j++){
            if(n%fac[j]==0){
                curr.push_back(fac[j]);
                solve(n/fac[j],k-1,i,curr,fac);
                curr.pop_back();
            }
        }
    }
    vector<int> minDifference(int n, int k) {
       
        vector<int> curr;
        vector<int> fac;

        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                fac.push_back(i);
                if(i*i!=n)
                fac.push_back(n/i);
            }
        }

        solve(n,k,0,curr,fac);
        return best;
      
    }
};






