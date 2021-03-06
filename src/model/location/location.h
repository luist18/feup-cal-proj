#ifndef FEUP_CAL_PROJ_LOCATION_H
#define FEUP_CAL_PROJ_LOCATION_H

#include <string>
#include <float.h>

/**
 * @brief   Represents a real world location.
 *
 * @warning A coordinate isn't defined if it is equal to \e DBL_MAX (from \e float.h).
 */
class Location {
public:
    /**
     * @brief Constructs the location with all its attributes.
     *
     * @param id        the unique ID
     * @param city      the city of the location
     * @param x         the \e x coordinate
     * @param y         the \e y coordinate
     * @param latitude  the latitude
     * @param longitude the longitude
     */
    Location(long id, const std::string &city, double x, double y, double latitude = DBL_MAX,
             double longitude = DBL_MAX);

    /**
     * @brief Copy constructor
     *
     * @param location  the location to copy from
     */
    Location(const Location &location);

    /**
     * @brief The default constructor
     */
    Location();

    /**
     * @brief Calculates the euclidean distance to a given point
     *
     * @param x the x of the point
     * @param y the y of the point
     * @return  the euclidean distance
     */
    double euclideanDistanceTo(double x, double y) const;

    /**
     * @brief Gets the ID.
     *
     * @return          the ID
     */
    long getId() const;

    /**
     * @brief Gets the city's name.
     *
     * @return the city name
     */
    const std::string &getCity() const;

    /**
     * @brief Gets the \e x coordinate.
     *
     * @return the \e x coordinate
     */
    double getX() const;

    /**
     * @brief Gets the \e y coordinate.
     *
     * @return the \e y coordinate
     */
    double getY() const;

    /**
     * @brief Gets the latitude.
     *
     * @return the latitude
     */
    double getLatitude() const;

    /**
     * @brief Gets the longitude
     *
     * @return the longitude
     */
    double getLongitude() const;

    /**
     * @brief Verifies if other given location is equal to this one.
     *
     * @param rhs   the other location
     * @return      true if they are equal, false otherwise
     */
    bool operator==(const Location &rhs) const;

    /**
     * @brief Verifies if other given location is different from this one.
     *
     * @param rhs   the other location
     * @return      true if they are equal, false otherwise
     */
    bool operator!=(const Location &rhs) const;

    /**
     * @brief Calculates a hash for the location
     *
     * @return      the hash
     */
    int hash() const;

    /**
     * @brief Computes the Manhattan distance heuristic value for a location.
     *
     * @param rhs the other location
     * @return the Manhattan distance heuristic value
     */
    double manhattanHeuristic(const Location &rhs) const;

private:
    /**
     * @brief The location unique identifier.
     */
    long id;

    /**
     * @brief The string
     */
    std::string city;

    /**
     * @brief The \e x coordinate.
     */
    double x;

    /**
     * @brief The \e y coordinate.
     */
    double y;

    /**
     * @brief The latitude.
     */
    double latitude;

    /**
     * @brief The longitude.
     */
    double longitude;
};


#endif //FEUP_CAL_PROJ_LOCATION_H
