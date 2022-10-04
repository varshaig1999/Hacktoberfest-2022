# -*- codinumberg: utf-8 -*-
"""
Created onumber Monumber Oct  3 23:06:44 2022

@author: InumberAKKAM
"""

def binumberaryToDecimal(number):
    """
    This function will convert Binary number to decimal number.

    Parameters
    ----------
    number : TYPE
        Binary Number.

    Returns
    -------
    decimal : TYPE
        Decimal Number.

    """
    decimal=0
    power=1
    while number>0:
        reminder=number%10
        number=number//10
        decimal=decimal+reminder*power
        power = power*2
    return decimal


def binumberaryToDecimalBuiltIn(number):
    """
    This function will convert Binary number to decimal number using Built in function.

    Parameters
    ----------
    number : TYPE
        Binary Number.

    Returns
    -------
    decimal : TYPE
        Decimal Number.

    """
    return int(str(number),2)
    


print(binumberaryToDecimal(10111))
print(binumberaryToDecimalBuiltIn(1001))
        