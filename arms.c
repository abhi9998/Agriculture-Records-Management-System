/* Processed by ecpg (10.5 (Ubuntu 10.5-0ubuntu0.18.04)) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "arms.pgc"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* exec sql begin declare section */
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
   

#line 5 "arms.pgc"
 int ca ;
 
#line 6 "arms.pgc"
 char a [ 30 ] ;
 
#line 7 "arms.pgc"
 char b [ 30 ] ;
 
#line 8 "arms.pgc"
 char crop [ 30 ] ;
 
#line 9 "arms.pgc"
 float sum ;
 
#line 10 "arms.pgc"
 int foo ;
 
#line 11 "arms.pgc"
 char dis [ 30 ] ;
 
#line 12 "arms.pgc"
 char tt [ 30 ] ;
 
#line 13 "arms.pgc"
 char f_id [ 30 ] ;
 
#line 14 "arms.pgc"
 char c_name [ 30 ] ;
 
#line 15 "arms.pgc"
 char p_name [ 30 ] ;
 
#line 16 "arms.pgc"
 char season [ 30 ] ;
 
#line 17 "arms.pgc"
 int ppk2 ;
 
#line 18 "arms.pgc"
 int temp ;
 
#line 19 "arms.pgc"
 double cost ;
 
#line 20 "arms.pgc"
 int z ;
 
#line 21 "arms.pgc"
 int y ;
 
#line 22 "arms.pgc"
 int x ;
 
#line 23 "arms.pgc"
 int w ;
 
#line 24 "arms.pgc"
 int year1 ;
 
#line 25 "arms.pgc"
 int year2 ;
 
#line 26 "arms.pgc"
 int income ;
 
#line 27 "arms.pgc"
 int coun ;
 
#line 28 "arms.pgc"
 int age ;
 
#line 29 "arms.pgc"
 char city [ 30 ] ;
 
#line 30 "arms.pgc"
 char district [ 30 ] ;
 
#line 31 "arms.pgc"
 char fin [ 30 ] ;
 
#line 32 "arms.pgc"
 char foo1 [ 30 ] ;
 
#line 33 "arms.pgc"
 char f_name [ 30 ] ;
 
#line 34 "arms.pgc"
 int c = 0 ;
/* exec sql end declare section */
#line 35 "arms.pgc"



