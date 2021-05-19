#include "rating.h"

Rating::Rating()
{

}
void Rating::rateflight(int c)
{
Frate=Frate+c;
Frate=Frate/2;
}
void Rating::ratehotel(int d)
{
Hrate=Hrate+d;
Hrate=Hrate/2;
}

