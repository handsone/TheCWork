# include "first.h"
int main ()
{	

	messages head ;
	int choice = TRUE  ;
	head = ( messages) malloc(sizeof(message));
	head -> next = NULL ;
	system("clear");
	while(choice)
	{
		cover();
		fscanf(stdin,"%d" , & choice);
		switch (choice){
			case 1:input(head);break;
			case 2:output(head); break;
			case 3:delete(head);break;
			case 4:inquiry(head);break;
			case 5:count(head);break;
			case 6:read(head);break;
			case 7:save(head);break;
			default:break;
		}
	}
}



/*void  input(messages head  )
{
	messages p , q ;
	int number , i  ;
	float 	water  , power   ;
	p = q = ( messages ) malloc(sizeof(message));
	head -> next = NULL ;
	puts("Please input the num of people who will input staff information ");
	scanf( "%d" , & number );
	for ( i = 0  ;i < number ; i ++)
	{
		printf("Please input the number of the  %d employee:(There are %d staff information need input )" , i + 1  , number - i - 1  );
		scanf("%d", & p -> num );
		printf("Please input the name of employee    : ");
		scanf("%s" , p -> name );
		printf("Please input the Banknumber of employee:");
		scanf("%s" , p -> cardnum  );
		printf("Please input the month :");
		scanf("%d", & p -> month);
		printf("Please input the gross salary of employee:");
		scanf("%f" , & p -> grosspay );
		printf("Please input the water consumption of employee in this month :");
		scanf("%f" , & water ) ;
		printf("Please input the power consumption of employee in this month :");
		scanf("%f" , & power );
		p -> cost = water * 2.80 + power * 0.60 ; 
		printf("Please input the remakes of the employee:");
		scanf("%s" , p -> remake );
		if ( p -> grosspay <= 1500 )
			p -> taxes = p -> grosspay * 0.03 ;
		else if ( p -> grosspay > 1500 && p -> grosspay <= 4500 )
			p -> taxes = p -> grosspay * 0.1 - 105 ;
		else if ( p -> grosspay > 4500 && p -> grosspay <= 9000 )
			p -> taxes = p -> grosspay * 0.2 - 555 ;
		else if ( p -> grosspay > 9000 && p -> grosspay <=35000 )
			p -> taxes = p -> grosspay * 0.25 - 1005 ;
		else if ( p -> grosspay > 35000 && p -> grosspay <= 55000 )
			p -> taxes = p -> grosspay * 0.3 - 2755 ;
		else if (p -> grosspay > 55000 &&  p -> grosspay <= 80000)
			p -> taxes = p -> grosspay * 0.35 - 5505 ;
		else
			p -> taxes = p -> grosspay * 0.45 - 13505 ;
		p -> netpay = p -> grosspay - p -> cost - p -> taxes ;
		if ( i == 0 )
			head ->next = p ;
		else
			q -> next =  p ;
		q = p ;
		p = ( messages ) malloc(sizeof(message));
	}
	q -> next = NULL ;
	system("clear");
}



void cover ()
{
	puts(" ————————————————————————————————————————————————————————————————————— ");
	puts("|                Welcome to staff information system !                |");
	puts("|                                                                     |");
	puts("|                1.Input staff information                            |");
	puts("|                                                                     |");
	puts("|                2.Browse staff information                           |");
	puts("|                                                                     |");
	puts("|                3.Delete staff information                           |");
	puts("|                                                                     |");
	puts("|                4.Inquiry staff information                          |");
	puts("|                                                                     |");
	puts("|                5.Count staff salary                                 |");
	puts("|                                                                     |");
	puts("|                6.Read employee information from file                |");
	puts("|                                                                     |");
	puts("|                7.Save employee information in file                  |");
	puts("|                                                                     |");
	puts("|                0. exit the system                                   |");
	puts("|                                                                     |");
	puts(" ————————————————————————————————————————————————————————————————————— ");
}



void output(message * head )
{
	char ch ; 
	messages p = head -> next ;
	system("clear");
	puts(" —————————————————————————————————————————————————————————————————————————————————————————————————— ");
	printf("|num  |name     |cardnum          |month     |grosspay  |charges   |taxes     |netpay    |remake   |\n");
	puts(  "|—————|—————————|—————————————————|——————————|——————————|——————————|——————————|——————————|————————— ");

	while ( p   != NULL )
	{
		printf("|%-5d" , p -> num );
		printf("|%-9s" , p -> name );
		printf("|%-17s" , p -> cardnum );
		printf("|%-10d" , p -> month );
		printf("|%-10.2f" , p -> grosspay );
		printf("|%-10.2f" , p -> cost );
		printf("|%-10.2f" , p -> taxes );
		printf("|%-10.2f" , p -> netpay );
		printf("|%-9s|\n" , p -> remake );
		p = p -> next;
	}
	puts(" —————————————————————————————————————————————————————————————————————————————————————————————————— ");
	reback();
	system("clear");
}



void reback()
{
	char ch ;
	ch = getchar ();
	puts(" press a to reback");
	while  (ch != EOF && ch != 'a' )
	{
		ch = getchar ();
	}
}


void delete(messages head )
{
	messages q , p ;
	char name[9] ;
	int  month , flag = 0 ;
	puts("Please entry the name of the deleted preson and the month you mant to delete. ");
	printf("The name : " ) ;
	scanf("%s" , name );
	printf("The month : ") ;
	scanf("%d" ,&month ) ;
	q = head ;
	p = head -> next ;
	while ( p != NULL )
	{
		if ( strcmp ( name , p -> name ) == 0 && month == p -> month )
		{
			q -> next = p -> next ;
			free(p);
			p = q -> next ;
			flag = 1 ;
		}
		else
		{
			p = p -> next ;
			q = q -> next ;
		}

	}
	if ( flag ==  0 ) 
		puts("Deletede fail !  dont find information! make sure input correct information");
	else
		puts("Deleted success!");
	reback();
	system("clear");
}



void sort (messages  head )
{
	messages p  , q ;
	int  temp ;
	for ( p  = head -> next ; p -> next  != NULL  ; p = p -> next  )
		for ( q = p -> next ; q != NULL ; q = q -> next  ) 	
		{
			if ( p -> netpay < q -> netpay)
			{
				temp = p -> month;
				p -> month = q -> month;
				q -> month = temp ;
				temp = p -> num ;
				p -> num = q -> num ;
				q -> num = temp ;
				float_sort(&p -> netpay , &q -> netpay);
				float_sort(&p -> grosspay ,& q -> grosspay);
				float_sort(&p -> cost , &q -> cost);
				float_sort(&p -> taxes , &q -> taxes);
				str_sort(p -> name ,q -> name);
				str_sort(p -> remake , q -> remake);
				str_sort(p -> cardnum , q -> cardnum);
			}
		}
}



void float_sort(float * a ,float * b )
{
	float temp ;
	temp = * a;
	* a = * b ;
	* b = temp ;
}



void str_sort(char a[] , char b[])
{
	char temp[50] ;
	strcpy(temp , a);
	strcpy(a , b);
	strcpy(b , temp);
}


void inquiry(messages head)
{
	int operation ;
	puts("1. inquiry by name    2. inquiry by card number  3. inquiry by netpay ");
	scanf("%d" , & operation ) ;
	switch (operation)
	{
		case 1 : inquirybyname( head ) ;break ;
		case 2 : inquirybybankcard ( head ) ; break ;
		case 3 : inquirybypay ( head ) ; break ; 
	}
}


void inquirybybankcard(messages head )
{
	char cardnum[17]  ;
	int flag = 0 ; 
	printf("Please enter the card number  you want to inquire for : ") ;
	scanf("%s",cardnum);
	printf("num  name     cardnum          month     grosspay  charges   taxes     netpay    remake   \n");
	head = head -> next ;	
	while ( head  != NULL ) 
	{
		if ( strcmp(cardnum , head  -> cardnum ) == 0 )
		{
			flag = 1 ;
			printf("%-5d" , head -> num );
			printf("%-9s" , head -> name );
			printf("%-17s" , head -> cardnum );
			printf("%-10d" , head -> month );
			printf("%-10.2f" , head -> grosspay );
			printf("%-10.2f" , head -> cost );
			printf("%-10.2f" , head -> taxes );
			printf("%-10.2f" , head -> netpay );
			printf("%-10s\n" , head -> remake );
		}
		head = head -> next ;
	}
	if ( flag == 0 ) 
		puts("Sorry! dont find the card number");
	reback();
	system("clear");
}

void inquirybyname(messages head)
{
	char name[10]  ;
	int flag = 0 ;
	head  = head -> next ;
	printf("Please enter the name you want to inquire for : ") ;
	scanf("%s",name);
	printf("num  name     cardnum          month     grosspay  charges   taxes     netpay    remake   \n");
	while ( head != NULL ) 
	{
		if ( strcmp(name , head  -> name ) == 0 )
		{
			flag = 1 ;
			printf("%-5d" , head -> num );
			printf("%-9s" , head -> name );
			printf("%-17s" , head -> cardnum );
			printf("%-10d" , head -> month );
			printf("%-10.2f" , head -> grosspay );
			printf("%-10.2f" , head -> cost );
			printf("%-10.2f" , head -> taxes );
			printf("%-10.2f" , head -> netpay );
			printf("%-10s\n" , head -> remake );
		}
		head = head -> next ;
	}
	if ( flag == 0 ) 
		puts("Inquiry failed Dont find the name");
	reback();
	system("clear");
}


void inquirybypay(messages head)
{
	float netpay;
	int flag = 0 ;
	printf("Please enter the netpay you want to inquire for : ") ;
	scanf("%f",&netpay);
	printf("num  name     cardnum          month     grosspay  charges   taxes     netpay    remake   \n");
	head = head -> next ;
	while ( head  != NULL ) 
	{
		if ((int) netpay ==(int) head -> netpay)
		{
			flag = 1 ;
			printf("%-5d" , head -> num );
			printf("%-9s" , head -> name );
			printf("%-17s" , head -> cardnum );
			printf("%-10d" , head -> month );
			printf("%-10.2f" , head -> grosspay );
			printf("%-10.2f" , head -> cost );
			printf("%-10.2f" , head -> taxes );
			printf("%-10.2f" , head -> netpay );
			printf("%-10s\n" , head -> remake );
		}
		head = head -> next ;
	}
	if ( flag == 0 )
		puts("Inquiry failed Dont find the netpay");
	reback();
	system("clear");
}

void count (messages head )
{
	char ch , name[10] ;
	int startmonth , endmonth , i = 0 ;
	float sum  = 0 ; 
	system("clear");

	puts(" please input name :");
	scanf("%s" , name  );
	puts("Please input the startmonth:") ;
	scanf("%d" , & startmonth) ;
	puts("Please input the endmonth :") ;
	scanf("%d" , & endmonth ) ;

	head = head -> next ;
	while( head  != NULL ) 
	{
		if ( strcmp ( name , head -> name ) == 0 && head -> month >= startmonth && head -> month <= endmonth )
		{
			i = 1 ;
			sum += head -> netpay ;
		}
		head = head -> next ;
	}

	if ( i == 0 ) 
		puts("Don not find information! ");
	else
		printf("%s ^s total money from %d to %d  : %.2f "  ,name , startmonth , endmonth , sum );

	reback();
	system("clear");

}


void error(char *msg)
{
	fprintf(stderr , "%s: %s\n" , msg , strerror(errno));
	exit(1);
}


void read(messages head)
{

	messages p , q ;
	FILE * fp ;
	if ( (fp = fopen("test" , "rb") ) == NULL )
		error("can^t open test ");
	q = head -> next = NULL ;
	p = (messages)malloc(sizeof(message));
	fread(p , sizeof(message) , 1 , fp );
	while (!feof(fp))
	{
		p -> next = q ;
		head -> next = p ;
		q = p ;
		p = (messages)malloc(sizeof(message));
		fread(p , sizeof(message) , 1 , fp );
	}	
	if ( head -> next != NULL ) 
	{
		sort(head);
		puts("Success read ");
	}
	else
		puts("The file is NULL ");
	reback();
	system("clear");
	fclose(fp);
}


void save(messages head)
{
	FILE * fp ; 
	messages p = head -> next ; 
	if ((fp = fopen("test" , "wb" ))== NULL )
		error("can^t open the file " )  ;
	while (   p != NULL )
	{
		fwrite( p  , sizeof( message)  , 1 ,  fp ) ;
		p = p -> next ;      	
	}
	puts("Success save!");
	reback();
	system("clear");
	fclose(fp);
}
*/
