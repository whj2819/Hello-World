#ifndef __util_h
#define __util_h

#ifdef __cplusplus
extern "C" {
#endif

#include "cbase/defs.h"


/*
 * stirng and parsing functioins
*/

extern char * __string_tolower(char *s);
extern char * __string_toupper(char *s);
extern char * __string_clean(char *s,char fillc);

extern c_bool_t  __string_is_numberic(const char *s);
extern c_bool_t  __string_startswith(const char *s, char *prefix);
extern c_bool_t  __string_endswith(const char *s, char *stuffix);



#ifdef __cplusplus
}
#endif /* __cplusplus*/

#endif /* end __util_h */
