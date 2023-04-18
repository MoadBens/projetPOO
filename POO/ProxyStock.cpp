#include "ProxyStock.h"
#include <string>
#include <stdexcept>

// Définition d'une exception personnalisée pour les erreurs d'authentification
class AuthenticationError : public std::runtime_error {
public:
    AuthenticationError(const std::string& message) : std::runtime_error(message) {}
};

ProxyStock::ProxyStock(Stock* stockername) {
}

int ProxyStock::getQuantite(Personnel* p1) {
    if (isAuthenticated(p1)) {
        return stock->get_quantite();
    }
    throw AuthenticationError("Access denied: invalid credentials"); // Lever une exception en cas d'erreur d'authentification
}

int ProxyStock::getLimite(Personnel* p1) {
    if (isAuthenticated(p1)) {
        return stock->get_limite();
    }
    throw AuthenticationError("Access denied: invalid credentials"); // Lever une exception en cas d'erreur d'authentification
}

int ProxyStock::getID(Personnel* p1) {
    if (isAuthenticated(p1)) {
        return stock->get_ID();
    }
    throw AuthenticationError("Access denied: invalid credentials"); // Lever une exception en cas d'erreur d'authentification
}

void ProxyStock::setQuantite(int quantite, Personnel* p1) {
    if (isAuthenticated(p1)) {
        stock->set_quantite(quantite);
    }
    throw AuthenticationError("Access denied: invalid credentials"); // Lever une exception en cas d'erreur d'authentification
}

void ProxyStock::setLimite(int limite, Personnel* p1) {
    if (isAuthenticated(p1)) {
        stock->set_limite(limite);
    }
    throw AuthenticationError("Access denied: invalid credentials"); // Lever une exception en cas d'erreur d'authentification
}

void ProxyStock::setID(int ID, Personnel* p1) {
    if (isAuthenticated(p1)) {
        stock->set_ID(ID);
    }
    throw AuthenticationError("Access denied: invalid credentials"); // Lever une exception en cas d'erreur d'authentification
}

bool ProxyStock::isAuthenticated(Personnel* p1) {
    // Logique d'authentification basée sur les informations d'authentification du technicien
    // Par exemple, vérification du nom d'utilisateur et du mot de passe
    // Retourne true si l'authentification est réussie, false sinon
    // Cette logique doit être implémentée en fonction des exigences de votre application
    // Dans cet exemple, on considère que l'authentification est réussie si le nom d'utilisateur est "technicien" et le mot de
    return (p1->get_niveau() == 1);
}
