#ifndef _ACCOUNTING_H_
#define _ACCOUNTING_H_

/*
 * HYUNWOOK SHIN
 * Copyright 2015
 */

#include "test.h"
#include <string> 
#include <utility>

struct accounting {

   /* If the user wants to identify the writer of the test
    * accounting_number can be specified by this argument */
   accounting(int );
   void scan( Question&, char );
   std::vector<int> stat();

   private:

   int accounting_number;
   int total_attempts;
   int total_correct;
};

typedef struct accounting Accounting;
#endif

