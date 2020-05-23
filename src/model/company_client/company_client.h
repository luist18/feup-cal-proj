#ifndef FEUP_CAL_PROJ_COMPANY_CLIENT_H
#define FEUP_CAL_PROJ_COMPANY_CLIENT_H

#include <string>
#include <vector>
#include <list>
#include "../../util/algorithm/path.h"
#include "../../model/location/location.h"
#include "../../model/company_client/company_representative/company_representative.h"
#include "../../util/graph/cluster.h"

/**
 * @brief   Represents a company that might benefit from BosHbus services.
 */
class CompanyClient {
public:
    /**
     * @brief Constructs the company with all its attributes.
     *
     * @param name                  the company name
     * @param representative        the company_representative
     * @param headquarters          the company headquarters location
     */
    CompanyClient(std::string name, CompanyRepresentative representative, const Location &headquarters);

    /**
     * @brief Gets the UUID.
     *
     * @return          the UUID
     */
    long getUUID() const;

    /**
     * @brief Gets the company's name.
     *
     * @return          the company name
     */
    std::string getName() const;

    /**
     * @brief Gets the company_representative.
     *
     * @return          the company_representative
     */
    CompanyRepresentative getRepresentative() const;

    /**
     * @brief Gets the headquarters location.
     *
     * @return          the headquarters location
     */
    Location getHeadquarters() const;

    /**
     * @brief Gets the pickup points location vector.
     *
     * @return          the pickup points location vector
     */
    std::vector<Location> getPickupPoints() const;

    /**
     * @brief Adds a location to the pickup points vector.
     *
     * @param location              the location wanted to be added to the pickup points vector
     */
    bool addPickupPoint(const Location &location);

    /**
     * @brief Removes a location from the pickup points vector.
     *
     * @param location              the location wanted to be removed from the pickup points vector
     */
    bool removePickupPoint(const Location &location);

    /**
     * @brief Gets the number of used vehicles by the company.
     *
     * @return          the number of used vehicles by the company
     */
    int getVehicleNumber() const;

    /**
     * @brief Sets the number of used vehicles by the company.
     *
     * @param          the number of used vehicles by the company
     */
    void setVehicleNumber(int vehicleNumber);

    bool isCalculated() const;

    const pair<std::list<Path<Location>>, std::vector<Cluster>> &getRoutes() const;

    void setRoutes(const pair<std::list<Path<Location>>, std::vector<Cluster>> &pair);

    bool hasPickupPoint(const Location &location);

    bool operator==(const CompanyClient &rhs) const;

    bool operator!=(const CompanyClient &rhs) const;

private:
    static long NUMBER_OF_COMPANIES;

    /**
	 * @brief The company name.
	 */
    std::string name;

    /**
     * @brief The Company Representative.
     */
    CompanyRepresentative representative;

    /**
     * @brief The Company's headquarters location.
     */
    Location headquarters;

    /**
     * @brief The Company's pickup points vector.
     */
    std::vector<Location> pickupPoints;

    /**
     * @brief The number of vehicles used by the Company.
     */
    int vehicleNumber;

    /**
     * @brief The Company's identifier.
     */
    long uuid;

    /**
     * @brief Flag to identify if the paths have been calculated or not.
     */
    bool calculated = false;

    /**
     * @brief The routes of the company.
     */
    std::pair<std::list<Path<Location>>, std::vector<Cluster>> routes;
};


#endif //FEUP_CAL_PROJ_COMPANY_CLIENT_H