#include <iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

char find_type ( char type )
{
    while(1)
    {
        if ( type =='a' || type =='b' || type =='c' )
             return type;
        else
            {
            cout<<" please enter a OR b OR c "<<endl;
            cin>>type;
            }
    }
}

char find_x_o ( char player1 )
{
    while ( 1 )
	{
		if( player1 !='x' &&  player1 !='o' && player1 !='X' &&  player1 !='O'  )
		{
			cout<<" wrong !!!!!!!!!!!!!! "<<endl;
			cout<<" please enter x OR o  "<<endl;
			cin>>player1;
        }

		if( player1 =='x' ||  player1 =='o' || player1 =='X' ||  player1 =='O' )
			break;
    }

	return player1 ;
}

void print ( char xo[5][5]  ,int c)
{
   for( int i=0 ; i<c; i++ )
   {  for( int j=0 ; j<c ; j++ )
      {
		  cout<<"\t"<<xo[i][j]<<"\t";
      }
       cout<<endl;

   }
}
void place( int x , int y , char xo[5][5] , char player1 , int c )
{

    while (1)
    {
    if( x>c-1 || y>c-1 || x<0 || y<0||xo[x][y]=='x' || xo[x][y] == 'o'  )
    {
        cout<<" please chose correct place :) "<<endl;
        cout<<" ROW : ";
        cin>>x;
        cout<<" column : ";
        cin>>y;
    }

    else
        break;

    }
   xo[x][y]=player1;
}


void check ( char xo[5][5] , char player2 , char player1 , int c  )
{
int CounterM2sp2=0,CounterM2s_p2=0,CounterColp2=0,CounterRowp2=0 ;
    	for( int i=0 ; i<c ; i++ )
  {
		for( int j=0 ,x=c-1 ; j<c  ; j++ , x-- )
		{
			if( xo[i][j]==player2 )
				CounterRowp2++;

            if ( xo[j][i]==player2 )
				CounterColp2++;

			if( xo[j][j]==player2 )
               CounterM2sp2++;

            if ( xo[j][x]==player2 )
               CounterM2s_p2++;
        }

       if(  ( CounterRowp2==c || CounterColp2==c || CounterM2sp2==c || CounterM2s_p2==c )&& player2!='x' )
	   {
		   cout<<"player( "<<player2<<" ) "<<" is wiiiiin !!!!! :) \n player( "<<player1<<" ) "<<" good luck "<<endl;
	       getch();
		   exit (0) ;
	   }

	   if(  ( CounterRowp2==c || CounterColp2==c || CounterM2sp2==c || CounterM2s_p2==c ) && player1=='o' )
        {
		   cout<<"player( "<<player2<<" ) "<<" is wiiiiin !!!!! :) \n player( "<<player1<<" ) "<<" good luck "<<endl;
	       getch();
		   exit (0) ;
	   }
         CounterRowp2=0 ;
         CounterColp2=0 ;
		 CounterM2sp2=0 ;
		 CounterM2s_p2=0 ;
  }
}
int main()
{
     int  c=0 ;
     char type ;
    cout<<" Please select the game be \n a) 3*3 \n b) 4*4 \n c) 5*5 "<<endl;
    cin>>type;

    type=find_type( type );

	if( type=='a')
		c=3;
    if(type=='b')
	    c=4;
	if(type=='c')
		c=5;
    //////////////////////////////////////////////////////////////////////////////////////////

int x,y ,a=0,b=0  ;
char player1 ,player2 ;
char xo[5][5];

for( int i=0 ; i<c ; i++ )
{
for(int j=0; j<c ; j++ )
      xo[i][j]='-';
}
    cout << " welcome in X-O :)" << endl;
    cout<< "  Please Select X or O " << endl;
    cin>>player1;

    player1= find_x_o( player1 );

    if( player1== 'x' || player1 == 'X')
       { player1='x';
         player2='o';
       }
     if ( player1== 'o' || player1 == 'O')
      { player1='o';
        player2='x';
      }

    cout<<" player 1 is "<<player1<<endl;
    cout<<" player 2 is "<<player2<<endl<<endl;

    for( int i=0  ; i<c ; i++ )
     {
         for( int j=0 ; j<c ; j++)
        {
        cout<<"\t"<<"("<<i<<" , "<<j<<")"<<"\t";
        }
        cout<<endl;
    }
    if( c%2==1 && c==3 )
      {
          a=5;
          b=4;
      }

    else if( c%2==1 && c==5 )
      {
          a=13;
          b=12;
      }
    else if( c%2==0 && c==4 )
      {
      a=8;
      b=9;
      }


 /////////////////////////////////////////////////////////////////////////////////////////////////////
	for( int j=0 ; j<a ; j++  )
 {
    cout<<" player 1 enter place ( Row , Column )  "<<endl;
    cout<<" ROW : ";
    cin>>x;
    cout<<" column : ";
    cin>>y;

    place(x,y,xo,player1,c);
    print(xo,c);
    check(xo,player1,player2,c);

     if ( j==b )
        break ;
    cout<<" player 2 enter place ( Row , Column )  "<<endl;
    cout<<" ROW : ";
    cin>>x;
    cout<<" column : ";
    cin>>y;

    place(x,y,xo,player2,c);
    print(xo,c);
	check(xo,player2,player1,c);


}
	cout<<" No one WIN !!!!! :(  ";

   getch();

}
