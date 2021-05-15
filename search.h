#ifndef SEARCH_H
#define SEARCH_H
#include<QVector>

class Search
{
public:

    Search();
void SearchByPrice(QVector<float> *fin);
void SearchByRatings();
void SearchByDistancefromairport();
void SearchByFacilities();
};

#endif // SEARCH_H
