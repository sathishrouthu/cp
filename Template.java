import java.util.*;
class Template{
    public static void solve(ArrayList<Integer> arr){
        HashMap<Integer,Integer> mp = new HashMap<Integer,Integer>();
        for(int i=0;i<arr.size();i++)
            mp.put(arr.get(i),i);
        for(int i=0;i<arr.size();i++){
            if(i < mp.get(arr.get(i)))
                System.out.print(1);
            else
                System.out.print(-1);
        }
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        ArrayList<Integer> arr = new ArrayList<Integer>();
        for(int i=0;i<n;i++){
            int t = sc.nextInt();
            arr.add(t);
        }
        solve(arr);
        sc.close();
    }
}