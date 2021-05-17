#ifndef RATING_H
#define RATING_H


class Rating
{
    float Hrate;
        float Frate;
        float Arate;
    public:
        Rating();
        float rateflight();
        float ratehotel();
        float averagerate();
};

#endif // RATING_H
