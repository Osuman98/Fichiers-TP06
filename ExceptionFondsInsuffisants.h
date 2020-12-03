#ifndef EXCEPTIONFONDSINSUFFISANTS_H
#define EXCEPTIONFONDSINSUFFISANTS_H

#include <QException>

class ExceptionFondsInsuffisant : public QException
{
public:
    ExceptionFondsInsuffisant(QString& s);
    QString What();
private:
    QString s_;
};

ExceptionFondsInsuffisant::ExceptionFondsInsuffisant(QString& s) : s_(s) {};

QString ExceptionFondsInsuffisant::What()
{
    return s_;
}



#endif // EXCEPTIONFONDSINSUFFISANTS_H
