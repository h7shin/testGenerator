#ifndef _TEST_H
#define _TEST_H

/* 
 * AUTHOR HYUNWOOK SHIN 
 * Copyright 2015 
 */

#include "item.h"
#include <vector>
#include <iostream>


/* Question data structure defines multiple choice question that
 * appear in the test 
 */
struct question {

     /* The test that owns the question */
     struct test *parent_test; 

     /* constructor */
     question(struct test *, std::vector<int>&, int);

     /* Returns the correct item id */
     int get_correct_id();

     /* Map Answer to Id */
     int convert_ans_id(char);

     /* Return question data in plaintext format */
     std::string to_str();

   private:

     /* list of items that will appear in each question in specified order */
     std::vector<int> item_ids;
     
     /* correct answer(item) */
     int correct_item_id;

};

/* Generate a test from istream and generate question
 * after creating a test, new question is generated
 * whenever generate_question() is called 
 */
struct test {
      /* generate a test from input */
      void test_generate(std::istream &);

      /* constructor */
      test(char *);
      
      /* generate a question */
      struct question generate_question( int );

      /* get description with id */
      std::string get_description( int );

      /* get name with id */
      std::string get_name( int );

   private:

      /* list of all items in the test */
      std::vector<item> items;  
      
      /* groups that contain related items */
      std::vector< std::vector<int> > groups;  
      
      struct question generate_question( int, int );
};

typedef struct question Question;
typedef struct test Test;
#endif 
