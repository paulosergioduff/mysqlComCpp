#include <iostream>
#include <fstream>

#include <string.h>

#include <mysql/mysql.h>

using namespace std;

#define HOST "localhost"
#define USER "root"
#define PASS ""
#define DB "estoque"

MYSQL *conn;

int main()
{

    //    ################### conexao #####################################
    MYSQL *conn = mysql_init(NULL);
    if (!conn) {
        cout << "falha no mysql_init()" << endl;
        return 1;
    }

    conn = mysql_real_connect(conn, HOST, USER, PASS, DB, 0, NULL, 0);
    if (!conn) {
        cout << "falha no mysql_real_connect()" << endl;
        return 1;
    }

    cout << "conectado" << endl;

    const char *value = "*";
    const char *table = "banana"; // tabela
    char buf[128];

    snprintf(buf, sizeof buf, "SELECT %s from %s", value, table); // Query
    mysql_real_query(conn, buf, strlen(buf));

    //    ################### conexao #####################################

    //    ################### saida dos dados #####################################
    //    ################### saida dos dados #####################################


    //  ############### ESCREVER EM ARQUIVO DE TEXTO O RESULTADO ############################

    MYSQL_ROW row;
    MYSQL_RES *result = mysql_store_result(conn);

    std::ofstream Hypnos_FILE;
    Hypnos_FILE.open("resultado.txt", std::ios::app);
    if (!Hypnos_FILE.is_open()) {
        std::cout << "Erro ao abrir arquivo de texto.";
        return 1;
    }
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

    Hypnos_FILE.close();

    //  ############### ESCREVER EM ARQUIVO DE TEXTO O RESULTADO ############################

    mysql_close(conn);

    return 0;



}
