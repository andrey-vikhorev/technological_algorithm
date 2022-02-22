/*
 * compute.h
 *
 *  Created on: 21 февр. 2022 г.
 *      Author: drews
 */

#ifndef COMPUTE_H_
#define COMPUTE_H_

bool rsTrigger(bool s, bool r);
bool delayLine(bool in);
bool orFunc(bool lop, bool rop);
bool andFunc(bool lop, bool rop);
bool notFunc(bool op);
bool xorFunc(bool lop, bool rop);

#endif /* COMPUTE_H_ */
