#include <stdio.h>
#include <string.h>
#include <math.h>
#include <windows.h>


int EXACT_MACTH (char* A,char* B){
  int i;
  int j;
  for(i=0;i<100;i++) {
    if(B[i] == '\n' && A[i] == 0) return 1;
    if(B[i] == 0 && A[i] == '\n') return 1;
    if(B[i] == '\n' && A[i] == '\n') return 1;
    if(B[i] == 0 && A[i] == 0) return 1;
    if(A[i] != B[i]) {
      return 0;
    }
  }
  return 1;
}

int SEMI_MATCH_PRO(char *A , char *B)
{
    int i  , k=0 , l ,j ,temp = 0 , cA[26], cB[26] ,n = 0 ,m = 0 ,  p ;
    for( i = 0 ; i < 26 ; i++)
    {
        cA[i] = 0;
        cB[i] = 0;
    }
    for(j=0 ; j<200 ; j++)
                {
                    if(A[j] == '\n' || A[j] == 0)
                        break;
                    n++;
                }
    for(j=0 ; j<200 ; j++)
        {
                    if(A[j] == '\n' || A[j] == 0)
                        break;
                    m++;
        }
    for( p = 0 ; p < n ; p++)
    {
        if( A[p] == 0 || A[p] == '\n' )
            break;
        for(i='A' , j = 0 ; i<= 'Z' ; i++ , j++)
        {
                if(A[p] == i)
                    {
                        cA[j] += 1;

                    }
        }


    }
    for( p = 0 ; p < n ; p++)
    {
        if(B[p] == '\n' || B[p] == 0)
            break;

        for(i='A' , j = 0 ; i<= 'Z' ; i++ , j++)
        {
                if(B[p] == i)
                    cB[j] += 1 ;
        }


    }
    for(l = 0 ; l<26 ; l++)
        {

        if(abs(cA[l] - cB[l]) <= 1)      ++temp ;

        }
		if( temp == 26 )
            return 1;
        return 0;

        }




    int SEMI_MATCH(char *A , char *B)
    {
        int i , j , n = 0 , temp = 0 ;
            for(j=0 ; j<200 ; j++)
                {
                    if(A[j] == '\n' || A[j] == 0)
                        break;
                    n++;
                }
        n = (0.2)*n;
            for(i=0;i<100;i++)
                {
                    if(B[i] == '\n' && A[i] == 0) return 1;
                    if(B[i] == 0 && A[i] == '\n') return 1;
                    if(B[i] == '\n' && A[i] == '\n') return 1;
                    if(B[i] == 0 && A[i] == 0) return 1;
                    if(A[i] != B[i])
                    {
                        if( temp <= n )
                        {
                            ++ temp;
                            continue;
                        }
                    return 0;
                    }
                }
                    return 1;


    }













int main()
{
    char buff_1[200] , buff_2[200] , buff_3[200]  ;


    FILE *f_small , *f_big , *f_past , *f_ans ;


    char inname_s[50] , inname_b[50] , inname_a[50] , inname_p[50] , inname_pb[50] ;


    int count = 0;

    printf("Enter the location of the first small file: ");
	scanf("%s", inname_p);
	f_past = fopen(inname_p, "r");
    if(f_past == NULL)
    {
        printf("Cannot open the f_past\n");
        return -1;
    }





    printf("Enter the location of the small file: ");
	scanf("%s", inname_s);
    f_small = fopen(inname_s, "r");
    if(f_small == NULL)
    {
        printf("Cannot open the f_small\n");
        return -1;
    }




    printf("Enter the location of the big file: ");
	scanf("%s", inname_b);




	printf("Where you want to put the match names? :");
	scanf("%s" , inname_a);
	f_ans = fopen(inname_a, "w");
    if(f_ans == NULL)
    {
        printf("Cannot open the f_ans\n");
        return -1;
    }

    system("cls");



    while(fgets(buff_1, 200 , f_small) != NULL)
    {
        fgets( buff_3, 200 , f_past );
        f_big = fopen( inname_b , "r" );
        if(f_big == NULL)
        {
            printf("Cannot open the f_big\n");
            return -1;
        }

            while( fgets( buff_2 , 200 , f_big) != NULL)
                {

                    system("cls");
                    printf("please wait ... :)\n");
                    if( EXACT_MACTH( buff_1 , buff_2 ) )
                        {
                            ++ count ;

                            fputs( buff_3 , f_ans );
                            break ;
                        }
                    if( SEMI_MATCH( buff_1 , buff_2 ) )
                        {
                            ++ count ;
                            fputs( buff_3 , f_ans );
                            break ;
                        }
                    if( SEMI_MATCH_PRO( buff_1 , buff_2 ) )
                        {
                            ++ count ;
                            fputs( buff_3 , f_ans );
                            break ;
                        }
                }
            fclose(f_big);
  }



    fclose(f_small) ;
    fclose(f_past) ;
    fclose(f_ans) ;
    printf(" The number of the matches is : %d\n" , count );
    printf(" ---------------------------------------\n");
    printf("\n The run was successful\n\n");
    return 0;
}
