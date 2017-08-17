

bool is_subseq(string A,string B){
    if(A==B)return true;
    if(A.size()>B.size()) return false;
    for(int i=0,j=0;i<B.size();i++){
        if(A[j]==B[i]){
            j++;
        }
        if(j==A.size()) return true;
    }
    return false;
}
bool isInterleaved(string A, string B, string C)
{
	if((int)C.size()!=(int)A.size()+(int)B.size()) return false;
	vector<int> res(26,0);
	for(int i=0;i<A.size();i++){
	    res[A[i]-'A']++;
	}
	for(int i=0;i<B.size();i++){
	    res[B[i]-'A']++;
	}
	for(int i=0;i<C.size();i++){
	    res[C[i]-'A']--;
	}
    for(int i=0;i<26;i++){
	    if(res[i]!=0){
	        return false;
	    }
	}
	return is_subseq(A,C) && is_subseq(B,C);
}