void executeQuery1()
{
	printf("Enter the year of which you want to find production amount of all crops in all districts\n");
	scanf("%d",&foo);
	/* declare curs cursor for select * from ( ( select crop_name , harvest_year , sum ( produced_amount ) , district from ( land natural join harvest ) group by ( crop_name , district , harvest_year ) ) ) as d where harvest_year = $1  */
#line 43 "arms.pgc"


	 { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare curs cursor for select * from ( ( select crop_name , harvest_year , sum ( produced_amount ) , district from ( land natural join harvest ) group by ( crop_name , district , harvest_year ) ) ) as d where harvest_year = $1 ", 
	ECPGt_int,&(foo),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 45 "arms.pgc"

	 { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch curs", ECPGt_EOIT, 
	ECPGt_char,(crop),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(temp),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(dis),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(b),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 46 "arms.pgc"

	while ( sqlca.sqlcode == 0) 
	{
		printf("Name of crop := %s\n" , crop);
		printf("Year := %d\n" , foo);
		printf("Name of district := %s\n" , dis);
		printf("Total production amount := %s\n" , b);
		printf("\n");
		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch curs", ECPGt_EOIT, 
	ECPGt_char,(crop),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(temp),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(dis),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(b),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 54 "arms.pgc"

	}
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close curs", ECPGt_EOIT, ECPGt_EORT);}
#line 56 "arms.pgc"

}

void executeQuery2()
{
	printf("Enter the two the years which you wanna compare\n");
	scanf("%d",&year1);
	scanf("%d",&year2);
	/* declare curs1 cursor for select prod_base , prod_curr , ROUND ( ( ( prod_curr - prod_base ) / prod_base ) * 100 , 2 ) as percentage_change , y . crop_name , y . district from ( ( select * from ( select harvest_year , sum ( produced_amount ) as prod_base , district , crop_name from ( land natural join harvest ) group by ( crop_name , harvest_year , district ) ) as c where harvest_year = $1  ) as y join ( select * from ( select harvest_year , sum ( produced_amount ) as prod_curr , district , crop_name from ( land natural join harvest ) group by ( crop_name , harvest_year , district ) ) as d where harvest_year = $2  ) as z on y . crop_name = z . crop_name and y . district = z . district ) */
#line 69 "arms.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare curs1 cursor for select prod_base , prod_curr , ROUND ( ( ( prod_curr - prod_base ) / prod_base ) * 100 , 2 ) as percentage_change , y . crop_name , y . district from ( ( select * from ( select harvest_year , sum ( produced_amount ) as prod_base , district , crop_name from ( land natural join harvest ) group by ( crop_name , harvest_year , district ) ) as c where harvest_year = $1  ) as y join ( select * from ( select harvest_year , sum ( produced_amount ) as prod_curr , district , crop_name from ( land natural join harvest ) group by ( crop_name , harvest_year , district ) ) as d where harvest_year = $2  ) as z on y . crop_name = z . crop_name and y . district = z . district )", 
	ECPGt_int,&(year1),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(year2),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 70 "arms.pgc"

	
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch curs1", ECPGt_EOIT, 
	ECPGt_int,&(z),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(y),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(b),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(crop),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(a),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 72 "arms.pgc"

	while( sqlca.sqlcode == 0) 
	{
		printf("Name of crop := %s\n" , crop);
		printf("Production in base year = %d\n" , z);
		printf("Production in current year = %d\n" , y);
		printf("Percentage Change = %s\n" , b);
		printf("Name of district := %s\n" , a);
		printf("\n");
		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch curs1", ECPGt_EOIT, 
	ECPGt_int,&(z),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(y),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(b),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(crop),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(a),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 81 "arms.pgc"

	}
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close curs1", ECPGt_EOIT, ECPGt_EORT);}
#line 83 "arms.pgc"
	
}

void executeQuery3()
{
	printf("Enter id of farmer:= ");
	scanf("%s",f_id);
	printf("Enter current year:= ");
	scanf("%d",&year1);
	/* declare curs2 cursor for select z . crop_name , da . pest_name , z . season from ( ( select distinct d . farmer_name , h . crop_name , h . season from ( ( select farmer_name , survey_number from ( land natural join farmer ) where farmer_id = $1  ) as d join harvest as h on d . survey_number = h . survey_number ) where h . harvest_year = $2  ) as z join damages as da on da . crop_name = z . crop_name ) */
#line 94 "arms.pgc"


	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare curs2 cursor for select z . crop_name , da . pest_name , z . season from ( ( select distinct d . farmer_name , h . crop_name , h . season from ( ( select farmer_name , survey_number from ( land natural join farmer ) where farmer_id = $1  ) as d join harvest as h on d . survey_number = h . survey_number ) where h . harvest_year = $2  ) as z join damages as da on da . crop_name = z . crop_name )", 
	ECPGt_char,(f_id),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(year1),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 96 "arms.pgc"

	
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch curs2", ECPGt_EOIT, 
	ECPGt_char,(c_name),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(p_name),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(season),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 98 "arms.pgc"

	while( sqlca.sqlcode == 0) 
	{
		printf("Name of crop := %s\n" , c_name);
		printf("Pest name = %s\n" , p_name);
		printf("Name of season := %s\n" , season);
		printf("\n");
		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch curs2", ECPGt_EOIT, 
	ECPGt_char,(c_name),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(p_name),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(season),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 105 "arms.pgc"

	}
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close curs2", ECPGt_EOIT, ECPGt_EORT);}
#line 107 "arms.pgc"
	
}

void executeUpdate()
{
	printf("Enter farmer id:= ");
	scanf("%s",f_id);
	printf("\nEnter new income:= ");
	scanf("%d",&income);
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update farmer set total_household_income = $1  where farmer_id = $2 ", 
	ECPGt_int,&(income),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(f_id),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 116 "arms.pgc"

	{ ECPGtrans(__LINE__, NULL, "commit");}
#line 117 "arms.pgc"

	if(sqlca.sqlcode == 0)
	{
		printf("Update successful\n");
	}	
	else
	{
		/* exec sql whenever sqlerror  sqlprint ; */
#line 124 "arms.pgc"

	}
	
	
}

void executeInsert()
{
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select count ( * ) from farmer", ECPGt_EOIT, 
	ECPGt_int,&(coun),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 132 "arms.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 132 "arms.pgc"

	coun++;
	c = 0;
	while(coun)
	{
		fin[c] = ('0' + (coun % 10));
		coun = coun / 10;
		c = c + 1;
	}
	foo1[0] = 'f';
	for (int i = c - 1 ; i >= 0 ; i--)
		foo1[c - 1 - i + 1] = fin[i];
	foo1[c + 1] = '\0';
	printf("Enter name of farmer:= ");
	scanf("%s" , f_name);
	printf("Enter age:= ");
	scanf("%d",&age);
	printf("Enter household income:= ");
	scanf("%d",&income);
	printf("Enter number of earning members:= ");
	scanf("%d",&z);
	printf("Enter number of non-earning members:= ");
	scanf("%d",&y);
	printf("Enter city or vilage:= ");
	scanf("%s",city);
	printf("Enter distict:= ");
	scanf("%s",district);
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into farmer values ( $1  , $2  , $3  , $4  , $5  , $6  , $7  , $8  )", 
	ECPGt_char,(foo1),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(f_name),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(age),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(income),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(z),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(y),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(city),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(district),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 159 "arms.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 159 "arms.pgc"

	{ ECPGtrans(__LINE__, NULL, "commit");
#line 160 "arms.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 160 "arms.pgc"

	if(sqlca.sqlcode == 0)
		printf("Insert successful\n");
	else
	{
		/* exec sql whenever sqlerror  sqlprint ; */
#line 165 "arms.pgc"

	}
}

int main ()
{	
	{ ECPGconnect(__LINE__, 0, "201601061@10.100.71.21" , "201601061" , "nikesh1234" , NULL, 0); 
#line 171 "arms.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 171 "arms.pgc"

	/* exec sql whenever sqlerror  sqlprint ; */
#line 172 "arms.pgc"

	/* exec sql whenever sql_warning  sqlprint ; */
#line 173 "arms.pgc"
	
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "set search_path to arms", ECPGt_EOIT, ECPGt_EORT);
#line 174 "arms.pgc"

if (sqlca.sqlwarn[0] == 'W') sqlprint();
#line 174 "arms.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 174 "arms.pgc"

	int close=0;
	while(close == 0)
	{
		printf("Print 1 if you want to execute query and 2 if you want to execute an update and 3 if you want to insert a farmer\n");
		int cntr;
		scanf("%d",&cntr);
		if(cntr==1)
		{
			int qq;
			printf("Press\n1:To find total production amount of all crops in all districts\n2:Enter two years whose production you want to compare\n3.Probable pests present in current year in all your lands\n");
			scanf("%d",&qq);
			if(qq==1)
				executeQuery1();
			else if(qq==2)
				executeQuery2();
			else
				executeQuery3();
		}
		else if (cntr == 2)
		{
			executeUpdate();
		}
		else if (cntr == 3)
			executeInsert();
		else
			exit(0);
		printf("Enter 1 to exit the program and 0 to continue\n");
		scanf("%d",&close);
	}


	return 0;
}
