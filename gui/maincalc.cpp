#include "maincalc.h"
#include "./ui_maincalc.h"

MainCalc::MainCalc(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainCalc)
{
    ui->setupUi(this);
    this->setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);
    QList<QGroupBox *> allGroups = this->findChildren<QGroupBox *>();
    this->lcd = this->findChild<QLCDNumber*>("scream");
    this->mathExpLabel = this->findChild<QLabel*>("mathExpression");
    this->selectGroup(allGroups);
    this->numbers = new ExponentNumbers();
}

MainCalc::~MainCalc()
{
    delete ui;
}

void MainCalc::selectGroup(QList<QGroupBox *> allGroups)
{
    for (QList<QGroupBox *>::iterator groupIt = allGroups.begin(); groupIt != allGroups.end(); groupIt++)
    {
        QGroupBox* group = *groupIt;
        QString groupName = group->objectName();
        if(groupName == "general")
        {
            QList<QPushButton *> buttonList = group->findChildren<QPushButton *>();
            for (QList<QPushButton *>::iterator buttonsIt = buttonList.begin(); buttonsIt != buttonList.end(); buttonsIt++)
            {
                QPushButton *button = *buttonsIt;
                connect(button, &QPushButton::clicked, this, [this, button]() {
                    onPushGeneralClicked(button);
                });
            }
        }
        else
        {
            this->inputList = group->findChildren<QLineEdit *>();
            for (QList<QLineEdit *>::iterator textIt = this->inputList.begin(); textIt != this->inputList.end(); textIt++)
            {
                QLineEdit *input = *textIt;
                //Accept only double numbers
                QRegularExpression regexDouble("^-?\\d*\\.?\\d+$");
                QRegularExpressionValidator *validator = new QRegularExpressionValidator(regexDouble);
                input->setValidator(validator);
                connect(input, &QLineEdit::editingFinished, this, [this, input]() {
                    onEditingFinished(input);
                });
            }

            this->comboOperation = this->findChild<QComboBox*>("operation");
            connect(this->comboOperation, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [this](int index) {
                onCurrentIndexChanged(index);
            });
        }
        
    }
        
}

void MainCalc::onCurrentIndexChanged(int index)
{
    QString operationValue = this->comboOperation->itemText(index);
    this->operation = EXP::Operation::Other;
    if(operationValue == "Division")
    {
        this->operation = EXP::Operation::Divi;
    }
    else if(operationValue == "Multiplication")
    {
        this->operation = EXP::Operation::Multi;
    } 
}

void  MainCalc::onEditingFinished(QLineEdit *input)
{
    QString inputName = input->objectName();
    QString inputValue = input->text();
    
        if(inputName == "aText")
        {
            this->numbers->a = new double(inputValue.toDouble());
        }

        if(inputName == "xText")
        {
            this->numbers->x = new double(inputValue.toDouble());
        }

        if(inputName == "bText")
        {
            this->numbers->b = new double(inputValue.toDouble());
        }

        if(inputName == "yText")
        {
            this->numbers->y = new double(inputValue.toDouble());
        }
        
    
}

void MainCalc::onPushGeneralClicked(QPushButton *button)
{
    QString generalButtonStr = button->objectName();
    double result = 0;
    QString mathExp;
    if(generalButtonStr == "equalButton")
    {
        try
        {
            this->validationofMathExpression();
            mathExp = this->getMathExp();
            EXP::ExponentCalculator *exp = new EXP::ExponentCalculator();
            exp->setOperation(this->operation);
            result = exp->result(*this->numbers);
        }
        catch(const std::exception& e)
        {
            QString error = QString::fromStdString(e.what());
            this->displayMessage("Error",error);
        }
    }

    this->lcd->display(result);
    this->displayMathExp(mathExp);
    this->clear(); 
}

void MainCalc::clear()
{
    this->numbers->a = nullptr;
    this->numbers->x = nullptr;
    this->numbers->b = nullptr;
    this->numbers->y = nullptr;
    for (QList<QLineEdit *>::iterator textIt = this->inputList.begin(); textIt != this->inputList.end(); textIt++)
    {
        QLineEdit *input = *textIt;
        input->setText("");
    }

    this->comboOperation->setCurrentIndex(0);
}

void MainCalc::validationofMathExpression()
{
    if(this->operation == EXP::Operation::Other && this->numbers->a != nullptr && this->numbers->b != nullptr)
    {
        throw std::runtime_error("Pick up the right operation: multiplication or division");
    }

    else if(this->operation != EXP::Operation::Other && (this->numbers->b == nullptr || this->numbers->a == nullptr))
    {
        throw std::runtime_error("To choose between multiplication and division,\n\
        you need to provide values for 'a' and 'b'"
        );
    }

    else if(this->numbers->x != nullptr && this->numbers->a == nullptr)
    {
        throw std::runtime_error("You need to pick a value for 'a'");
    }

    else if(this->operation != EXP::Operation::Other && this->numbers->y != nullptr && this->numbers->b == nullptr)
    {
        throw std::runtime_error("You need to pick a value for 'b'");
    }
}

void MainCalc::displayMessage(QString type, QString msg)
{
    QMessageBox messageBox;
    messageBox.setWindowTitle(type);
    messageBox.setText(msg);
    messageBox.addButton(QMessageBox::Ok);
    QRect parentGeometry = this->geometry();
    messageBox.move(parentGeometry.center() - messageBox.rect().center());
    messageBox.exec();
}

QString MainCalc::getMathExp()
{
    std::string mathExp;
    if(this->numbers->a != nullptr)
    {
        mathExp += std::to_string(*this->numbers->a);
    }

    if(this->numbers->x != nullptr)
    {
        mathExp += "^" + (std::to_string(*this->numbers->x));
    }

    if(this->numbers->b != nullptr)
    {
        if(this->operation == EXP::Operation::Divi){
            mathExp += "/";
        }

        else if(this->operation == EXP::Operation::Multi){
            mathExp += "*";
        }

        mathExp += std::to_string(*this->numbers->b);
    }

    if(this->numbers->y != nullptr)
    {
        mathExp += "^" + (std::to_string(*this->numbers->y));
    }

    return QString::fromStdString(mathExp);
}

void MainCalc::displayMathExp(QString mathExp)
{
    this->mathExpLabel->setText(mathExp);
    this->mathExpLabel->show();

}