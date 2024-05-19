#ifndef MAINCALC_H
#define MAINCALC_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QList>
#include <QGroupBox>
#include <QLCDNumber>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QDebug>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QRegularExpressionValidator>
#include <vector>
#include <string>
#include <iostream>
#include "../expCalculator/exponentCalculator.h"
#include "../expCalculator/exponentNumbers.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainCalc;
}
QT_END_NAMESPACE

class MainCalc : public QMainWindow
{
    Q_OBJECT

public:
    MainCalc(QWidget *parent = nullptr);
    ~MainCalc();
private:
    Ui::MainCalc *ui;
    void selectGroup(QList<QGroupBox *> allGroups);
    QLCDNumber *lcd;
    QLabel *mathExpLabel;
    ExponentNumbers *numbers;
    QList<QLineEdit *> inputList;
    QComboBox *comboOperation;
    EXP::Operation operation = EXP::Operation::Other;
    void displayMathExp(QString mathExp);
    QString getMathExp();
    void clear();
    void displayMessage(QString type, QString msg);
    void validationofMathExpression();

public slots:
    void onCurrentIndexChanged(int index);
    void onEditingFinished(QLineEdit *input);
    void onPushGeneralClicked(QPushButton *button);
};
#endif // MAINCALC_H
