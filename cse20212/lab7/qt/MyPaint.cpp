/*
 * MyPaint.cpp - Implementation of the MyPaint class
 * CSE 20212 - Spring 2009
 * 
 * The MyPaint class creates a paint object capable of capturing mouse clicks, 
 * and drawing dots at the point of the mouse click.
 * 
 * 
 * Author: Phil MacCart
 * 03-01-2009
 * 
 */


#include "MyPaint.h"
#include <QtGui>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

// Set the background to the spanning tree forest...
MyPaint::MyPaint(QWidget *parent)
 : QWidget(parent) {
     setWindowTitle(tr("MyPaint"));
     resize(512, 512);
}

// This method is called when the widget needs to be redrawn.
//
void MyPaint::paintEvent(QPaintEvent *) {

  //if (dots.size() == 0) return; 

	QPainter painter(this);  //! get a painter object to send drawing commands to
	 
	// a QPainter operates (by default) in pixel coordinates, with the origin
	// at the upper-left corner

	// Set the colors for each of the painters
	// The Pen is used to draw lines and figure outlines, while the brush is used to fill in
	// the figures
	painter.setPen(Qt::cyan);
	painter.setBrush(Qt::darkYellow);
	
	QPen pen(Qt::black, 2, Qt::SolidLine);
	pen.setStyle(Qt::DashDotDotLine);
	painter.drawLine(400, 200, 400, 200);

	QLinearGradient grad1(0, 20, 0, 110);

	grad1.setColorAt(0.1, Qt::black);
	grad1.setColorAt(0.5, Qt::yellow);
	grad1.setColorAt(0.9, Qt::black);

	painter.fillRect(20, 20, 300, 90, grad1);

	QLinearGradient grad2(0, 55, 250, 0);

	grad2.setColorAt(0.2, Qt::black);
	grad2.setColorAt(0.5, Qt::red);
	grad2.setColorAt(0.8, Qt::black);

	painter.fillRect(20, 140, 300, 100, grad2);


	/*************/
	// DRAWING CODE GOES HERE!!!
	
	painter.setPen(QColor("#d4d4d4"));

	painter.setBrush(QBrush("#c56c00"));
	painter.drawRect(10, 15, 90, 60);

	painter.setBrush(QBrush("#1ac500"));
	painter.drawRect(130, 15, 90, 60);

	painter.setBrush(QBrush("#539e47"));
	painter.drawRect(250, 15, 90, 60);

	painter.setBrush(QBrush("#004fc5"));
	painter.drawRect(10, 105, 90, 60);

	painter.setBrush(QBrush("#c50024"));
	painter.drawRect(130, 105, 90, 60);

	painter.setBrush(QBrush("#9e4757"));
	painter.drawRect(250, 105, 90, 60);

	painter.setBrush(QBrush("#5f3b00"));
	painter.drawRect(10, 195, 90, 60);

	painter.setBrush(QBrush("#4c4c4c"));
	painter.drawRect(130, 195, 90, 60);

	painter.setBrush(QBrush("#785f36"));
	painter.drawRect(250, 195, 90, 60);
	
	pen.setStyle(Qt::DashDotDotLine);
  painter.setPen(pen);
  painter.drawLine(20, 200, 250, 200);
  
  pen.setStyle(Qt::SolidLine);
  painter.drawEllipse(x, y, 30, 30);
}

// The mousePressEvent() function overrides the mousePressEvent() function of the parent QWidget
// class, and is used to capture mouse clicks (either on the button press or the button release).
void MyPaint::mousePressEvent(QMouseEvent *e) {
	/*************/
	// MOUSE PRESS CODE GOES HERE!!!
	// See QT Documenation to see the data members provided with the QMouseEvent class
	
	x=e->x();
	y=e->y();


	//  The update() function belongs to the QWidget parent class, and instructs the window
	//  that the screen needs to be redrawn.  Leave this at the end of your mousePressEvent function
	update();
}

