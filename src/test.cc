#include "test.h"
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <fstream>
#include <istream>
#include "debug.h"

using namespace std;

int
question::convert_ans_id(char ans) {
   int option_number = ans - 'a';
   return item_ids[option_number];
}

question::question( struct test* t, vector<int> &item_ids, int correct_item_id ) :
   correct_item_id(correct_item_id), parent_test(t) { 
   if (DEBUG) CERR( "test.cc", "question", "item_ids.size()", item_ids.size() );
   for (int i = 0; i < item_ids.size(); ++i ) {
      if (DEBUG) cerr << item_ids[i];
      if (DEBUG) CERR( "test.cc", "question", "item_ids[i]", item_ids[i] );
      this->item_ids.push_back(item_ids[i]);
      if (DEBUG) CERR( "test.cc", "question", "item_ids success", 1 );
   }
}

std::string
question::to_str() {
   string s("");
   s += "What is the correct description of ";
   s += parent_test->get_name(correct_item_id);
   s += " ?\n"; 
   if (DEBUG) {
      for( int i = 0; i < item_ids.size(); ++i ) {
          cerr << " " << item_ids[i];
      }
   }
   for (int i = 0; i < item_ids.size(); ++i ) {
      if (DEBUG) CERR( "test.cc", "to_str", "i", i );
      if (DEBUG) CERR( "test.cc", "to_str", "item_ids[i]", item_ids[i] );
      if (DEBUG) CERR( "test.cc", "to_str", "s", s );
      s.push_back( 'A' + i );
      s += parent_test->get_description(item_ids[i]) + "\n";  
   }
   return s;
}

int 
question::get_correct_id() {
   return correct_item_id;
}

test::test( char *file ) {
   string item_str;
   ifstream fin;
   fin.open((const char*)file);
   test_generate(fin);
}

void
test::test_generate( istream &in ) {
   string    item_str;
   string    group_str;
   string    item_name;
   string    item_description;
   int       item_id = 0;
   string    item_id_str;
   vector<int>  new_group;
   
   /* Process Input Items */
   while( getline( in, item_str ) ) {
      if (item_str.size()) {
         item_id++;
         istringstream ssm( item_str );
         getline ( ssm, item_name, ':' );   
         getline ( ssm, item_description, ':' );
         if (DEBUG) CERR( "test.cc", "test", "item_name", item_name );
         items.push_back( item( item_id, item_name, item_description) );
      } else {
         break;
      }   
   } 

   /* Group the items together */
   while( getline( in, group_str ) ) {
      istringstream ssm( group_str );
      if (DEBUG) cerr << "New group" << endl;
      while( getline( ssm, item_id_str, ',' )) {
         
         if (DEBUG) CERR( "test.cc", "test", "item_id_str", item_id_str );
         new_group.push_back( atoi(item_id_str.c_str()) - 1 );
      }   
      groups.push_back(new_group);
      new_group.clear();
   }
}

struct question 
test::generate_question( int group_id, int num_options ) {
   vector<int> group = groups[group_id];
   if (num_options > group.size()) {
      num_options = group.size(); 
   } 
   random_shuffle( group.begin(), group.end() );
   group.erase( group.begin() + num_options, group.end() );
   srand(time(NULL));
   struct question q( this, group, group[rand() % num_options] ); 
   return q;
}

struct question 
test::generate_question( int num_options ) {
   srand(time(NULL));
   int group_id = rand() % groups.size();
   return generate_question( group_id, num_options );
}

string
test::get_description( int id ) {
   return items[id].item_description;
}

string
test::get_name( int id ) {
   return items[id].item_name;
}
