#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QTextStream>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>

extern int errno;

#define PORT 10066
#define IP "127.0.0.1"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();





    return a.exec();
}
