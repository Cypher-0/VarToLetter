#include "conversions.h"

#include <QStringList>
#include <QMap>

#include <QDebug>

namespace Conversions
{
    QMap<QString,QString> getLetterListFromVars(QString varList, const QStringList &alphabet)
    {
        auto tempList{varList.replace(" ","").split(",")};
        QMap<QString,QString> result{};

        if(tempList.size() > alphabet.size())
            return result;

        for(int i = 0; i < tempList.size();i++)
        {
            result[tempList.at(i)] = alphabet.at(i);
        }

        return result;
    }


    QString get_eq_varsToLetters(QString equation, const QMap<QString,QString> &varMap)
    {
        for(const auto &elem : varMap)
        {
            equation.replace(varMap.key(elem),elem);
        }

        return equation;
    }
    QString get_eq_lettersToVars(QString equation, const QMap<QString,QString> &varMap)
    {
        for(const auto &elem : varMap)
        {
            equation.replace(elem,varMap.key(elem));
        }

        return equation;
    }
}
