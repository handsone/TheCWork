# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# define TRUE 1  


typedef struct worksmessage {
	int num ;
	char name[10] ;
	char  cardnum[17] ;
	int    month ;
	float grosspay ;
	float cost ;
	float taxes;
	float netpay;
	char  remake[10] ;
	struct worksmessage * next ;
} message , * messages ;

void reback();
void save(messages head);
void error(char *msg);
void float_sort(float * a ,float * b );
void count (messages head);
void output(message * head );
void sort (messages head   );
void str_sort(char a[] , char b[]);
void delete(messages head );
void   cover (void);
void input(messages head );
void browse(messages  );
void print(void);
void inquiry(messages head );
void inquirybyname(messages head);
void inquirybypay(messages head);
void inquirybybankcard(messages head );
void read(messages head );


