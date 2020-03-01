#ifndef CONVERSIONS_H
#define CONVERSIONS_H

#include <QStringList>
#include <QList>
#include <QMap>

namespace Conversions
{
    QMap<QString,QString> getLetterListFromVars(QString varList, const QStringList &alphabet);

    QString get_eq_varsToLetters(QString equation, const QMap<QString, QString> &varMap);
    QString get_eq_lettersToVars(QString equation, const QMap<QString, QString> &varMap);
}

#endif // CONVERSIONS_H
