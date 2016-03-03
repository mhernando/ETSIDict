#ifndef _HASHMGR_HXX_
#define _HASHMGR_HXX_

#include "htypes.h"
#include "mock_file.h"

class HashMgr
{
  int             tablesize;
  struct hentry * tableptr;

public:
  HashMgr(const char * tpath);
  HashMgr(MockFile *tfile);
  ~HashMgr();

  struct hentry * lookup(const char *) const;
  int hash(const char *) const;
  struct hentry * walk_hashtable(int & col, struct hentry * hp) const;

private:
  HashMgr( const HashMgr & ); // not implemented
  HashMgr &operator=( const HashMgr & ); // not implemented
  int load_tables(const char * tpath);
  int load_tables(MockFile *mfile); //MHG mock
  int add_word(const char * word, int wl, const char * ap, int al);

};

#endif
