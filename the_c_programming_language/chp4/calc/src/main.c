/******************************************************************************

  Copyright (C), 2001-2013, DCN Co., Ltd.

 ******************************************************************************
  File Name     : main.c
  Version       : Initial Draft
  Author        : huajie.wu
  Created       : 2013/3/8
  Last Modified :
  Description   : ºÚµ•º∆À„≥Ã–Ú
  Function List :
              main
  History       :
  1.Date        : 2013/3/8
    Author      : huajie.wu
    Modification: Created file

******************************************************************************/

 #include <stdio.h>
 #include <stdlib.h>
 #include "calc.h"


/*----------------------------------------------*
 * external variables                           *
 *----------------------------------------------*/

/*----------------------------------------------*
 * external routine prototypes                  *
 *----------------------------------------------*/

/*----------------------------------------------*
 * internal routine prototypes                  *
 *----------------------------------------------*/

/*----------------------------------------------*
 * project-wide global variables                *
 *----------------------------------------------*/

/*----------------------------------------------*
 * module-wide global variables                 *
 *----------------------------------------------*/

/*----------------------------------------------*
 * constants                                    *
 *----------------------------------------------*/

 #define MAXOP 100

/*----------------------------------------------*
 * macros                                       *
 *----------------------------------------------*/

/*----------------------------------------------*
 * routines' implementations                    *
 *----------------------------------------------*/





int
main(int argc, char *argv[])
{

	int type;
	char s[MAXOP];
	double op2;

    while ( (type = getop(s)) != EOF ) {
        switch ( type ) {
        
        case NUMBER :
			push(atof(s));
            break;
        case '+' :
			push(pop() + pop());
            break;
        case '*' :
			push(pop() + pop());
            break;
        case '-' :
			op2 = pop();
			push(pop() - op2);
            break;
        case '/' :
			op2 = pop();
			push(pop() / op2);
            break;
        case '\n' :
			printf("\t%.8g\n",pop());
            break;
        default:
			printf("error:unknow command %s \n",s);
            break;
        }
    }
	
    

}

