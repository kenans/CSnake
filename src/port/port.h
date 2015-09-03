/*
 * port.h
 *
 *  Created on: 2015Äê4ÔÂ28ÈÕ
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
void PortPaintPoint(int x, int y);
void PortPaintLine(int x1, int y1, int x2, int y2);

#ifdef __cplusplus
}
#endif

#endif /* PORT_H_ */
