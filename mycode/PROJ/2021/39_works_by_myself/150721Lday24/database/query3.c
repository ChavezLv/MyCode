#include <mysql/mysql.h>
#include <stdio.h>

int main(int argc, char * argv[])
{
    if(2 != argc)
    {
        printf("args error\n");
        return -1;
    }

    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    char *host = "localhost";
    char *user = "root";
    char *passwd = "root";
    /* char *database = "lol"; */
    char *database = "net_work";
    /* char query[200] = "select * from member where name like '"; */
    /* sprintf(query, "%s%s%s", query, argv[1], "'"); */

    char *userName = "xiaobai";
    char query[200] = { 0 };//
    /* char query[200] = "select name from hero where name like '"; */
    sprintf(query, "select userID from USER_INFO where \
            userName = '%s'", userName); 
    puts(query);
    printf("%s\n", query);

    puts(query);

    conn = mysql_init(NULL);
    if(!conn)
    {
        printf("mysql init fail\n");
        return -1;
    }

    if(!mysql_real_connect(conn, host, user, passwd, database, 0, NULL, 0))
    {
        printf("Error connecting to database: %s\n", mysql_error(conn));
        return -1;
    }
    else
    {
        printf("MySQL connected...\n");
    }

    int queryRet = mysql_query(conn, query);
    if(queryRet)
    {
        printf("Error query: %s\n", mysql_error(conn));
        return -1;
    }
    else
    {
        res = mysql_store_result(conn);
        /* printf("mysql_affacted_rows: %lu\n", (unsigned long)mysql_affected_rows(conn)); */
        printf("mysql_num_rows: %lu\n", (unsigned long)mysql_num_rows(res));

        row = mysql_fetch_row(res);
        if(NULL == row)
        {
            printf("Don't query any data\n");
        }
        else
        {
            do
            {
                printf("num row: %lu\n", (unsigned long)mysql_num_rows(res));
                printf("num fileds: %lu\n", (unsigned long)mysql_num_fields(res));
                for(queryRet = 0; queryRet != (int)mysql_num_fields(res); ++queryRet)
                {
                    printf("%8s ", row[queryRet]);
                    printf("int : %d\n", atoi(row[queryRet]));
                }
                printf("\n");
            }while(NULL != (row = mysql_fetch_row(res)));
        }

        mysql_free_result(res);
    }

    mysql_close(conn);
    return 0;
}

