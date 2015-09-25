/*
 * MyPaint.cpp - Implementation of the MyPaint class
 * CSE 20212 - Spring 2009
 * 
 * The MyPaint class creates a paint object capable of capturing mouse clicks, drawing dots at the point of the mouse click,
 * then constructing a minimum spanning tree connecting the points.
 * 
 * Author: Phil MacCart 
 * 03-01-2009
 * 
 */

#ifndef MYPAINT_H_
#define MYPAINT_H_
 
//!
//! Yo: the Q_OBJECT macro tells us that this class can have
//! slots and signals.  It also tells qmake to compile this
//! class in a special way
//!

#include <QWidget>
using namespace std;

class MyPaint : public QWidget {
 	Q_OBJECT

public:
	MyPaint(QWidget *parent = 0);

protected:
	void paintEvent(QPaintEvent *e);
	void mousePressEvent(QMouseEvent *e);

private:
	int x;
	int y;
};

#endif
