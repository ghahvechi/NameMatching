#include <stdio.h>
#include <string.h>
#include <windows.h>


char base[50] = "G:\\programing\\project\\Name Matching\\";

char countries[9][10] = {
    "AS.txt",
    "CA.txt",
    "FR.txt",
    "GE.txt",
    "GR.txt",
    "SW.txt",
    "UK.txt",
    "UR.txt",
    "US.txt"
};

int check(int j , char *A , char *buff)
{
    if (strlen(buff) == 0) return 0;
    int i;
    for( i = 0 ; i < 20 ; i++)
    {
        if( buff[ i ] == 0 || buff[ i ] == '\n')
            return 1;
        if( A[ j + i ] == 0 || A[ j + i ] == '\n')
            return 0;
        if( A[ j + i ] != buff[i] )
            return 0;
    }
}

void CHANGEtoFIRM(char *A)
{
    int i;
    char buff[20];
    int j;
    for( j = 0 ; j < 200 && A[j] != 0; j++)
    {
        for( i = 0 ; i < 9 ; i++)
        {
            FILE *country;
            char path[100] = "";
            strcat(path , base);
            strcat(path , &countries[i][0]);
            country = fopen( path , "r");
            if(country == NULL)
            {
                printf("%s\n" , path);
                printf("Cannot open the file---'\n");
                return -1;
            }
            while( fgets( buff , 19 , country ) != NULL )
            {
                if( check( j , A , buff ) )
                {
                    A[j] = 'F';
                    A[++j] = 'I';
                    A[++j] = 'R';
                    A[++j] = 'M';
                    A[++j] = '\n';
                    while (j<200) A[++j] = '\0';
                    fclose(country);
                    return ;
                }
            }
            fclose(country);
        }
    }
    return ;
    }


int main()
{
    char buff_1[200] , buff_2[200];
    FILE *f_small , *f_big ,*f_small1 , *f_big1;
    char inname_s[50],inname_b[50],inname_s1[50],inname_b1[50];
    int count;


    printf("Enter the location of the smaller file: ");
	scanf("%s", inname_s);
    f_small = fopen(inname_s, "r");
    if(f_small == NULL)
    {
        printf("Cannot open the file1\n");
        return -1;
    }

    printf("Where you want to put it ? : ");
	scanf("%s", inname_s1);
    f_small1 = fopen(inname_s1, "w");
    if(f_small1 == NULL)
    {
        printf("Cannot open the file1'\n");
        return -1;
    }

    system("cls");
    printf(" Please wait ...\n");


    while(fgets(buff_1, 200, f_small))
    {
        strupr( buff_1);
        CHANGEtoFIRM(buff_1);
        fputs( buff_1 , f_small1);
    }
    fclose(f_small);
    fclose(f_small1);


    system("cls");
    printf("Enter the location of the larger file: ");
	scanf("%s", inname_b);
    f_big = fopen( inname_b , "r" );
    if(f_big == NULL)
    {
        printf("Cannot open the file2\n");
        return -1;
    }

    printf("Where you want to put it ? : ");
	scanf("%s", inname_b1);
    f_big1 = fopen( inname_b1 , "w" );
    if(f_big1 == NULL)
    {
        printf("Cannot open the file2'\n");
        return -1;
    }




    system("cls");
    printf(" Have patience :) \n ");



    while(fgets(buff_2, 200, f_big))
    {
        strupr( buff_2);
        CHANGEtoFIRM(buff_2);
        fputs( buff_2 , f_big1);
    }
    fclose(f_big);
    fclose(f_big1);

    system("cls");
    printf("\n The run was successful");
    return 0;
}
