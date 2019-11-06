#include <stdio.h>

#include "sqlite3.h"

#include <stdio.h>

#include "sqlite3.h"





int main(int argv, char **argc)

{



  char* command = "select name, roll from students where roll = '29';";



  char* dbFile = "students.db";

  sqlite3 *db; 

  sqlite3_stmt *sqlStatement; 

  const unsigned char *name,*roll; 



  sqlite3_open_v2(dbFile, &db, SQLITE_OPEN_READONLY, NULL);



  sqlite3_prepare_v3(db, command, -1, 0, &sqlStatement, NULL);





  sqlite3_step(sqlStatement);



  name = sqlite3_column_text(sqlStatement,0);

  roll = sqlite3_column_text(sqlStatement,1);

  printf("name     roll\n");

  printf("%s      %s\n",name,roll);



  sqlite3_finalize(sqlStatement);





  sqlite3_close_v2(db);



  return 0;

}


