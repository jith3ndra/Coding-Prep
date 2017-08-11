

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int a1 = (D-B) * (C-A);
        int a2 = (H-F) * (G-E);
        int common = 0;
        
        if(C<=E || G<=A || B>=H || F>=D ){
            return a1+a2;
        }else{
            common = (max(A,E) - min(G,C)) * (max(B,F) - min(H,D));
        }
        return a1+a2-common;
    }
