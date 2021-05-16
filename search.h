#ifndef SEARCH_H
#define SEARCH_H
#include<QVector>

class Search
{
public:

    Search();
QVector<float> SearchByPrice();
void SearchByRatings();
void SearchByDistancefromairport();
void SearchByFacilities();

private:
QVector<float> sort;
};

#endif // SEARCH_H
