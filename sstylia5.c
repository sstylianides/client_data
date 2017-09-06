


//Include all necessary libraries and functions
#include <stdio.h>

//Declare and initalize a global constant
int const SIZE = 5;

//Define Accounts structure
struct Accounts
{
    int    account_number;
    char   last_name[ 30 ];
    float  balance;
};

//Run the program
int main( )
{
    //Declare all local variables and objects
    struct Accounts obj[ SIZE ];
    struct Accounts temp;
    
    printf( "Enter account number, last name, and balance." );
    printf( "Enter -999 to end input\n" );
    
    for( int i = 0; i < SIZE ; i++ )
    {
        scanf( "%i", &obj[ i ].account_number );
        if( obj[ i ].account_number == -999 ) break;
        else if( obj[ i ].account_number > 999 || obj[ i ].account_number < 0 )
        {
            i--;
            printf( "*** Invalid account number. Please enter 1 - 1000 or -999 to exit ***\n" );
        }
        
        scanf( "%s", obj[ i ].last_name );
        scanf( "%f", &obj[ i ].balance );
        if( obj[ i ].balance < 0 )
        {
            i--;
            printf( "*** Invalid balance amount. Please enter a positive value. ***\n" );
        }
    }
    
    
    for( int i = 0; i < 4; i++ )
    {
        int k = i;
        for( int j = k + 1; j > -1; j-- )
        {
            if( obj[ k ].account_number > obj[ j ].account_number )
            {
                temp = obj[ k ];
                obj[ k ] = obj[ j ];
                obj[ j ] = temp;
                k--;
            }
            else break;
        }
    }
    
    printf( "ACCOUNT\tLAST NAME\t\tBALANCE\n\n" );
    
    for( int i = 0; i < SIZE; i++ )
    {
        if( obj[ i ]. account_number == -999 ) break;
        printf( "%i   \t%s\t\t\t%.2f\n", obj[ i ].account_number, obj[ i ].last_name, obj[ i ].balance );
    }
    
    //Pause then terminate the program
    getchar( );
    return 0; 
}
