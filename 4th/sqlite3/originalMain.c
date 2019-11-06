#include <stdio.h>
#include "sqlite3.h"


int main(int argv, char **argc)
{


  char* sql = "SELECT name, state FROM people WHERE state = ?1;";
  sqlite3 *db; 
  sqlite3_stmt *pstmt; 
  const unsigned char *name,*state; 
  char *zErrMsg = 0;
  int rc; 
  

  if (argv != 3)
  {
    printf("usage: %s db state\n",argc[0]);
    return(1);
  }


  rc = sqlite3_open_v2(argc[1], &db, SQLITE_OPEN_READONLY, NULL);
  if (rc)
  {
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    sqlite3_close_v2(db);
    return(1);
  }


  rc = sqlite3_prepare_v3(db, sql, -1, 0, &pstmt, NULL);

  if (rc)
  {
    fprintf(stderr, "Couldn't prepare sql statement: %s\n", sqlite3_errmsg(db));
    sqlite3_finalize(pstmt);
    sqlite3_close_v2(db);
    return(1);
  }


  rc = sqlite3_bind_text(pstmt, 1, argc[2], -1, NULL);
  if (rc)
  {
    fprintf(stderr, "Couldn't bind to prepared sql stmt: %s\n", sqlite3_errmsg(db));
    sqlite3_finalize(pstmt);
    sqlite3_close_v2(db);
    return(1);
  }


  while(sqlite3_step(pstmt) == SQLITE_ROW)
  {
    name = sqlite3_column_text(pstmt,0);
    state = sqlite3_column_text(pstmt,1);
    printf("name: %s state: %s\n",name,state);
  }


  sqlite3_finalize(pstmt);


  sqlite3_close_v2(db);

  return 0;
}
