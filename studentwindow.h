#ifndef STUDENTWINDOW_H
#define STUDENTWINDOW_H

#include <QDialog>

namespace Ui {
class StudentWindow;
}

class StudentWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StudentWindow(QWidget *parent = nullptr, int i = 0 );
    ~StudentWindow();

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_8_clicked();

    void on_lineEdit_7_textChanged(const QString &arg1);

    void on_lineEdit_8_textChanged(const QString &arg1);

    void on_lineEdit_9_textChanged(const QString &arg1);

    void on_lineEdit_10_textChanged(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::StudentWindow *ui;
    int id;
};

#endif // STUDENTWINDOW_H
