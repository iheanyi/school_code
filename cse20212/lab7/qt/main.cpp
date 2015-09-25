/*
 * main.cpp - Driver for the MyPaint class
 * CSE 20212 - Spring 2009
 * 
 * Author: Phil MacCart 
 * 03-01-2009
 * 
 */
 
 
#include <QApplication>

#include "MyPaint.h"

int main(int argc, char *argv[]) {
     QApplication app(argc, argv);
     MyPaint p;
     p.show();
     return app.exec();
 }
