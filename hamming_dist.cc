int hammingDistance(int x, int y) {
        
        int res = x ^ y;
        int ctr =0;
        for(int i=0;i< 32;i++){
          if( res & (0x1 << i))  
            ctr++;
        }
        return ctr;
    }
