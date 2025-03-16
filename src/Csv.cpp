#include "Csv.hpp"

/**
 * @brief Construct a new Csv:: Csv object
 *
 */
Csv::Csv()
{
    this->evenements = map<int, list<string>>();
}

/**
 * @brief Destroy the Csv:: Csv object
 *
 */
Csv::~Csv()
{
}

/**
 * @brief Ajoute un évènement au dictionnaire
 *
 * @param annee L'année à ajouter
 * @param description La description de l'évènement
 */
void Csv::ajoute_evenement(int annee, const string &description)
{

    // Si l'année existe déjà, on ajoute à la liste existante
    if (evenements.find(annee) != evenements.end())
    {
        evenements[annee].push_back(description);
    }
    else
    {
        list<string> liste;
        liste.push_back(description);
        evenements.insert(make_pair(annee, liste));
    }
}

/**
 * @brief Affiche le dictionnaire
 *
 */
void Csv::affiche() const
{
    for (const auto &pair : this->evenements)
    {
        cout << "Année " << pair.first << " : ";
        for (const auto &event : pair.second)
        {
            cout << event << "; ";
        }
        cout << endl;
    }
}

/**
 * @brief Lis un fichier CSV
 *
 * @param path Chemin du fichier CSV
 */
void Csv::lire_csv(const string &path)
{

    ifstream fichier(path);
    if (!fichier)
    {
        cerr << "Erreur lors de l'ouverture du fichier : " << path << endl;
        return;
    }

    string ligne;
    while (getline(fichier, ligne))
    {
        istringstream iss(ligne);
        string annee_str, description;

        if (getline(iss, annee_str, ';') && getline(iss, description))
        {
            try
            {
                int annee = stoi(annee_str);
                ajoute_evenement(annee, description);
            }
            catch (const exception &e)
            {
                cerr << "Erreur de conversion pour la ligne : " << ligne << endl;
            }
        }
    }

    fichier.close();
}

/**
 * @brief Ecriture dans un fichier CSV
 *
 * @param path Chemin du fichier CSV
 */
void Csv::ecrire_csv(const string &path) const
{
    ofstream fichier(path);
    if (!fichier)
    {
        cerr << "Erreur lors de l'écriture du fichier : " << path << endl;
        return;
    }

    for (const auto &pair : this->evenements)
    {
        for (const auto &event : pair.second)
        {
            fichier << pair.first << ";" << event << "\n";
        }
    }

    fichier.close();
}
