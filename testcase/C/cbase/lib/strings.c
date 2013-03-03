/* system header */
#include <ctype.h>
#include <string.h>

/* local header */
//#include "cbase/defs.h"
#include "cbase/util.h"


char *
__string_tolower(char *s)
{
    char *p;

    if (!s)
        return (NULL);

    for (p=s; *p; p++)
        if( isupper((int)(*p)) )
            *p = (char)tolower((int)*p);

    return (s);
}

char *
__string_toupper(char *s)
{
    char *p;

    if (!s)
        return (NULL);

    for (p=s; *p; p++)
        if( islower((int)(*p)) )
            *p = (char)toupper((int)*p);

    return (s);
}

char *
__string_clean(char *s,char fillc)
{
    char *p;

    if (!s)
        return (NULL);

    for (p=s; *p; p++)
        if( !isprint((int)*p) && !isspace((int)*p) )
            *p = fillc;

    return (s);
}


c_bool_t
__string_is_numberic(const char *s)
{
    char *p;

    if (! *s)
        return (FALSE);

    for (p=(char *)s; *p; p++)
        if (! isdigit((int)*p))
            return FALSE;

    return TRUE;
}

c_bool_t
__string_startswith(const char *s, char *prefix)
{
    int len;

    if (!s || !prefix)
        return FALSE;

    len = strlen(prefix);

    return (! strncmp(s,prefix,len) );
}
