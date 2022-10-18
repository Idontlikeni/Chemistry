#include "Mtable.h"

Mtable::Mtable()
{
    int pl = 0;
    this->elements[1] = ChElement(1, 1, 1, "H");
    this->elements[2] = ChElement(2, 2, 8, "He");
    for(int i = 3; i <= 18; i++){
        this->elements[i] = ChElement(i, (i - 3) / 8 + 2, (i - 3) % 8 + 1, this->elementSymbol[i - 1]);
    }

    for(int i = 0; i < 3; i++){
        for(int j = 19 + i * 18; j <= 19 + i * 18 + 7; j++){
            this->elements[j + pl] = ChElement(j + pl, i + 4, (j - 19 - i * 18) % 8 + 1, this->elementSymbol[j - 1 + pl]);
            if(j == 57)pl = 14;
        }
        this->elements[27 + i * 18 + pl] = ChElement(27 + i * 18 + pl, i + 4, 8, this->elementSymbol[27 + i * 18 - 1 + pl]);
        this->elements[28 + i * 18 + pl] = ChElement(28 + i * 18 + pl, i + 4, 8, this->elementSymbol[28 + i * 18 - 1 + pl]);

        for(int j = 29 + i * 18; j <= 29 + i * 18 + 7; j++){
            this->elements[j + pl] = ChElement(j + pl, i + 4, (j - 29 - i * 18) % 8 + 1, this->elementSymbol[j - 1 + pl]);
        }
    }
    for(int i = 0; i < 8; i++){
        this->elements[86 + i] = ChElement(87 + i + pl, 7, i, this->elementSymbol[85 + i]);
    }

//    for(int i = 0; i < 110; i++){
//        qDebug() << i << this->elements[i].get_name() << this->elements[i].get_position().x << this->elements[i].get_position().y << this->elements[i].get_number();
//    }
}
