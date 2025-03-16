#ifndef _CSV_HPP
#define _CSV_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <list>

using namespace std;

class Csv
{
private:
    map<int, list<string>> evenements;

public:
    /**
     * @brief Construct a new Csv:: Csv object
     *
     */
    Csv();

    /**
     * @brief Destroy the Csv:: Csv object
     *
     */
    ~Csv();

    /**
     * @brief Ajoute un évènement au dictionnaire
     *
     * @param annee L'année à ajouter
     * @param description La description de l'évènement
     */
    void ajoute_evenement(int annee, const string &description);

    /**
     * @brief Affiche le dictionnaire
     *
     */
    void affiche() const;

    /**
     * @brief Lis un fichier CSV
     *
     * @param path Chemin du fichier CSV
     */
    void lire_csv(const string &nom_fichier);

    /**
     * @brief Ecriture dans un fichier CSV
     *
     * @param path Chemin du fichier CSV
     */
    void ecrire_csv(const string &nom_fichier) const;
};

#endif