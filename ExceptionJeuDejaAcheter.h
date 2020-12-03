#ifndef EXCEPTIONJEUDEJAACHETER_H
#define EXCEPTIONJEUDEJAACHETER_H

#include <QException>

class ExceptionJeuDejaAchete : public QException
{
public:
    ExceptionJeuDejaAchete(QString& s);
    QString What();
private:
    QString s_;
};

ExceptionJeuDejaAchete::ExceptionJeuDejaAchete(QString& s) : s_(s) {};

QString ExceptionJeuDejaAchete::What()
{
    return s_;
}
#endif // EXCEPTIONJEUDEJAACHETER_H
