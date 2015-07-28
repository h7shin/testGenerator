#ifndef _ITEM_H
#define _ITEM_H

/*
 * HYUNWOOK SHIN
 * Copyright 2015
 */

#include <string>
#include <vector>

/* Item contains an identifier, name, and description 
 * The description will show up in the list of multiple
 * choice options.
 */
struct item {
   int item_id;
   std::string item_name;
   std::string item_description;
   item( int, std::string, std::string );
};

#endif 
