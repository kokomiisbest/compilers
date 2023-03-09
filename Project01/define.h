#pragma once
/*
*@单词符号及种别编码
*/

/* 单词种别码*/
/*1-20为关键字种别码*/
#define _BEGIN 1     // begin
#define _CHAR 2      // char
#define _INT  3      // int
#define _FLOAT 4     // float
#define _DOUBLE 5    // double
#define _CONST 6     // const
#define _IF 7        // if
#define _THEN 8      // then
#define _ELSE 9      // else
#define _WHILE 10    // while
#define _DO 11       // do
#define _FOR 12      // for
#define _BREAK 13    // break
#define _CONTINUE 14 // continue
#define _SIZEOF 15   // sizeof
#define _VOID 16     // void
#define _RETURN 17   // return
#define _END 18      // end

/*20为标识符种别码*/
#define _ID 20   

/*30为常量种别码*/
#define _NUM 30    

/*31-40为运算符种别码*/
#define _AS 31       // =
#define _EQ 32       // ==
#define _GT 33       // >
#define _LT 34       // <
#define _GE 35       // >=
#define _LE 36       // <=
#define _ADD 37      // + 
#define _SUB 38      // - 
#define _MUL 39      // * 
#define _DIV 40      // / 

/*41-35为运算符种别码*/
#define _LP 41       // (
#define _RP 42       // )
#define _LBT 43      // [
#define _RBT 44      // ]
#define _LBS 45      // {
#define _RBS 46      // }
#define _COM 47      // ,
#define _COL 48      // :
#define _SEM 49      // ;

/*将-1置为无法识别的字符标志码*/
#define _ERROR -1       
