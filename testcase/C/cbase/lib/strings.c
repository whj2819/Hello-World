/* system header */
#include <ctype.h>
#include <string.h>
#include <stdio.h>

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


c_bool_t
__string_endswith(const char *s, char *stuffix)
{
    int offset,len;

    if (!s || !stuffix)
        return FALSE;

    len = strlen(stuffix);
    offset = strlen(s)-strlen(stuffix);

    if (offset >= 0)
        if (! strncmp(s+offset,stuffix,len) )
            return TRUE;

    return FALSE;
}


char *
__string_trim(char *s)
{
    char *p,*q;
    size_t llen,len;

    if (!s)
        return (NULL);

    llen = len = strlen(s);

    for (p=s; *p && isspace( (int)*p );p++,len--);

    if (! len) {
        *s = '\0';
    } else {
        for (q=s+llen-1; len>0  && isspace( (int)*q ); q--,len--);
        
        memmove( (void *)s, (void *)p, len );
        *(s + len) = '\0';
    }

    return s;
}
