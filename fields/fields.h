//
// Created by User on 21/02/2024.
//

#ifndef SPORTS_FIELDS_TEAM_PROJECT_FIELDS_H
#define SPORTS_FIELDS_TEAM_PROJECT_FIELDS_H

#include "stringh"
#include "reservation.h"

class fields {
private:
    std::string name;
    std::string city;
    std::string sportType;
    std::string ID_manager;
    std::string description;
    reservation* res;
    std::string* reviews;
    int reviews_counter;
    bool accessible;
    int fieldsCounter;

public:
    fields(std::string name, std::string city, std::string sportType, std::string ID_manager
           std::string description, reservation *res, std::string *reviews, bool accessible, int counter);

    const std::string &getName() const;
    const std::string &getCity() const;
    const std::string &getSportType() const;
    const std::string &ID_manager() const;
    const std::string &getDescription() const;
    reservation *getRes() const;
    std::string *getReviews() const;
    int getReviewsCounter(); const
    bool isAccessible() const;
    int getFieldsCounter() const;



    void setName(const std::string &name);
    void setCity(const std::string &city);
    void setSportType(const std::string &sportType);
    void setDescription(const std::string &description);
    void setRes(reservation *res);
    void setReviews(std::string *reviews);
    void setAccessible(bool accessible);
    void setCounter(int counter);

    void addReviews(std::string rev);


};


#endif //SPORTS_FIELDS_TEAM_PROJECT_FIELDS_H
