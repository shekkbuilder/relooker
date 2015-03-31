#include "twodimension.h"

#include <iostream>
#include <iomanip>

using namespace std;

TwoDimension::TwoDimension()
{
    this->content = NULL;
    this->size = 0;
}
void TwoDimension::setContent(char * content,int size)
{
    this->content = content;
    this->size = size;
}

int *TwoDimension::getArray(int mode)
{
    int* returnValue;
    switch (mode)
    {
        case 1:
            returnValue = this->getRange();
            break;
        case 2:
            returnValue = this->getEntropy();
            break;
    }
    return returnValue;
}

int TwoDimension::getSize()
{
    return size;
}

int * TwoDimension::getRange()
{
    int value; 
    int * range = new int[this->size];
    int b;
    unsigned char c;
    for(int i=0;i<this->size;++i)
    {
        value = 0;
        b = c = this->content[i];
        //cout << c << ":" << b << endl;
        //cout << uppercase << setw(2) << setfill('0')<< hex << int(b) << endl;

        if(b != 0) // 0 = white
        {
            if(b == 255)// FF = black
                value = 1;
            else if(b == 9 || b == 10 || b == 13 || (b >= 32 && b <= 127)) // ASCII = Red
                value = 2;
            else if(b < 32) // Low Byte = Blue
                value = 3;
            else if(b > 127) // High Byte = Magenta
                value = 4;
        }
        range[i] = value;
    }
    return range;

}

int *TwoDimension::getEntropy()
{
    int * entropy = new int[this->size];
    for(int i=0;i<this->size;++i)
        entropy[i] = 3;
    return entropy;
}
