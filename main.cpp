#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <map>
#include "src/Csv.hpp"

using namespace std;

void vecteurEntiers(void);
void affiche(vector<string> const &vec);
string concatene(vector<string> const &vec);
void ajoute_virgule(vector<string> &vec);
void vecteurChaineCaracteres(void);
void listes(void);
void ajoute_evenement(map<int, list<string>> &evenements, int annee, const string &intitule);
void affiche_evenements(const map<int, list<string>> &evenements);
void maps(void);
void fichierCSV(void);

int main()
{
    vecteurEntiers();
    vecteurChaineCaracteres();
    listes();
    maps();
    fichierCSV();
    return 0;
}

void vecteurEntiers(void)
{
    cout << "** Exercice 1 - Vecteur d'entiers **" << endl
         << endl;

    vector<int> vec;

    vec.resize(3);

    vec[0] = 10;
    vec[1] = 20;
    vec[2] = 30;

    cout << "Affichage avec indices : ";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << " ";
    }
    cout << endl;

    cout << "Affichage avec plage de nombres : ";
    for (int val : vec)
    {
        cout << val << " ";
    }
    cout << endl;

    cout << "Affichage avec itérateurs : ";
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    vec.push_back(40);
    cout << "Taille du vecteur après ajout : " << vec.size() << endl;

    vector<int> vec_copy1(vec);

    vector<int> vec_copy2;
    vec_copy2 = vec;

    vector<int> vec_copy3;
    vec_copy3.assign(vec.begin(), vec.end());

    cout << "Vecteur copié par assign : ";
    for (int val : vec_copy3)
    {
        cout << val << " ";
    }
    cout << endl
         << endl;
}

/**
 * @brief Affiche le contenu du vecteur passé en paramètre
 *
 * @param vec vecteur de string
 */
void affiche(vector<string> const &vec)
{
    for (const string &s : vec)
    {
        cout << s << " ";
    }
    cout << endl;
}

/**
 * @brief Concatene les valeurs du vecteur passé en paramètre dans un string
 *
 * @param vec Vecteur de string
 * @return string
 */
string concatene(vector<string> const &vec)
{
    string result;
    for (const string &s : vec)
    {
        result += s + " ";
    }
    return result;
}

/**
 * @brief Ajoute une virgule entre chaque string du vecteur
 *
 * @param vec Vecteur de string
 */
void ajoute_virgule(vector<string> &vec)
{
    for_each(vec.begin(), vec.end(), [](string &s)
             { s += ","; });
}

