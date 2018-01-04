#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include <QDebug>
#include<iostream>
#define PORT 10066
#define IP "127.0.0.1"
char* conn(QMessageBox * mb);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

   QMessageBox mb;

    conn(&mb);

   int ret = mb.exec();

}



char* conn(QMessageBox * mb){

      int sd;			// descriptorul de socket
      struct sockaddr_in server;	// structura folosita pentru conectare
      char* msg="Hello its me client";		// mesajul trimis
      char ret[100];
      /* cream socketul */
      if ((sd = socket (AF_INET, SOCK_STREAM, 0)) == -1)
        {
          perror ("Eroare la socket().\n");

        }

      /* umplem structura folosita pentru realizarea conexiunii cu serverul */
      /* familia socket-ului */
      server.sin_family = AF_INET;
      /* adresa IP a serverului */
      server.sin_addr.s_addr = inet_addr(IP);
      /* portul de conectare */
      server.sin_port = htons (PORT);


      /* ne conectam la server */
        if (connect (sd, (struct sockaddr *) &server,sizeof (struct sockaddr)) == -1)
          {
            perror ("[client]Eroare la connect().\n");

          }
        /* trimiterea mesajului la server */
          if (write (sd, msg, 100) <= 0)
            {
              perror ("[client]Eroare la write() spre server.\n");

            }

          if (read (sd, ret, 100) < 0)
              {
                perror ("[client]Eroare la read() de la server.\n");

              }
          QTextStream out(stdout);
          out<<QString(ret);
          close(sd);
          mb->setText(ret);
          return ret;
}
