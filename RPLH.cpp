
#include <cstdio>
#include <cmath>

#define PI 3.14159265

using namespace std ;

int main( )
{
    int t , ta , sp , i ;
    double angle ;
    
    for( scanf("%d",&t) , i = 1 ; i <= t ; i++ )
    {
        scanf("%d%d",&ta,&sp) ;
        
        angle = asin( ( 9.806 * ta ) / ( sp * sp ) ) ;
        angle /= 2 ;
        angle *= 180.0 ;
        angle /= PI ;
        
        printf("Scenario #%d: ",i) ;
        if( angle <= 45.000000000000 )
            printf("%.2lf\n",angle) ;
        else
            printf("-1\n") ;
    }
    
    return 0 ;
}