void vecteurChaineCaracteres(void)
{

    cout << "** Exercice 2 - Vecteur de chaines de caractères **" << endl
         << endl;

    vector<string> mots;

    mots.push_back("Bonjour");
    mots.push_back("comment");
    mots.push_back("allez");
    mots.push_back("vous");
    mots.push_back("?");

    // Affiche la taille et la capacité
    cout << "Taille : " << mots.size() << endl;       // Nombre d'éléments dans le vecteur
    cout << "Capacité : " << mots.capacity() << endl; // Espace mémoire alloué

    // Ajouter quelques éléments pour observer l'évolution de la capacité
    mots.push_back("Ca");
    mots.push_back("va");
    mots.push_back("et");
    mots.push_back("toi");
    mots.push_back("?");

    cout << "Nouvelle taille : " << mots.size() << endl;
    cout << "Nouvelle capacité : " << mots.capacity() << endl;

    // Affichage avec indices
    cout << "Affichage avec indices : ";
    for (size_t i = 0; i < mots.size(); ++i)
    {
        cout << mots[i] << " ";
    }
    cout << endl;

    // Affichage avec plage de nombres
    cout << "Affichage avec plage de nombres loop : ";
    for (const string &mot : mots)
    {
        cout << mot << " ";
    }
    cout << endl;

    // Affichage avec itérateurs
    cout << "Affichage avec itérateurs : ";
    for (auto it = mots.begin(); it != mots.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // Échanger les éléments d’indice 1 et 3
    swap(mots[1], mots[3]);
    cout << "Après échange entre mots[1] et mots[3] : ";
    affiche(mots);

    // Insérer "a tous" après le premier élément
    mots.insert(mots.begin() + 1, "a tous");
    cout << "Après insertion de ''a tous'' : ";
    affiche(mots);

    // Remplacer le point d'interrogation final par "???"
    for (string &s : mots)
    {
        if (s == "?")
        {
            s = "???";
        }
    }
    cout << "Après remplacement du ? : ";
    affiche(mots);

    // Affichage avec virgules entre chaque mot
    cout << "Affichage avec virgules : ";
    for (size_t i = 0; i < mots.size(); ++i)
    {
        cout << mots[i];
        if (i != mots.size() - 1)
            cout << ", ";
    }
    cout << endl;

    // Tri du vecteur
    sort(mots.begin(), mots.end());
    cout << "Vecteur après trie : ";
    affiche(mots);

    // Affichage
    cout << "Affichage via fonction affiche() : ";
    affiche(mots);

    // Concaténation
    string phrase = concatene(mots);
    cout << "Résultat de concatene() : " << phrase << endl;

    // Ajout de virgule
    ajoute_virgule(mots);
    cout << "Après ajoute_virgule() : ";
    affiche(mots);

    cout << endl
         << endl;
}

void listes(void)
{

    cout << "** Exercice 3 - Les Listes **" << endl
         << endl;
    // Crée la liste
    list<int> liste = {10, 20, 30, 40, 50, 60, 70, 80};

    // Init de l'itérator et se place à l'index 2
    list<int>::iterator it_1 = liste.begin();
    advance(it_1, 2);

    // Supprime la valeur d'index 2
    liste.erase(it_1);

    // Affichage de la liste
    cout << "Affichage de la liste après suppression de liste[2] : ";
    for (auto it_2 = liste.begin(); it_2 != liste.end(); ++it_2)
    {
        cout << *it_2 << " ";
    }
    cout << endl
         << endl;
}

/**
 * @brief Ajoute un évènement à un dictionnaire
 *
 * @param evenements Dictionnaire d'évènements
 * @param annee L'année de l'évènement
 * @param intitule L'intitule de l'évènement
 */
void ajoute_evenement(map<int, list<string>> &evenements, int annee, const string &intitule)
{
    // Si l'année existe déjà, on ajoute à la liste existante
    if (evenements.find(annee) != evenements.end())
    {
        evenements[annee].push_back(intitule);
    }
    else
    {
        list<string> liste;
        liste.push_back(intitule);
        evenements.insert(make_pair(annee, liste));
    }
}

/**
 * @brief Affiche le dictionnaire
 *
 * @param evenements Le dictionnaire à afficher
 */
void affiche_evenements(const map<int, list<string>> &evenements)
{
    for (const auto &pair : evenements)
    {
        cout << "Année " << pair.first << " : ";
        for (const string &event : pair.second)
        {
            cout << event << "; ";
        }
        cout << endl;
    }
}

void maps(void)
{
    cout << "** Exercice 4 - Maps **" << endl;

    map<int, list<string>> events;

    // Jeux d'essais
    ajoute_evenement(events, -753, "Fondation de Rome");
    ajoute_evenement(events, 1945, "Fondation de la république");
    ajoute_evenement(events, 1789, "Révolution française");
    ajoute_evenement(events, 1789, "Prise de la Bastille");
    ajoute_evenement(events, 64, "Incendie de Rome");
    ajoute_evenement(events, 64, "Début des persécutions contre les chrétiens");

    // Affichage des événements
    affiche_evenements(events);

    cout << endl
         << endl;
}

void fichierCSV(void)
{
    cout << "** Exercice 5 - Lecture/Ecriture de fichier CSV **" << endl;
    string newFileName = "dates_2.csv";

    Csv dict;

    dict.lire_csv("assets/dates.csv");
    dict.affiche();

    // Ajout d'événements
    dict.ajoute_evenement(1789, "Révolution française");
    dict.ajoute_evenement(1789, "Prise de la Bastille");
    dict.ajoute_evenement(2024, "Jeux Olympiques de Paris");

    cout << endl
         << "Après ajout d'éléments" << endl;

    dict.affiche();

    // Écriture dans un fichier CSV
    dict.ecrire_csv("assets/" + newFileName);
}