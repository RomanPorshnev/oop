#include "FieldGenerators.h"
#include <iostream>
FieldGenerators::FieldGenerators()
{
}

FieldGenerators::~FieldGenerators()
{
}

void FieldGenerators::GeneratorWalls(Field &Fld)
{
    int k = 0;
    int x_rand;
    int y_rand;
    TempMatrix = Fld.GetField();
    TempMatrix[2][1].SetC('#');
    /*do
    {
        x_rand = 1 + rand() % (Fld.GetM() - 1);
        y_rand = 1 + rand() % (Fld.GetN() - 1);
        if ((x_rand != 0) || (y_rand != 0))
        {
            TempMatrix[x_rand][y_rand].SetC('#');
            k++;
        }
    } while (k < int(std::sqrt(Fld.GetM() * Fld.GetN())));
    Fld.SetMatrix(TempMatrix);
    */
    Fld.SetMatrix(TempMatrix);
    TempMatrix = Fld.GetField();
    std::cout <<"("<< TempMatrix[2][1].GetC() << ")";
}
