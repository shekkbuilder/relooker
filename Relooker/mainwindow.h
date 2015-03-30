#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "fichier.h"
#include "twodimension.h"
class QListWidgetItem;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:

    void on_verticalTabsList_itemClicked(QListWidgetItem *item);
    void on_verticalTabsList_currentRowChanged(int currentRow);
    void on_actionOpen_triggered();
    void on_actionAbout_triggered();
public slots:
    void update_hex_view();

private:
    Ui::MainWindow *ui;
    Fichier *binaire;
    TwoDimension* tdim;
};

#endif // MAINWINDOW_H
