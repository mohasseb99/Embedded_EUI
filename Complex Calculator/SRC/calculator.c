/*
 * calculator.c
 *
 *  Created on: Sep 4, 2023
 *      Author: mohas
 */

#include "../INC/calculator.h"

long operand1;
unsigned char operation;
unsigned char st_first = 1, st_wrongSyntax = 0, st_divideZero = 0, st_isNum = 0, st_isNeg = 0;
long result = 0;

void calculator(unsigned char value){
    if(st_wrongSyntax || st_divideZero){   /* if one of these states is true that means we do not need to continue so we make return from function */
        return;
    }
    else{

    }

    static long num = 0;
    if(value == '+' || value == '-'){
        if(st_first == 1){         /* if we first pressed + --> wrong syntax, - --> make number negative */
            if(value == '-'){
                st_isNeg = 1;
                st_isNum = 0;   /* we make it not num so if user pressed - again, he will get syntax error */
                st_first = 0;
                return;
            }
            else{
                st_wrongSyntax = 1;
            }
        }
        else{}

        if(st_isNum == 0) st_wrongSyntax = 1;  /* before entering operation user should entered number, if not will get syntax error */
        else{
            if(operation == '*'){
                if(st_isNeg == 1) result -= operand1 * num;
                else result += operand1 * num;
                operation = 0;
                if(value == '-')st_isNeg = 1;
                else{
                    st_isNeg = 0;
                }
            }
            else if(operation == '/'){
                if(num == 0){
                    st_divideZero = 1;
                }
                else{
                    if(st_isNeg == 1) result -= operand1 / num;
                    else result += operand1 / num;
                    operation = 0;
                }
                if(value == '-')st_isNeg = 1;
                else{
                    st_isNeg = 0;
                }
            }
            else{
                if(value == '+') {
                    result += num;
                    st_isNeg = 0;
                }
                else {
                    if(st_isNeg == 1) result -= num;
                    else result += num;
                    st_isNeg = 1;
                }
            }
        }
        num = 0;
        st_isNum = 0;
    }
    else if(value == '*' || value == '/'){
        if(st_first == 1){     /* if we first pressed * or / --> wrong syntax */
            st_wrongSyntax = 1;
        }
        else{}

        if(st_isNum == 0){
            st_wrongSyntax = 1;
        }
        else{}

        operand1 = num;
        num = 0;
        st_isNum = 0;
        operation = value;
    }
    else if(value == '='){
        if(st_isNum == 0){  /* if before = is operation not num */
            st_wrongSyntax = 1;
        }
        else{  /* if before = is num --> if positive we add else we subtract */
            if(operation == '*'){
                if(st_isNeg == 1) result -= operand1 * num;
                else result += operand1 * num;
                operation = 0;
            }
            else if(operation == '/'){
                if(num == 0){
                    st_divideZero = 1;
                }
                else{
                    if(st_isNeg == 1) result -= operand1 / num;
                    else result += operand1 / num;
                    operation = 0;
                }
            }
            else{
                if(st_isNeg) result -= num;
                else result += num;
            }
        }
        num = 0;
    }
    else if(value >= '0' && value <= '9'){
        st_first = 0;   /* we make it as 0 so that means user does not entered operation first */
        num = (num*10) + (value - '0');
        st_isNum = 1;
    }
    else{  /* user enters . */
        st_wrongSyntax = 1;
    }
}


void clear_calculator(){
    operand1 = 0;
    operation = 0;
    st_isNeg = 0;
    st_first = 1;
    st_isNum = 0;
    st_divideZero = 0;
    st_wrongSyntax = 0;
    result = 0;
}
