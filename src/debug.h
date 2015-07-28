#ifndef _DEBUG_H
#define _DEBUG_H

#define DEBUG 0

#define CERR( MODULE, FUNC, VAR, VAL ) std::cerr << MODULE << "(" << FUNC << "): " << VAR << " = " << VAL << std::endl;
#endif 
