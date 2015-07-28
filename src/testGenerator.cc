
/* HYUNWOOK SHIN
 * Copyright 2015
 */

#include <iostream>
#include "item.h"
#include "test.h"
#include "accounting.h"

int main( int argc, char *argv[] ) {
   char ans;
   std::vector<int> result;
   Accounting a(0);
   
   /* Generate a test */
   Test t(argv[1]);

   while(1) {

      /* Generate questions */
      Question q = t.generate_question(5);
      std::cerr << "\n";

      /* Print the question */
      std::cerr << q.to_str();

      /* Get the answer */
      std::cin >> ans;
      std::cerr << "\n";
      if (ans == 'q') {
         /* Show the final result */
         result = a.stat();
         std::cout << "Total Attempted:" << result[0] << " ";
         std::cout << "Total Correct  :" << result[1] << " ";
         std::cout << "Percent Correct :"<< result[2] << "%\n";
         std::cerr << "Total Attempted:" << result[0] << " ";
         std::cerr << "Total Correct  :" << result[1] << " ";
         std::cerr << "Percent Correct :"<< result[2] << "%\n";
         break;
      } else if (!(ans)) {
         break;
      }

      /* Scan the answer for marking */
      a.scan(q, ans);
   }
}


