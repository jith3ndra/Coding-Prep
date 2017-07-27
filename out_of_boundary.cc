


    int findPaths(int m, int n, int N, int n1, int n2) {
        vector<vector<vector<long long int >>> ref (2,vector<vector<long long int >>(m,vector<long long int>(n,0)));
        long long int res =0;
        for(int k=1;k<=N;k++){
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    ref[k%2][i][j] = (((i==0?1:ref[(k-1)%2][i-1][j]) + (j==0?1:ref[(k-1)%2][i][j-1]) + (i==m-1?1:ref[(k-1)%2][i+1][j]) + (j==n-1?1:ref[(k-1)%2][i][j+1]))%(1000000000+7));
                }
            }
        }
        return ref[N%2][n1][n2];
    }
