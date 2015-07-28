#include "accounting.h"
#include "test.h"
#include <string>
#include <utility>

using namespace std;

accounting::accounting(int accounting_number) :total_attempts(0), total_correct(0),
                          accounting_number(accounting_number) {}

void
accounting::scan( Question& question, char ans ) {
   int correct_id = question.get_correct_id();
   if (correct_id == question.convert_ans_id(ans) ) {
      total_correct++;
   } 
   cerr << "Correct Answer: " << question.parent_test->get_description(correct_id) << "\n"; 
   total_attempts++;
}

vector<int>
accounting::stat() {
   vector<int> result;
   string s("");
   int p = 0;
   if (total_attempts > 0) 
       p = (total_correct*100)/total_attempts;
   result.push_back(total_attempts);
   result.push_back(total_correct);
   result.push_back( p);
   return result;
}
