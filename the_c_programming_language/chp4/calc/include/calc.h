/******************************************************************************

  Copyright (C), 2001-2013, DCN Co., Ltd.

 ******************************************************************************
  File Name     : calc.h
  Version       : Initial Draft
  Author        : huajie.wu
  Created       : 2013/3/8
  Last Modified :
  Description   : nothing
  Function List :
  History       :
  1.Date        : 2013/3/8
    Author      : huajie.wu
    Modification: Created file

******************************************************************************/


#ifndef __CALC_H__
#define __CALC_H__


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */


/*----------------------------------------------*
 * external variables                           *
 *----------------------------------------------*/

/*----------------------------------------------*
 * external routine prototypes                  *
 *----------------------------------------------*/

/*----------------------------------------------*
 * internal routine prototypes                  *
 *----------------------------------------------*/

void push(double f);
double pop(void);
int getop(char s[]);
int getch(void);
void ungetch(int c);




 

/*----------------------------------------------*
 * project-wide global variables                *
 *----------------------------------------------*/

/*----------------------------------------------*
 * module-wide global variables                 *
 *----------------------------------------------*/

/*----------------------------------------------*
 * constants                                    *
 *----------------------------------------------*/

/*----------------------------------------------*
 * macros                                       *
 *----------------------------------------------*/

 #define NUMBER '0'

/*----------------------------------------------*
 * routines' implementations                    *
 *----------------------------------------------*/


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __CALC_H__ */

