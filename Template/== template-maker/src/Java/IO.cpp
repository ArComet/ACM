package mytest;
//提交评测前删除package
import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter writer = new PrintWriter(System.out);
    StringTokenizer tokenizer = null;
    void solve()throws Exception{
    	List<String> mylist1 = new ArrayList<>();
		List<String> mylist2 = new LinkedList<>();
		List<String> mylist3 = new Vector<>();
		Vector<String> vec = new Vector<>();
		Queue<String> que = new LinkedList<>();
		Stack<String> sta = new Stack<>();
		Set<String> myset = new HashSet<>();
		Set<String> myset2 = new TreeSet<>();
		Map<String, Integer> mymap = new HashMap<>();
		Map<String, Integer> mymap2 = new TreeMap<>();
    }
    void run()throws Exception{
    	try {
    		while (true) {
    			solve();
    		}
    	}catch(Exception e) {}
    	finally {
    		reader.close();
    		writer.close();
    	}
    }
    String next()throws Exception{ 
    	for(;tokenizer == null || !tokenizer.hasMoreTokens();){
    		tokenizer = new StringTokenizer(reader.readLine());
    	}
    	return tokenizer.nextToken();
    }
    int nextInt()throws Exception{
    	return Integer.parseInt(next());
    }
    double nextDouble()throws Exception{
    	return Double.parseDouble(next());
    }
    BigInteger nextBigInteger()throws Exception{
    	return new BigInteger(next());
    }
    public static void main(String args[])throws Exception{
    	(new Main()).run();
    }
}
