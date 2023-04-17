// ProxyStock.h




#include "Stock.h"
#include <string>
#include "Personnel.h"

class ProxyStock {
public:
    ProxyStock(Stock* stockername);

    // Getters
    int getQuantite(Personnel* p1);
    int getLimite(Personnel* p1);
    int getID(Personnel* p1);

    // Setters
    void setQuantite(int quantite, Personnel* p1);
    void setLimite(int limite, Personnel* p1);
    void setID(int ID, Personnel* p1);

private:
    Stock* stock;
    std::string username;
    std::string password;
    bool isAuthenticated(Personnel* p1);



};


