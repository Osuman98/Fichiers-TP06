#ifndef EXCEPTIONJEUPASDANSLALIBRAIRIE_H
#define EXCEPTIONJEUPASDANSLALIBRAIRIE_H

#include <QException>

class ExceptionJeuPasDansDansLibrairie : public QException
{
public:
    ExceptionJeuPasDansDansLibrairie(QString& s);
    QString What();
private:
    QString s_;
};

ExceptionJeuPasDansDansLibrairie::ExceptionJeuPasDansDansLibrairie(QString& s) : s_(s) {};

QString ExceptionJeuPasDansDansLibrairie::What()
{
    return s_;
}

#endif // EXCEPTIONJEUPASDANSLALIBRAIRIE_H
