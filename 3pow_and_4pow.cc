


bool isPowerOfThree(int n) {
        if(n<=0)return false;
        //int max=3;
        //while(max*3>0){
          //  max*=3;
        //}
        int max = 1162261467;
        //cout << max<<endl;
        return max%n==0;
    }


bool isPowerOfFour(int n) {
        return n>0 && ((n & n-1) == 0) && ((n-1)%3==0);
    }
