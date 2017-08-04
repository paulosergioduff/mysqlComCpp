#include <windows.h>
#include <iostream>
#include <fstream>
#include <mysql/mysql.h>

using namespace std;

#define HOST "localhost"
#define USER "root"
#define PASS ""
#define DB "estoque"


MYSQL *conn;
	

int main()
{
    
	conn = mysql_init(NULL);
	
	const char *value = "varchar1, varchar2, varchar3";
    const char *table = "estoque"; // tabela
    char buf[128];
    
//    ################### conexao #####################################

	if(mysql_real_connect(conn, HOST, USER, PASS, DB, 0, NULL, 0))
	{
		cout << "conectado \n";
	
	}
	//Select all table
	//mysql_query(conn,"SELECT * FROM estoque");	
	snprintf(buf, sizeof buf, "SELECT %s from %s", value, table); // Query
    mysql_real_query(conn, buf, strlen(buf)); 
    
//    ################### conexao #####################################

//    ################### saida dos dados #####################################
	
	// pointer of result
	MYSQL_RES *result; 

	MYSQL_ROW row; 
	unsigned int i;
	

	result = mysql_store_result(conn); 
	row = mysql_fetch_row(result);
	char* myrow = row[i];

	
	while ((row = mysql_fetch_row(result)) != NULL) 
	{ 	
	for (i=0; i<mysql_num_fields(result); i++) 
		
		cout << row[i] << endl;
		
//    ################### saida dos dados #####################################		
		
	//	############### ESCREVER EM ARQUIVO DE TEXTO O RESULTADO ############################
		
		std::ofstream Hypnos_FILE;
std::string TEXTO = buf;
Hypnos_FILE.open("example.txt", std::ios::app);
if (Hypnos_FILE.is_open())
{
   std::cout << "Arquivo de texto aberto com sucesso!\n";

   unsigned int j = 0;
    while (((row = mysql_fetch_row(result)) !=NULL)) {
        cout << j << ":";
        Hypnos_FILE << j << ":";;
        j++;
        for (unsigned int i = 0; i < mysql_num_fields(result); i++) {
            cout << " " << row[i];
            Hypnos_FILE << " " << row[i];
        }
        cout << endl;
        Hypnos_FILE << endl;
    }

}
else
   std::cout << "Erro ao abrir arquivo de texto.";

Hypnos_FILE.close();				
		
	//	############### ESCREVER EM ARQUIVO DE TEXTO O RESULTADO ############################
	
	} 
	// mysql_query(conn,"SELECT varchar1, varchar2 FROM estoque;");
	return 0;
}

 





