


    // time is dependent on idle slots
    // find out the idle slots
public:
    int leastInterval(vector<char>& tasks, int n) {
      vector<int> ary(26,0);
        for(int i=0;i<tasks.size();i++){
            ary[tasks[i]-'A']++; 
        }
        int max1=0,max_count=0;
        for(int i=0;i<ary.size();i++){
            if(ary[i]>0 && max1 <ary[i]){
             max1 =ary[i];
             max_count = 1;   
            }else if(max1==ary[i]){
                max_count++;
            }  
            
        }
        int idl_slots = (max1-1) * (n+1) ;
        int time = max((int)tasks.size(),idl_slots+ max_count);
        return time;
    }
