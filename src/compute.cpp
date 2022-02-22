/*
 * compute.cpp
 *
 *  Created on: 21 февр. 2022 г.
 *      Author: drews
 */
#include "compute.h"

bool rsTrigger(bool s, bool r)
{
	bool out = false;
	if (s == true && r == false)
	{
		out = true;
	}
	else if (s == false && r == true)
	{
		out = false;
	}
	return out;
}

bool delayLine(bool in)
{
	return in;
}

bool orFunc(bool lop, bool rop)
{
	bool result;
	result = lop || rop;
	return result;
}

bool andFunc(bool lop, bool rop)
{
	bool result;
	result = lop && rop;
	return result;
}
bool notFunc(bool op)
{
	return !op;
}

bool xorFunc(bool lop, bool rop)
{
	bool result;
	result = lop ^ rop;
	return result;
}

