#include "ProxyStock.h"
#include <string>

ProxyStock::ProxyStock(Stock* stockername) {
}

int ProxyStock::getQuantite(Personnel* p1) {
    if (isAuthenticated(p1)) {
        return stock->get_quantite();
    }
    // Afficher un message d'erreur ou ne rien faire
    return -1; // Valeur par défaut en cas d'erreur
}

int ProxyStock::getLimite(Personnel* p1) {
    if (isAuthenticated(p1)) {
        return stock->get_limite();
    }
    // Afficher un message d'erreur ou ne rien faire
    return -1; // Valeur par défaut en cas d'erreur
}

int ProxyStock::getID(Personnel* p1) {
    if (isAuthenticated(p1)) {
        return stock->get_ID();
    }
    // Afficher un message d'erreur ou ne rien faire
    return -1; // Valeur par défaut en cas d'erreur
}

void ProxyStock::setQuantite(int quantite, Personnel* p1) {
    if (isAuthenticated(p1)) {
        stock->set_quantite(quantite);
    }
    // Afficher un message d'erreur ou ne rien faire
}

void ProxyStock::setLimite(int limite, Personnel* p1) {
    if (isAuthenticated(p1)) {
        stock->set_limite(limite);
    }
    // Afficher un message d'erreur ou ne rien faire
}

void ProxyStock::setID(int ID, Personnel* p1) {
    if (isAuthenticated(p1)) {
        stock->set_ID(ID);
    }
    // Afficher un message d'erreur ou ne rien faire
}

bool ProxyStock::isAuthenticated(Personnel* p1) {
    // Logique d'authentification basée sur les informations d'authentification du technicien
    // Par exemple, vérification du nom d'utilisateur et du mot de passe
    // Retourne true si l'authentification est réussie, false sinon
    // Cette logique doit être implémentée en fonction des exigences de votre application
    // Dans cet exemple, on considère que l'authentification est réussie si le nom d'utilisateur est "technicien" et le mot de passe est "motdepasse"
    return (p1 ->get_niveau() == 1);
}
