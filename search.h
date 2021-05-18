#ifndef SEARCH_H
#define SEARCH_H
#include<QVector>

class Search
{
public:

    Search();
QVector<float> SearchByPriceF();
QVector<float> SearchByPriceH();
QVector<float> SearchByRatingF();
QVector<float> SearchByRatingH();
QVector<float> SearchByDistancefromairport();
QString SearchByFacilities();

private:
QVector<float> sort;
};

#endif // SEARCH_H
