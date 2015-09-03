/*
 * port.h
 *
 *  Created on: 2015��4��28��
 *      Author: apple
 */

#ifndef PORT_H_
#define PORT_H_

#ifdef __cplusplus
extern "C" {
#endif

void PortDelay(int ms);
int PortRand(int max);
int PortGetKey(void); // UP, DOWN, LEFT, RIGHT: 0, 1, 2, 3

#ifdef __cplusplus
}
#endif

#endif /* PORT_H_ */
