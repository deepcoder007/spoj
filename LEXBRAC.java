import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;


public class LEXBRAC
{

    public static void main(String[] args) throws Exception
    {
	BigInteger[][] dp = new BigInteger[2][260];   // 0-> ()  , 1-> []
	
	BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	BigInteger n=new BigInteger(br.readLine());
	BigInteger k=new BigInteger(br.readLine());
	// now init the dp
	dp[0][0]=dp[1][0]=1;
	dp[0][2]=dp[1][2]=1;   // for a single bracket
	int i,j,k;   
	BigInteger tmp1;
	
	for( i=4; i<=250 ; i+=2 )    // for all the size of the array
	    {
		tmp1=new BigInteger("0");
		for( j=2;j<i ;j++ )   // for all the mid partition positions
		    {
			tmp1=tmp1.add( dp[0][j-2].multiply(dp[0][i-j]));
			tmp1=tmp1.add( dp[1][j-2].multiply(dp[1][i-j]));
			tmp1=tmp1.add( dp[0][j-2].multiply(dp[1][i-j]));
			tmp1=tmp1.add( dp[1][j-2].multiply(dp[0][i-j]));
		    }
		dp[0][i]=dp[1][i]=tmp1;
	    }
	// now go down till we find k	
			
	



	return ;
    }
}
