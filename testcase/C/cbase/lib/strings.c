/* system header */
#include <ctype.h>
#include <string.h>

/* local header */
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
