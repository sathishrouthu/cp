package BS_On_Answer;

public class NthRoot {

	// Sample : Finding Square Root using BS
    public static int sqrtN(long N) {
		 long l=1;
		 long h=N;
		 while(l<=h){
			 long mid=(l+h)>>1;
			 if(mid<=N/mid)
			 	l = mid+1;
			 else
			 	h = mid-1;
		 }
		 return (int)h;
	}

	// below funcion gives 3 values, if b^exp == m then 1, if b^exp > m then 2, if b^exp < m then 0
	static int func(int b,int exp,int m){
        long ans=1;
        for(int i=1;i<=exp;i++){
            ans*=b;
            if(ans>m) return 2;
        }
        if(ans==m) return 1;
        return 0;
    }
    public static int NthRootM(int n, int m) {
        
        int l=0,h=m;
        while(l<=h){
            int mid  = l+(h-l)/2;
            int midN = func(mid,n,m);
            if(midN==1) return mid;
            else if(midN==2) 
                h=mid-1;
            else 
                l=mid+1;
        }
        return -1;
    }
}
