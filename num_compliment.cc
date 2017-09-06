
int findComplement(int num) {
        int res=~0;
        while(num & res) res= res<<1;
        res = ~res & ~num;
        return res;
    }
