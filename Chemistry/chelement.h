#ifndef CHELEMENT_H
#define CHELEMENT_H

#include <QString>
#include <QDebug>
struct tuple{
    tuple(int x, int y) { this->x = x; this->y = y; }
    int x = 1, y = 1;
};

class ChElement
{
public:
    ChElement(int number, int period, int group, QString name);
    ChElement();

    tuple get_position();
    int get_number();
    QString get_name();
    QString calculate_conf();
private:
    int number, group, period;
    QString name;
    QString electr[5] = {"s", "p", "d", "e", "f"};
};

#endif // CHELEMENT_H
