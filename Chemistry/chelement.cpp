#include "chelement.h"

ChElement::ChElement(int number, int period, int group, QString name)
{
    this->number = number;
    this->group = group;
    this->period = period;
    this->name = name;
}

ChElement::ChElement()
{
    this->number = 1;
    this->group = 1;
    this->period = 1;
    this->name = "H";
}


tuple ChElement::get_position(){
    return tuple(this->period, this->group);
}
int ChElement::get_number(){
    return this->number;
}
QString ChElement::get_name(){
    return this->name;
}

QString ChElement::calculate_conf(){
    QString ans = "";
    int count = 0, sm = this->number, it = 0;
    bool flag = false;
    for(int i = 0; i < this->period; i++){
        if(i == this->period - 1)count = this->group;
        else if(i == this->period - 2)count = sm - this->group;
        else count = 2 * (i + 1) * (i + 1);
        it = 0;
        qDebug() << i << count;
        for(int j = 0; j < 5; j++){
            if(count == 0)break;
            if(count - (2 + j * 4) < 0){
                ans += QString::number(i + 1) + this->electr[j] + "^" + QString::number(count) + " ";
                sm -= count;
                count = 0;
                break;
            }
            else
            {
                ans += QString::number(i + 1) + this->electr[j] + "^" + QString::number(2 + j * 4) + " ";
                sm -= (2 + j * 4);
                count -= (2 + j * 4);
            }
        }
    }
    return ans;
}
