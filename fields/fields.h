//
// Created by User on 21/02/2024.
//

#ifndef SPORTS_FIELDS_TEAM_PROJECT_FIELDS_H
#define SPORTS_FIELDS_TEAM_PROJECT_FIELDS_H

#include <string>
#include "reservation.h"

class fields {
private:
    std::string name;
    std::string city;
    std::string sportType;
    std::string ownerId;
    std::string description;
    std::string reviews;
    bool accessible;
    int reservationCounter;

public:
    fields(std::string name, std::string city, std::string sportType, std::string ownerId,
           std::string description, std::string reviews, bool accessible, int counter);

    const std::string &getName() const;
    const std::string &getCity() const;
    const std::string &getSportType() const;
    const std::string &getOwnerId() const;
    const std::string &getDescription() const;
    std::string getReviews() const;
    bool isAccessible() const;
    int getReservationCounter() const;



    void setName(const std::string &name);
    void setCity(const std::string &city);
    void setSportType(const std::string &sportType);
    void setDescription(const std::string &descriptionEdit);
    void setAccessible(bool accessible);
    void setCounter(int counter);
    void setReview(std::string& rev);
    void appReview(std::string& rev);
    void fixArr(int type);


};


#endif //SPORTS_FIELDS_TEAM_PROJECT_FIELDS_H
